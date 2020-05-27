
#include "game.h"
#include "constants.h"
#include "ncurses.h"
#include "screen.h"
#include "paddle.h"
#include "ball.h"
#include <iostream>
#include <memory>

int main(int argc, char **argv) {
  using namespace std;
  using namespace constants;

  // commandline usage
  if (argc > 1) {
    if (argc == 2) {
      auto arg = string(argv[1]);
      if (arg == "-v" || arg == "--version") {
        cout << "Terminal-Pong 1.0.0\n";
      } else if (arg == "-h" || arg == "--help") {
        cout << "Usage: "
                  << "pong [option]\n\nOptions:\n";
        cout << " -h, --help            print Pong commandline options "
                     "(currently set)\n";
        cout << " -v, --version         print Pong version\n";
        cout << "\nFor more information: githublink" << endl;
      } else {
        cout << "Bad option: " << arg << "\n";
        cout << "Try 'pong -h' for more information." << endl;
      }
    } else if (argc >= 3) {
      cout << "Too many arguments.\nUse '-h' to see available options\n";
    }
    return 0;
  }

  // game
  try {
    unique_ptr<game::Screen> screen(new game::Screen());
    auto [height, width] = screen->getDimensions();

    if (height < MIN_SCREEN_HEIGHT ||
        width < MIN_SCREEN_WIDTH) {
      screen.reset();
      cout << "Terminal dimensions not large enough. Please try after "
                   "widening terminal"
                << endl;
      return 0;
    }

    const uint32_t ARENA_HEIGHT = MIN_SCREEN_HEIGHT;
    const uint32_t ARENA_WIDTH = MIN_SCREEN_WIDTH;
    const uint32_t ARENA_Y = height/2-ARENA_HEIGHT/2;
    const uint32_t ARENA_X = width/2-ARENA_WIDTH/2;
    const double PLAYER_1_PADDLE_Y = ARENA_HEIGHT-1;
    const double PLAYER_1_PADDLE_X = ARENA_WIDTH/2 - MIN_PADDLE_WIDTH/2;
    const double PLAYER_2_PADDLE_Y =  1.0;
    const double PLAYER_2_PADDLE_X = ARENA_WIDTH/2 - MIN_PADDLE_WIDTH/2;

    unique_ptr<display::Window> gameArena(new display::Window(ARENA_HEIGHT, ARENA_WIDTH, ARENA_Y, ARENA_X));
    screen->setArena(gameArena);

    unique_ptr<world::IEntity> player1Paddle = make_unique<world::Paddle>(PLAYER_1_PADDLE_Y, PLAYER_1_PADDLE_X, MAX_PADDLE_Y_VELOCITY, MAX_PADDLE_X_VELOCITY, MIN_PADDLE_WIDTH, PADDLE_BODY_CHARACTER);
    unique_ptr<world::IEntity> player2Paddle = make_unique<world::Paddle>(PLAYER_2_PADDLE_Y, PLAYER_2_PADDLE_X, MAX_PADDLE_Y_VELOCITY, MAX_PADDLE_X_VELOCITY, MIN_PADDLE_WIDTH, PADDLE_BODY_CHARACTER);

    unique_ptr<world::IEntity> ball = make_unique<world::Ball>(ARENA_HEIGHT/2, ARENA_WIDTH/2, MAX_BALL_Y_VELOCITY, MAX_BALL_Y_VELOCITY, BALL_WIDTH, BALL_BODY_CHARACTER);

    // construct world
    // construct game
    // game.start();



//    unique_ptr<game::Game> pingPongGame(new game::Game());
//    pingPongGame->start();

  } catch (std::exception &err) {
    std::cerr << err.what() << std::endl;
  }
  std::cout << "got dimensions";
  //
  std::cout << std::endl;
  return 0;
}
