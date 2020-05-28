#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "SDL.h"
#include "renderer.h"

class Menu {

public:
  void Start();
  void GameOver();
  bool GameOverStatus();
  bool ContinueStatus();

private:
  bool gameOver = false;
  bool gameContinue = false;
};

#endif
