#include "game.h"
#include <iostream>
#include "SDL.h"
#include "audio.h"

// For reviewer: Changes to this code are marked with the tag "PJG:"
Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(1, static_cast<int>(grid_width-2)), //PJG: modified to keep food on screen.
      random_h(1, static_cast<int>(grid_height-2)) { //PJG: and prevent food from spawning against wall
  PlaceFood();
  PlacePoison(); //PJG: Place initial poison
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  Audio audio; //PJG: Construct audio object for sound playback.
  audio.GameMusic(true); //PJG: start playing music.

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake, audio); //PJG: function now takes audio object.

    //PJG: Check if the snake is alive. If it is, run update function.
    if (snake.alive){
      Update(audio);
    } else {
      //PJG: If snake dies, turn off the game music and play game over sound.
      audio.GameMusic(false);
      audio.GameOverSound();
      break;
    }

    renderer.Render(snake, food, poison); //PJG: added poison to be rendered.

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

//PJG: Added poison spawner.
void Game::PlacePoison() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);

    // Check that the location is not occupied by a snake item before placing
    // food.

    //PJG: Function also checks if the cell is a food cell using new FoodCell function.
    if (!snake.SnakeCell(x, y) && !FoodCell(x,y)) {
      poison.x = x;
      poison.y = y;
      return;
    }
  }
}


void Game::Update(Audio &audio) {
  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  //PJG: Changed this section such that everytime the snake eats, whether it's food or poison,
  // a new food and poison item will be spawned randomly on the map.

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    PlacePoison();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
    audio.EatSound(); //PJG: Plays eating sound effect.
  }

  // Check if there's poison over here
  if (poison.x == new_x && poison.y == new_y) {
    score--; //PJG: eating poison subtracts from score.
    PlaceFood();
    PlacePoison();

    // Grow snake and increase speed.
    snake.ShrinkBody(); //PJG: New function for shrinking the snake size if he eats poison.
    snake.speed -= 0.02; //PJG: Eating poison also slows the snake down.
    audio.PoisonSound(); //PJG: Play poison sound effect.
  }
}

//PJG: Check if there is food spawned in cell.
bool Game::FoodCell(int x, int y) {
  if (x == static_cast<int>(food.x) && y == static_cast<int>(food.y)) {
    return true;
  }
  return false;
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
