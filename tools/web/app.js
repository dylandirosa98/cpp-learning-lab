'use strict';

const $ = (selector) => document.querySelector(selector);
const state = {
  lessons: [],
  steps: [],
  step: null,
  lesson: null,
  token: '',
  drafts: new Map(),
  pendingSaves: 0,
  leftView: 'learncpp',
  quizIndex: 0,
  quizAnswers: new Map(),
  showExplanation: false,
  showSolution: false,
  request: 0,
  running: null,
  results: new Map(),
  loadedUrl: '',
};

let editor;
let editorLessonId = null;
let saveQueue = Promise.resolve();
const escapeHTML = (text) =>
  String(text).replace(/[&<>"']/g, (char) => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;', "'": '&#39;' }[char]));

async function api(path, options = {}) {
  const response = await fetch(path, { cache: 'no-store', ...options });
  const body = await response.json();
  if (!response.ok) throw new Error(body.error || `Request failed (${response.status})`);
  return body;
}

function showError(message = '') {
  $('#app-error').textContent = message;
  $('#app-error').hidden = !message;
}

function inline(text) {
  return escapeHTML(text)
    .replace(/`([^`]+)`/g, '<code>$1</code>')
    .replace(/\*\*([^*]+)\*\*/g, '<strong>$1</strong>')
    .replace(/\[([^\]]+)\]\((https:\/\/[^\s)]+)\)/g, '<a href="$2" target="_blank" rel="noopener noreferrer">$1 ↗</a>');
}

function markdown(text) {
  let html = '', paragraph = [], list = null, code = null;
  const flush = () => { if (paragraph.length) html += `<p>${inline(paragraph.join(' '))}</p>`; paragraph = []; };
  const closeList = () => { if (list) html += `</${list}>`; list = null; };
  for (const line of text.split('\n')) {
    if (line.startsWith('```')) {
      flush(); closeList();
      if (code === null) code = [];
      else { html += `<pre><code>${escapeHTML(code.join('\n'))}</code></pre>`; code = null; }
      continue;
    }
    if (code !== null) { code.push(line); continue; }
    if (!line.trim()) { flush(); closeList(); continue; }
    const heading = line.match(/^(#{1,3})\s+(.+)$/);
    if (heading) { flush(); closeList(); const level = Math.min(heading[1].length + 1, 4); html += `<h${level}>${inline(heading[2])}</h${level}>`; continue; }
    const bullet = line.match(/^([-*]|\d+\.)\s+(.+)$/);
    if (bullet) {
      flush(); const kind = bullet[1] === '-' || bullet[1] === '*' ? 'ul' : 'ol';
      if (list !== kind) { closeList(); list = kind; html += `<${kind}>`; }
      html += `<li>${inline(bullet[2])}</li>`; continue;
    }
    closeList(); paragraph.push(line);
  }
  flush(); closeList();
  if (code !== null) html += `<pre><code>${escapeHTML(code.join('\n'))}</code></pre>`;
  return html;
}

function highlight(source) {
  const tokens = /(\/\/[^\n]*|\/\*[\s\S]*?\*\/|"(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*'|\b(?:bool|int|double|void|const|constexpr|return|if|else|while|for|true|false|static_assert|auto|namespace|include)\b|\b\d+(?:\.\d+)?\b)/g;
  let html = '', end = 0;
  for (const match of source.matchAll(tokens)) {
    html += escapeHTML(source.slice(end, match.index));
    const token = match[0];
    const kind = token.startsWith('//') || token.startsWith('/*') ? 'comment' : /^["']/.test(token) ? 'string' : /^\d/.test(token) ? 'number' : 'keyword';
    html += `<span class="syntax-${kind}">${escapeHTML(token)}</span>`;
    end = match.index + token.length;
  }
  return html + escapeHTML(source.slice(end));
}

function parseRouteHash(raw) {
  const clean = raw.replace(/^#/, '').trim();
  if (!clean) return null;
  if (state.steps.some((s) => s.id === clean)) return clean;
  // Keep bookmarks from the earlier fixed quiz/challenge edition working.
  if (clean.endsWith('-quiz')) {
    const firstCheck = state.steps.find((s) => s.lessonId === clean.slice(0, -5) && ['quiz', 'predict', 'debug'].includes(s.kind));
    if (firstCheck) return firstCheck.id;
  }
  // A topic link now starts its sequence, not its final assignment.
  if (state.lessons.some((l) => l.id === clean)) return state.steps.find((s) => s.lessonId === clean)?.id;
  return null;
}

function drawNavigation() {
  const completedLessons = new Set(state.lessons.filter((l) => l.completed).map((l) => l.id));
  $('#progress-label').textContent = `${completedLessons.size} / ${state.lessons.length}`;
  $('#progress').max = state.lessons.length;
  $('#progress').value = completedLessons.size;

  $('#navigation').innerHTML = state.steps.map((step, idx) => {
    const active = state.step?.id === step.id;
    const done = completedLessons.has(step.lessonId);
    const quizClass = step.kind === 'quiz' ? 'quiz-dot' : '';
    return `<a href="#${step.id}" class="step-dot ${quizClass} kind-${step.kind} ${active ? 'selected' : ''} ${done ? 'completed' : ''}" aria-label="${escapeHTML(`${step.lessonId}: ${step.title} (${step.kind})`)}" title="${escapeHTML(`${step.lessonId}: ${step.title} (${step.kind})`)}" ${active ? 'aria-current="page"' : ''}>${idx + 1}</a>`;
  }).join('');

  $('#step-select').innerHTML = state.steps.map((step, idx) => {
    const selected = state.step?.id === step.id ? 'selected' : '';
    return `<option value="${step.id}" ${selected}>${idx + 1}. ${escapeHTML(step.shortTitle)} [${step.kind}]</option>`;
  }).join('');
}

function drawLeftPane() {
  const lesson = state.lesson;
  if (!lesson) return;

  const isLearncpp = state.leftView === 'learncpp';
  $('#tab-learncpp').classList.toggle('active', isLearncpp);
  $('#tab-learncpp').setAttribute('aria-selected', String(isLearncpp));
  $('#tab-assignment').classList.toggle('active', !isLearncpp);
  $('#tab-assignment').setAttribute('aria-selected', String(!isLearncpp));

  $('#learncpp-view').hidden = !isLearncpp;
  $('#assignment-view').hidden = isLearncpp;

  if (state.loadedUrl !== lesson.url) {
    state.loadedUrl = lesson.url;
    $('#learncpp-frame').src = lesson.url;
  }

  const step = state.step;
  $('#reading').innerHTML = `<h2>${escapeHTML(step.title)}</h2><p><strong>Goal:</strong> ${inline(step.objective)}</p>${markdown(step.explanation)}
    ${step.kind === 'code' ? `<h3>Assignment contract</h3><p>${inline(lesson.challenge)}</p><div class="examples">${lesson.examples.map((ex) => `<div><span>→</span><code>${escapeHTML(ex)}</code></div>`).join('')}</div>` : ''}
    <details><summary>Full original companion notes for ${escapeHTML(lesson.id)}</summary>${markdown(lesson.notes)}</details>`;
}

function currentQuestions() {
  return state.step?.questions || [];
}

function nextStep() {
  const index = state.steps.findIndex((step) => step.id === state.step?.id);
  const next = state.steps[index + 1];
  if (next) location.hash = next.id;
}

function drawQuizPane() {
  const lesson = state.lesson;
  if (!lesson) return;
  const quizzes = currentQuestions();
  if (!quizzes.length) return;
  if (state.quizIndex >= quizzes.length) state.quizIndex = 0;

  const current = quizzes[state.quizIndex];
  const key = `${state.step.id}:${state.quizIndex}`;
  const chosen = state.quizAnswers.get(key);

  $('#quiz-dots').innerHTML = quizzes.map((_, idx) => {
    const correct = state.quizAnswers.get(`${state.step.id}:${idx}`) === quizzes[idx].answer;
    return `<button type="button" class="quiz-q-btn ${idx === state.quizIndex ? 'active' : ''} ${correct ? 'answered' : ''}" data-qidx="${idx}" aria-label="Question ${idx + 1}">${idx + 1}</button>`;
  }).join('');

  $('#quiz-dots').querySelectorAll('[data-qidx]').forEach((btn) => {
    btn.addEventListener('click', () => {
      state.quizIndex = Number(btn.dataset.qidx);
      state.showExplanation = false;
      drawQuizPane();
    });
  });

  $('#quiz-prev').disabled = state.quizIndex === 0;
  $('#quiz-next').disabled = state.quizIndex === quizzes.length - 1;
  $('#quiz-counter').textContent = `${state.step.kind === 'debug' ? 'Repair' : state.step.kind === 'predict' ? 'Prediction' : 'Question'} ${state.quizIndex + 1} of ${quizzes.length}`;
  $('#question-context').textContent = state.step.explanation;
  $('#question-code').hidden = !state.step.code;
  $('#question-code').innerHTML = highlight(state.step.code || '');
  $('#quiz-to-code').textContent = 'Continue to next step →';

  const statusEl = $('#quiz-status');
  if (chosen === undefined) {
    statusEl.textContent = '';
    statusEl.className = 'quiz-status';
  } else if (chosen === current.answer) {
    statusEl.textContent = 'Correct';
    statusEl.className = 'quiz-status correct';
  } else {
    statusEl.textContent = 'Try again';
    statusEl.className = 'quiz-status wrong';
  }

  $('#quiz-question').textContent = current.question;
  $('#quiz-options').innerHTML = current.options.map((opt, idx) => {
    const selected = chosen === idx;
    const outcome = selected ? (idx === current.answer ? 'correct' : 'wrong') : '';
    return `
      <div class="quiz-option-row">
        <span class="quiz-option-num">${idx + 1}</span>
        <button type="button" class="quiz-option-btn ${selected ? 'selected' : ''} ${outcome}" data-opt="${idx}">
          ${escapeHTML(opt)}
        </button>
      </div>
    `;
  }).join('');

  $('#quiz-options').querySelectorAll('[data-opt]').forEach((btn) => {
    btn.addEventListener('click', () => {
      const idx = Number(btn.dataset.opt);
      state.quizAnswers.set(key, idx);
      state.showExplanation = true;
      drawQuizPane();
    });
  });

  const expEl = $('#quiz-explanation');
  expEl.hidden = !state.showExplanation;
  expEl.textContent = current.explanation;
  const repaired = $('#repair-preview');
  repaired.hidden = !(state.step.repairTemplate && chosen === current.answer);
  if (!repaired.hidden) repaired.innerHTML = highlight(state.step.repairTemplate.replace('REPLACEMENT', current.options[chosen]));
}

function isDirty(draft) {
  return draft && draft.doc.getValue() !== draft.savedSource;
}

function drawSaveStatus() {
  const dirty = isDirty(state.drafts.get(editorLessonId));
  $('#save-status').textContent = state.pendingSaves ? 'Saving…' : dirty ? 'Unsaved changes' : 'Saved';
  $('#save-status').classList.toggle('dirty', Boolean(dirty));
  $('#editor-save').disabled = Boolean(state.pendingSaves);
}

function activateEditor(lesson) {
  if (!state.drafts.has(lesson.id)) {
    const doc = new CodeMirror.Doc(lesson.source, 'text/x-c++src');
    const todo = lesson.source.split('\n').findIndex((line) => /^\s*\/\/ TODO/.test(line));
    doc.setCursor(Math.max(0, todo), 0);
    state.drafts.set(lesson.id, { doc, revision: lesson.revision, savedSource: lesson.source });
  }
  if (editorLessonId !== lesson.id) {
    CodeMirror.Vim.exitInsertMode(editor);
    editorLessonId = lesson.id;
    editor.swapDoc(state.drafts.get(lesson.id).doc);
  }
  // The editor may have just become visible after a reading/quiz activity.
  requestAnimationFrame(() => { editor.refresh(); editor.scrollIntoView(editor.getCursor(), 80); });
  drawSaveStatus();
}

function saveDraft(id = editorLessonId) {
  const draft = state.drafts.get(id);
  if (!draft) return Promise.reject(new Error('Open a coding assignment before saving.'));
  const source = draft.doc.getValue();
  state.pendingSaves++;
  drawSaveStatus();
  const task = saveQueue.then(async () => {
    const result = await api(`/api/save/${id}`, {
      method: 'POST',
      headers: { 'Content-Type': 'application/json', 'X-Course-Token': state.token },
      body: JSON.stringify({ source, revision: draft.revision }),
    });
    draft.savedSource = source;
    draft.revision = result.revision;
    return { source, revision: result.revision };
  }).finally(() => { state.pendingSaves--; drawSaveStatus(); });
  saveQueue = task.catch(() => {});
  return task;
}

function initializeEditor() {
  editor = CodeMirror.fromTextArea($('#code-editor'), {
    mode: 'text/x-c++src', theme: 'material-darker', keyMap: 'vim',
    lineNumbers: true, indentUnit: 4, tabSize: 4, indentWithTabs: false,
    inputStyle: 'textarea', viewportMargin: 10,
    extraKeys: { 'Ctrl-S': () => saveDraft().catch((e) => showError(e.message)),
                 'Cmd-S': () => saveDraft().catch((e) => showError(e.message)) },
  });
  editor.on('vim-mode-change', (mode) => {
    $('#editor-mode').textContent = mode.mode.toUpperCase();
    $('#editor-mode').classList.toggle('insert', mode.mode === 'insert');
  });
  editor.on('change', () => { drawSaveStatus(); drawRunner(); });
  CodeMirror.Vim.defineEx('write', 'w', () => {
    saveDraft().catch((error) => showError(error.message));
  });
}

function drawRunner() {
  const result = state.results.get(state.lesson?.id);
  const draft = state.drafts.get(state.lesson?.id);
  const stale = result && draft && result.source !== draft.doc.getValue();
  const busy = Boolean(state.running);
  $('#run').disabled = busy || !state.lesson;
  $('#quick-test').disabled = busy || !state.lesson;
  $('#run-status').textContent =
    state.running === state.lesson?.id
      ? 'RUNNING'
      : stale ? 'EDITED' : result
      ? result.passed
        ? 'PASSED'
        : 'NEEDS WORK'
      : 'READY';
  $('#run-status').className = `status ${result && !stale ? (result.passed ? 'passed' : 'failed') : ''}`;
  $('#test-output').textContent =
    state.running === state.lesson?.id
      ? 'Saving buffer, compiling C++20, and running behavioral tests…'
      : (stale ? 'Code changed since this run. Press Alt+R to test the current buffer.\n\nPrevious result:\n' : '') + (result?.message || 'Press Alt+R or Run to save your browser code and run the C++20 behavioral tests.');
  $('#test-output').classList.toggle('success', Boolean(result?.passed && !stale));

  const solEl = $('#solution-view');
  solEl.hidden = !state.showSolution;
  if (state.showSolution && state.lesson) {
    solEl.innerHTML = highlight(state.lesson.solution || '// Reference solution not found.');
  }
}

function drawRightPane() {
  if (!state.step || !state.lesson) return;
  const kind = state.step.kind;
  $('#activity-kind').textContent = { read: 'EXPLANATION', quiz: 'KNOWLEDGE CHECK', predict: 'PREDICT THE BEHAVIOR', debug: 'REPAIR DRILL', code: 'CODING ASSIGNMENT' }[kind];
  $('#activity-title').textContent = state.step.title;
  $('#activity-objective').textContent = state.step.objective;
  $('#read-pane').hidden = kind !== 'read';
  $('#quiz-pane').hidden = !['quiz', 'predict', 'debug'].includes(kind);
  $('#code-pane').hidden = kind !== 'code';
  if (kind === 'read') {
    $('#step-reading').innerHTML = markdown(state.step.explanation) + (state.step.code ? `<pre class="question-code"><code>${highlight(state.step.code)}</code></pre>` : '');
  } else if (kind !== 'code') {
    drawQuizPane();
  } else {
    activateEditor(state.lesson);
    drawRunner();
  }
}

async function refreshCourse() {
  const data = await api('/api/course');
  state.lessons = data.lessons;
  state.steps = data.steps || [];
  state.token = data.token;
  if (state.lesson) {
    const current = state.lessons.find((lesson) => lesson.id === state.lesson.id);
    $('#completion').textContent = current?.completed ? '✓ Submitted' : 'Not submitted';
  }
}

async function loadStep(stepId) {
  const step = state.steps.find((s) => s.id === stepId) || state.steps[0];
  if (!step) return;
  state.step = step;
  const request = ++state.request;
  $('#reload').disabled = true;
  showError();

  try {
    const lesson = await api(`/api/lessons/${encodeURIComponent(step.lessonId)}`);
    if (request !== state.request) return;
    state.lesson = lesson;
    if (state.results.get(lesson.id)?.source !== lesson.source) state.results.delete(lesson.id);
    state.quizIndex = 0;
    state.showExplanation = false;
    state.showSolution = false;

    state.lessons.forEach((item) => {
      if (item.id === lesson.id) item.completed = lesson.completed;
    });

    document.title = `${lesson.id} · ${step.title} · C++ Learning Lab`;
    $('#title').textContent = step.title;
    $('#lesson-number').textContent = `CH 09 · ${lesson.id}`;
    $('#duration').textContent = `~${lesson.minutes} min`;
    $('#completion').textContent = lesson.completed ? '✓ Submitted' : 'Not submitted';
    $('#file-path-label').textContent = lesson.path;
    $('#challenge-brief').textContent = lesson.challenge;
    $('#challenge-examples').innerHTML = lesson.examples.map((ex) => `<code>${escapeHTML(ex)}</code>`).join('');

    $('#open-command').textContent = `nvim ${lesson.path}`;
    $('#copy').textContent = 'Copy command';
    $('#submit-command').textContent = `./course check ${lesson.id}`;
    $('#reference').href = lesson.url;
    $('#hints').innerHTML = lesson.hints.map((hint, index) => `<details><summary>Hint ${index + 1}<span>+</span></summary><p>${escapeHTML(hint)}</p></details>`).join('');

    const index = state.steps.findIndex((item) => item.id === step.id);
    $('#previous').disabled = index === 0;
    $('#next').disabled = index === state.steps.length - 1;
    $('#position').textContent = `${index + 1} of ${state.steps.length}`;

    drawNavigation();
    drawLeftPane();
    drawRightPane();
  } catch (error) {
    if (request === state.request) showError(`${error.message} Your files have not been changed.`);
  } finally {
    if (request === state.request) $('#reload').disabled = false;
  }
}

function route() {
  const stepId = parseRouteHash(location.hash);
  if (!stepId) {
    const completedLessons = new Set(state.lessons.filter((l) => l.completed).map((l) => l.id));
    const first = state.steps.find((s) => !completedLessons.has(s.lessonId)) || state.steps[0];
    if (!first) return;
    history.replaceState(null, '', `#${first.id}`);
    loadStep(first.id);
  } else {
    if (location.hash !== `#${stepId}`) {
      history.replaceState(null, '', `#${stepId}`);
    }
    loadStep(stepId);
  }
}

document.querySelectorAll('.pane-tab').forEach((tab) => {
  tab.addEventListener('click', () => {
    state.leftView = tab.dataset.left;
    drawLeftPane();
  });
});

$('#step-select').addEventListener('change', (e) => {
  location.hash = e.target.value;
});

$('#quiz-prev').addEventListener('click', () => {
  if (state.quizIndex > 0) {
    state.quizIndex--;
    state.showExplanation = false;
    drawQuizPane();
  }
});

$('#quiz-next').addEventListener('click', () => {
  const len = currentQuestions().length;
  if (state.quizIndex < len - 1) {
    state.quizIndex++;
    state.showExplanation = false;
    drawQuizPane();
  }
});

$('#quiz-explain-btn').addEventListener('click', () => {
  state.showExplanation = !state.showExplanation;
  drawQuizPane();
});

$('#quiz-to-code').addEventListener('click', nextStep);
$('#read-continue').addEventListener('click', nextStep);

$('#editor-save').addEventListener('click', () => {
  showError();
  saveDraft().catch((error) => showError(error.message));
});

$('#reload').addEventListener('click', async () => {
  try {
    const id = state.lesson?.id;
    if (isDirty(state.drafts.get(id)) && !confirm('Discard this unsaved browser draft and reload main.cpp from disk?')) return;
    await refreshCourse();
    state.drafts.delete(id);
    editorLessonId = null;
    if (state.step) await loadStep(state.step.id);
  } catch (error) {
    showError(error.message);
  }
});

$('#copy').addEventListener('click', async () => {
  try {
    await navigator.clipboard.writeText($('#open-command').textContent);
    $('#copy').textContent = 'Copied!';
  } catch {
    $('#copy').textContent = 'Select and copy above';
  }
});

async function executeRun() {
  if (!state.lesson || state.step?.kind !== 'code' || state.lesson.id !== state.step.lessonId || state.running) return;
  const id = state.lesson.id;
  state.running = id;
  showError();
  drawRunner();
  try {
    const saved = await saveDraft(id);
    const result = await api(`/api/test/${id}`, {
      method: 'POST',
      headers: { 'Content-Type': 'application/json', 'X-Course-Token': state.token },
      body: JSON.stringify({ revision: saved.revision }),
    });
    state.results.set(id, { ...result, source: saved.source });
  } catch (error) {
    state.results.set(id, { passed: false, message: error.message });
    showError(error.message);
  } finally {
    state.running = null;
    drawRunner();
  }
}

$('#run').addEventListener('click', executeRun);
$('#quick-test').addEventListener('click', executeRun);

// Capture before Vim's keymap: Alt+R runs from both Normal and Insert mode.
document.addEventListener('keydown', (event) => {
  if (event.altKey && !event.ctrlKey && !event.metaKey && event.key.toLowerCase() === 'r' && state.step?.kind === 'code') {
    event.preventDefault();
    event.stopImmediatePropagation();
    if (!event.repeat) executeRun();
  }
}, true);

window.addEventListener('beforeunload', (event) => {
  if ([...state.drafts.values()].some(isDirty)) {
    event.preventDefault();
    event.returnValue = '';
  }
});

$('#solution-btn').addEventListener('click', () => {
  state.showSolution = !state.showSolution;
  drawRunner();
});

for (const [selector, delta] of [['#previous', -1], ['#next', 1]]) {
  $(selector).addEventListener('click', () => {
    const index = state.steps.findIndex((s) => s.id === state.step?.id);
    const next = state.steps[index + delta];
    if (next) location.hash = next.id;
  });
}

window.addEventListener('hashchange', route);
window.addEventListener('focus', () => {
  if (!state.lesson) return;
  refreshCourse().then(drawNavigation).catch(() => {});
});

initializeEditor();
refreshCourse()
  .then(route)
  .catch((error) => showError(`Could not connect to the local companion: ${error.message}. Keep ./course web running, then refresh.`));
