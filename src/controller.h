#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "audio.h"

// For reviewer: only change is adding the audio object to HandleInput parameters list.
class Controller {
 public:
  void HandleInput(bool &running, Snake &snake, Audio &audio) const; //PJG: modified.

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif
