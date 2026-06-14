include(FetchContent)

cmake_minimum_required(VERSION 3.16)
project(maze LANGUAGES CXX)

FetchContent_Declare(
    terminal_library
    GIT_REPOSITORY https://github.com/K10-K10/Terminal-Library.git
    GIT_TAG main # We suport only latest version, so use main branch
)

FetchContent_MakeAvailable(terminal_library)

add_executable(maze src/main.cpp src/make.cpp)
target_link_libraries(maze PRIVATE K10-K10::terminal)
