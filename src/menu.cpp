#include <iostream>
#include <thread>
#include <chrono>
#include "menu.h"
#include "SDL.h"

void Menu::Start(){
  // Infinitely wait for the user to press the space bar to begin playing the game.
  while(true){
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_KEYDOWN){
        if ((e.key.keysym.sym) == SDLK_SPACE){
          return;
        }
      }
    }

    // Add delay for while loop to reduce cpu demand.
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
}

void Menu::GameOver(){

  // Output the GameOver message on the screen with a prompt to either restart or quit.
  SDL_Event e;
  while(true){

    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_KEYDOWN){
        switch (e.key.keysym.sym){
          case SDLK_SPACE:
          gameContinue = true;
          return;

          case SDLK_RETURN:
          gameOver = true;
          return;
        }
      }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }


//Infinitely check for selected Option
// Wait for input.

//If restart option is selected. Stop
};

// Return the game status to decide if user will keep playing.
bool Menu::GameOverStatus(){return gameOver;}
bool Menu::ContinueStatus(){return gameContinue;} // Used to make sure the Start menu doesn't reappear during sessions.
