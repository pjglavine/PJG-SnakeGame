#include "controller.h"
#include <iostream>
#include "snake.h"

// For reviewer: Additions to this file are marked by comments using "PJG:" label.

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}
// PJG: Gave controller access to audio object by reference.
void Controller::HandleInput(bool &running, Snake &snake, Audio &audio) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;

        //PJG: Added a pause button to stop the game and resume.
        case SDLK_RETURN:
          float temp_speed = snake.speed; //PJG: temporarily store the snake's speed.
          snake.speed = 0; //PJG: stop the snake while paused.
          audio.Pause(); //PJG: play the pause audio sound effect.
          bool flag = true; //PJG: flag for exiting paused game state.

          //PJG: Begin polling for user to press ENTER to unpause the game.
          while (flag){
            std::this_thread::sleep_for(std::chrono::milliseconds(1)); //PJG: sleep to save CPU cycles.
            while (SDL_PollEvent(&e)) {
              if (e.type == SDL_KEYDOWN){
                if ((e.key.keysym.sym) == SDLK_RETURN){
                  snake.speed = temp_speed; //PJG: return snake's speed to unpaused state.
                  audio.Unpause(); //PJG: play unpause audio sound.
                  flag = false; //PJG: break out of the polling while loop.
                  break;
                }
              }
            }
          }
        }
      }
    }
  }
