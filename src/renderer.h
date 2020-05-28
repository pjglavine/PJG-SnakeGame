#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "snake.h"
#include "menu.h"

// For reviewer: added poison object reference parameter to Render. Also overloaded renderer
// such that it takes a string indicating which menu is being rendered ie: start or gameover screens.

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food, SDL_Point const &poison); //PJG: modified.
  void Render(std::string menuOption); //PJG overloaded function
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif
