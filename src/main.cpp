
#include "ball.h"
#include "commands.h"
#include "constants.h"
#include "game.h"
#include "inputHandler.h"
#include "ncurses.h"
#include "paddle.h"
#include "screen.h"
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
        cout << "\nFor more information: https://github.com/kumaran-14/terminal-pong" << endl;
      } else {
        cout << "Bad option: " << arg << "\n";
        cout << "Try 'pong -h' for more information." << endl;
      }
    } else if (argc >= 3) {
      cout << "Too many arguments.\nUse '-h' to see available options\n";
    }
    return 0;
  }

  // seed randomness
  srand((unsigned)time(0));

  // game
  try {
    auto screen = make_unique<game::Screen>();
    auto [height, width] = screen->getDimensions();

    if (height < MIN_SCREEN_HEIGHT || width < MIN_SCREEN_WIDTH) {
      screen.reset();
      cout << "Terminal dimensions not large enough. Please "
              "increase terminal dimensions."
           << endl;
      return 0;
    }

    const uint32_t ARENA_HEIGHT = MIN_SCREEN_HEIGHT;
    const uint32_t ARENA_WIDTH = MIN_SCREEN_WIDTH;
    const uint32_t ARENA_Y = height / 2 - ARENA_HEIGHT / 2;
    const uint32_t ARENA_X = width / 2 - ARENA_WIDTH / 2;
    const double PLAYER_1_PADDLE_Y = ARENA_HEIGHT - 2;
    const double PLAYER_1_PADDLE_X = ARENA_WIDTH / 2 - MIN_PADDLE_WIDTH / 2;
    const double PLAYER_2_PADDLE_Y = 1.0;
    const double PLAYER_2_PADDLE_X = ARENA_WIDTH / 2 - MIN_PADDLE_WIDTH / 2;

    auto gameArena = make_unique<display::Window>(ARENA_HEIGHT, ARENA_WIDTH,
                                                  ARENA_Y, ARENA_X);
    screen->setArena(gameArena);

    // auto cannot be used since they cannot be 'moved' to base class type ptr
    unique_ptr<world::IEntity> player1Paddle(new world::Paddle(
        PLAYER_1_PADDLE_Y, PLAYER_1_PADDLE_X, MAX_PADDLE_Y_VELOCITY,
        MAX_PADDLE_X_VELOCITY, MIN_PADDLE_WIDTH, PADDLE_BODY_CHARACTER));
    unique_ptr<world::IEntity> player2Paddle(new world::Paddle(
        PLAYER_2_PADDLE_Y, PLAYER_2_PADDLE_X, MAX_PADDLE_Y_VELOCITY,
        MAX_PADDLE_X_VELOCITY, MIN_PADDLE_WIDTH, PADDLE_BODY_CHARACTER));

    unique_ptr<world::IEntity> ball(
        new world::Ball(ARENA_HEIGHT / 2, ARENA_WIDTH / 2, MAX_BALL_Y_VELOCITY,
                        0, BALL_WIDTH, BALL_BODY_CHARACTER));

    auto world = make_unique<game::World>(ARENA_HEIGHT, ARENA_WIDTH,
                                          player1Paddle, player2Paddle, ball);

    auto keyboardHandler =
        make_unique<game::InputHandler>(make_unique<game::MoveLeftCommand>(),
                                        make_unique<game::MoveRightCommand>());

    auto pongGame = make_unique<game::Game>(world, screen, keyboardHandler);
    pongGame->start();

  } catch (exception &err) {
    cerr << err.what() << std::endl;
  }

  cout << std::endl;
  return 0;
}
