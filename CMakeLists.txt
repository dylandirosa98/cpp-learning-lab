cmake_minimum_required(VERSION 3.20)
project(cpp_learning_lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic)

file(GLOB lesson_cmake_files CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/workspaces/*/CMakeLists.txt")
foreach(lesson_cmake_file IN LISTS lesson_cmake_files)
    get_filename_component(lesson_directory "${lesson_cmake_file}" DIRECTORY)
    get_filename_component(lesson_name "${lesson_directory}" NAME)
    add_subdirectory("${lesson_directory}" "${CMAKE_BINARY_DIR}/${lesson_name}")
endforeach()

add_executable(testlesson testlesson.cpp)