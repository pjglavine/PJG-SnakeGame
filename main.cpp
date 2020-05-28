#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "menu.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;

  // Construct the game music here.
  // GameSound music("/snakegamemusic.wav");
  // Wrap menu system around the game.run
  Menu menu;
  while(menu.GameOverStatus() == false){
      if(menu.ContinueStatus() == false){
        renderer.Render("start");
        menu.Start();
      }
      Game game(kGridWidth, kGridHeight);
      game.Run(controller, renderer, kMsPerFrame);
      renderer.Render("gameover");
      menu.GameOver();
      std::cout << "Score: " << game.GetScore() << "\n";
      std::cout << "Size: " << game.GetSize() << "\n";
    }
    std::cout << "Game has terminated successfully!\n";

  return 0;
}
