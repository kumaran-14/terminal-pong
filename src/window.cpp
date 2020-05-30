/*
 * window.cpp
 * Defines window in screen where game is rendered
 */

#include "window.h"
#include <memory>

namespace display {

Window::Window(uint32_t height, uint32_t width, uint32_t y, uint32_t x)
    : height(height), width(width), y(y), x(x) {
  this->_win = ncurses::createWindow(height, width, y, x);
}

void Window::drawAtPosition(uint32_t y, uint32_t x, std::string &str) {
  ncurses::draw(this->_win, y, x, str);
}

void Window::refresh() { ncurses::refresh(this->_win); }

display::Window::~Window() { ncurses::destroyWindow(this->_win); }

void Window::drawBorder() { ncurses::drawBox(this->_win); }

void Window::erase() { ncurses::erase(this->_win); }

} // namespace display