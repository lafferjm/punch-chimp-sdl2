project(punch-a-chimp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_library(window_lib OBJECT window/window.hpp window/window.cpp)

add_executable(punch-a-chimp main.cpp)
target_link_libraries(punch-a-chimp window_lib SDL2)
