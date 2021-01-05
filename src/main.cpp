#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "obstacle.h"
#include "gamemode.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  bool startGame{false};
  
  while(startGame != true)
  {
    GameMode initialGame;
    startGame = initialGame.StartGame();
    if(initialGame.quitGame == true)
    {
      return 0;
    }
  }
  
  Obstacle obstacle(kGridWidth, kGridHeight);
  Game game(kGridWidth, kGridHeight, obstacle);
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight, obstacle);
  Controller controller;
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  
  return 0;
}