cmake_minimum_required(VERSION 3.15)
project(pingpong)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include_directories(src/include)

find_package(Curses REQUIRED)

add_executable(pong
        src/ncurses.cpp
        src/screen.cpp
        src/window.cpp
        src/paddle.cpp
        src/ball.cpp
        src/inputHandler.cpp
        src/commands.cpp
        src/world.cpp
        src/game.cpp
        src/main.cpp
        )

target_link_libraries(pong ${CURSES_LIBRARIES})
