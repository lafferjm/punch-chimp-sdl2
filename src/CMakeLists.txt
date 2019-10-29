project(punch-a-chimp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_library(window_lib OBJECT window/window.hpp window/window.cpp)
add_library(text_lib OBJECT text/text.hpp text/text.cpp)

add_library(fist_lib OBJECT objects/fist/fist/hpp objects/fist/fist.cpp)

add_executable(punch-a-chimp main.cpp)
target_link_libraries(punch-a-chimp window_lib text_lib fist_lib SDL2 SDL2_ttf)
