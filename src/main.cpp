
#include "game.h"
#include "constants.h"
#include "ncurses.h"
#include "screen.h"
#include <iostream>
#include <memory>

int main(int argc, char **argv) {
  using namespace std;
  using namespace constants;
  // commandline usage
  if (argc > 1) {
    if (argc == 2) {
      auto arg = std::string(argv[1]);
      if (arg == "-v" || arg == "--version") {
        std::cout << "Terminal-Pong 1.0.0\n";
      } else if (arg == "-h" || arg == "--help") {
        std::cout << "Usage: "
                  << "pong [option]\n\nOptions:\n";
        std::cout << " -h, --help            print Pong commandline options "
                     "(currently set)\n";
        std::cout << " -v, --version         print Pong version\n";
        std::cout << "\nFor more information: githublink" << std::endl;
      } else {
        std::cout << "Bad option: " << arg << "\n";
        std::cout << "Try 'pong -h' for more information." << std::endl;
      }
    } else if (argc >= 3) {
      std::cout << "Too many arguments.\nUse '-h' to see available options\n";
    }
    return 0;
  }

  // game
  try {
    std::unique_ptr<game::Screen> screen(new game::Screen());
    auto [height, width] = screen->getDimensions();

    if (height < MIN_SCREEN_HEIGHT ||
        width < MIN_SCREEN_WIDTH) {
      screen.reset();
      std::cout << "Terminal dimensions not large enough. Please try after "
                   "widening terminal"
                << std::endl;
      return 0;
    }

    std::unique_ptr<display::Window> gameArena(new display::Window(MIN_SCREEN_HEIGHT, MIN_SCREEN_WIDTH, height/2-MIN_SCREEN_HEIGHT/2, width/2 - MIN_SCREEN_WIDTH/2));
    screen->setArena(gameArena);

//    const PLAYER_1_PADDLE_Y =


//    std::unique_ptr<game::Game> pingPongGame(new game::Game());
//    pingPongGame->start();

  } catch (std::exception &err) {
    std::cerr << err.what() << std::endl;
  }
  std::cout << "got dimensions";
  //
  std::cout << std::endl;
  return 0;
}
