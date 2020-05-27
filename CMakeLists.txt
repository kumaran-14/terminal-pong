cmake_minimum_required(VERSION 3.15)
project(pingpong)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/include)

find_package(Curses REQUIRED)

add_executable(pong
        src/ncurses.cpp
        src/screen.cpp
        src/window.cpp
        src/paddle.cpp
        src/ball.cpp
        src/world.cpp
        src/main.cpp
        )

target_link_libraries(pong ${CURSES_LIBRARIES})
