
#include "game.h"
#include "screen.h"
#include "constants.h"
#include <iostream>
#include <memory>

int main(int argc, char** argv) {

  if(argc == 2) {
    auto arg = std::string(argv[1]);
    if(arg == "-v" || arg == "--version") {
      std::cout<<"Terminal-Pong 1.0.0\n";
    } else if (arg == "-h" || arg == "--help") {
      std::cout<<"Usage: "<<"pong [option]\n\nOptions:\n";
      std::cout<<" -h, --help            print pong commandline options (currently set)\n";
      std::cout<<" -v, --version         print Pong version\n";
      std::cout<<"\nFor more information: githublink"<<std::endl;
    } else {
      std::cout<<"Bad option: "<<arg<<"\n";
      std::cout<<"Try 'pong -h' for more information."<<std::endl;

    }
    return 0;

  } else if(argc >= 3) {
    std::cout<<"Too many arguments.\nUse -h to see available options\n";
    return 0;
  }


  std::unique_ptr<game::Screen> gameScreen(new game::Screen());

  auto [height, width] = gameScreen->getDimensions();
  if(height < constants::MIN_SCREEN_HEIGHT || width < constants::MIN_SCREEN_WIDTH) {
    std::cout<<" Terminal dimensions not large enough. Please try after widening terminal";
  }

//  std::unique_ptr<game::Game> pingPongGame( new game::Game());
//  pingPongGame->start();
  return 0;
}
