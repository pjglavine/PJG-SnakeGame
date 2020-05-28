#include <iostream>
#include <thread>
#include <chrono>
#include "menu.h"
#include "SDL.h"

// For reviewer: This whole file is an addition to the original Udacity repository.

// Menu prompt for when the game launches.
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

// Menu prompt for when the snake dies.
void Menu::GameOver(){

  // Output the GameOver message on the screen with a prompt to either restart or quit.
  SDL_Event e;
  while(true){

    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_KEYDOWN){
        switch (e.key.keysym.sym){
          case SDLK_SPACE:
          gameContinue = true; // If the user presses space, the game restarts.
          return;

          case SDLK_RETURN:
          gameOver = true; // If the user presser Enter, the game ends and the application quits.
          return;
        }
      }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
}

// Return the game status to decide if user will keep playing.
bool Menu::GameOverStatus(){return gameOver;}
bool Menu::ContinueStatus(){return gameContinue;} // Used to make sure the Start menu doesn't reappear during sessions.
