# Chapter 9 browser companion: design references

Reviewed October 18, 2026. This is an original local UI and original C++ lesson
material, not a copy of Boot.dev's course frontend, branding, or course content.
No Boot.dev source code or assets are included. No Boot.dev account, API,
service, or runtime dependency is used.

Public repositories inspected:

- [bootdotdev/curriculum](https://github.com/bootdotdev/curriculum): structured
  learning paths and the course/project progression model. The repository is a
  roadmap, not the main course UI source.
- [bootdotdev/bootdev](https://github.com/bootdotdev/bootdev): its README separates
  `bootdev run` from `bootdev submit`. This companion similarly distinguishes
  running saved-code tests from the existing terminal submission command.
  [License](https://github.com/bootdotdev/bootdev/blob/main/LICENSE): MIT.
- [bootdotdev/prepcards](https://github.com/bootdotdev/prepcards): the
  `src/lib/Game.svelte` and `src/lib/FlipCard.svelte` components use revealable
  review cards. This companion adapts the interaction idea into accessible
  question/explanation disclosures using original Chapter 9 prompts. There is
  no copied Svelte code, card content, imagery, or animation.
  [License](https://github.com/bootdotdev/prepcards/blob/main/LICENSE): MIT.

## Deliberate differences

- Only Chapter 9 is exposed in the UI.
- The left pane loads live LearnCpp pages directly; no article content is mirrored.
- Topic-specific activity sequences replace fixed quiz/challenge pairs. Each of
  the seven LearnCpp pages was researched independently. Source quizzes and the
  Hi-Lo assignment are adapted in original wording and linked; supplementary
  exercises fill the remaining concepts. Per-page provenance and coverage maps
  are in `tools/chapter9/09_*.json`. The articles themselves are not mirrored.
- The browser editor uses locally bundled CodeMirror 5.65.16 and its Vim keymap,
  not a Neovim process. Its MIT license and pinned sources are in
  [vendor/README.md](vendor/README.md). External Neovim remains an option.
- Real C++20 checks run locally, not in WebAssembly or a cloud environment.
- Progress comes from the existing course submission records; a browser test pass
  is not a completion record. There is no artificial XP, currency, or streak state.
- The browser editor writes your challenge file when you save or run tests. There
  are no reset controls, remote binding, browser submissions, or Git actions.
- No CDN or extra editor installation is needed. Alt+R saves and runs in both Vim
  Normal and Insert mode; stale revisions cannot overwrite externally edited files.

## Mini-lesson design references (October 19, 2026)

Public Boot.dev assignments reviewed for the teaching-plus-immediate-task pattern:

- [Python: Fix Your First Bug](https://www.boot.dev/lessons/d3d50474-d60a-4751-b71e-e145ae95b966)
- [Python: Syntax Errors Quiz](https://www.boot.dev/lessons/28607ef6-faa5-42a8-a9bc-ec361b3dd87a)
- [Go: Learn Go](https://www.boot.dev/lessons/224252be-adc9-452f-8ed0-0b305b25d0cb)
- [OOP: Welcome](https://www.boot.dev/lessons/ea171b42-0d9b-43d2-a136-4e2e89227f9e)

These informed activity granularity and progression, not the C++ exercise content.
