project(punch-a-chimp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(punch-a-chimp main.cpp)
target_link_libraries(punch-a-chimp SDL2)
