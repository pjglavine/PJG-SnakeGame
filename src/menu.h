#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "SDL.h"
#include "renderer.h"

// For reviewer: This whole file is an addition to the original Udacity repository.

class Menu {

public:
  void Start(); //PJG: Start menu prompt function.
  void GameOver(); //PJG: Game over menu prompt function.
  bool GameOverStatus(); //PJG: returns gameover flag.
  bool ContinueStatus(); //PJG: returns continue flag.

private:
  bool gameOver = false; //PJG: Flag let's us know if gameover has occured.
  bool gameContinue = false; //PJG: Flag to see if the user wants to keep playing.
};

#endif
