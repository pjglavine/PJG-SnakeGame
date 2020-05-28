#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "audio.h"
#include "menu.h"

// For reviewer: changes made here include adding poison SDL point, adding PlacePoison Function
// adding FoodCell function and changing the Update function such that it takes an audio object.
class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;


 private:
  Snake snake;
  SDL_Point food;
  SDL_Point poison; //PJG: added.

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void PlacePoison(); //PJG: added.
  bool FoodCell(int x, int y); //PJG: added.
  void Update(Audio &audio); //PJG: modified to take audio object.
};

#endif
