/*
 * window.h
 * Defines window class using ncurses API
 */

#include <curses.h>

namespace world {
class Window {
public:

    Window();

    void drawAtPosition();

    ~Window();

private:
    int height, width, y, x;
    WINDOW* _win;
};
} // world