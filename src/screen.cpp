/*
 * screen.cpp
 * Implementation of Game Screen
 */
#include "screen.h"
#include "ncurses.h"
#include <iostream>

namespace game {

Screen::Screen() {
  ncurses::setlocale();
  ncurses::init();
  ncurses::cbreak();
  ncurses::noecho();
  ncurses::keypad();
  ncurses::meta();
  ncurses::nodelay();
  ncurses::curs_set(0);
  ncurses::typeahead();

  this->setDimensions();
}
Screen::~Screen() {
  ncurses::clear();
  ncurses::terminate();
}

void Screen::drawAtPosition(const uint32_t y, const uint32_t x,
                            const std::string &str) {
  ncurses::draw(y, x, str);
}
void Screen::setDimensions() {
  ncurses::setScreenDimensions(this->height, this->width);
}

std::tuple<uint32_t, uint32_t> Screen::getDimensions() {
  return {this->height, this->width};
}

void Screen::refresh() { ncurses::refresh(); }
display::Window *Screen::getArena() { return this->arena.get(); }

void Screen::setArena(std::unique_ptr<display::Window> &arena_window) {
  this->arena = std::move(arena_window);
}

} // namespace game
