#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "menu.h"

//For reviewer: changes marked with "PJG:" tag.
int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;

  // Wrap menu system around the game.run
  Menu menu;

  //PJG: While the player hasn't pressed the Quit button in the gameover screen.
  while(menu.GameOverStatus() == false){
    //PJG: Check if the player has restarted the game from the game over screen, or if this is a fresh launch of the application.
      if(menu.ContinueStatus() == false){
        renderer.Render("start"); //PJG: Render the start menu.
        menu.Start(); //PJG: This function keeps polling until the player hits the space bar and begins the game.
      }
      Game game(kGridWidth, kGridHeight);
      game.Run(controller, renderer, kMsPerFrame);
      //PJG: if we break out of Run, the snake has died, prompt user with gameover menu.
      renderer.Render("gameover");
      menu.GameOver(); //PJG: Wait for the user to hit SPACE to continue or ENTER to quit.
      std::cout << "Score: " << game.GetScore() << "\n"; //PJG: Print score and size of snake after each instance of the game.
      std::cout << "Size: " << game.GetSize() << "\n";
    }
    std::cout << "Game has terminated successfully!\n";

  return 0;
}
