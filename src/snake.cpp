#include "snake.h"
#include <cmath>
#include <iostream>

// For reviewer: changes marked with "PJG:" tag.
void Snake::Update() {
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)};  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    UpdateBody(current_cell, prev_cell);
  }
}

void Snake::UpdateHead() {
  switch (direction) {
    case Direction::kUp:
      head_y -= speed;
      break;

    case Direction::kDown:
      head_y += speed;
      break;

    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }

  //PJG: Add boundaries to the map so the snake dies if it hits a wall instead of wrapping around.
  if((head_x < 0) || (head_x > grid_width) || (head_y < 0) || (head_y > grid_height)){
    alive = false;
  }
  // Wrap the Snake around to the beginning if going off of the screen.
  //head_x = fmod(head_x + grid_width, grid_width);
  //head_y = fmod(head_y + grid_height, grid_height);
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  //PJG: check if the snake is growing or shrinking.
  if (!growing && !shrinking) {
    // Remove the tail from the vector.
    body.erase(body.begin());
  } else if (growing && !shrinking){ //PJG: if growing and not shrinking, grow the snake.
    growing = false;
    size++;
  } else if (!growing && shrinking){ //PJG: if shrinking and not growing, shrink the snake.
    shrinking = false;
    if((size - 1 ) == 0){ //PJG: check if the snake will have zero size after shrink is performed, if so, the snake is dead.
      alive = false;
    }
    if(size > 1){ //PJG: if the snake is shrinking and it's current size is greater than 1, decrease the snake size by 1.
      size--;
      body.erase(body.begin()); //PJG: pop the tail twice to make the snake body shorter.
      body.erase(body.begin());
    }
  }

  // Check if the snake has died.
  for (auto const &item : body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      alive = false;
    }
  }
}

void Snake::GrowBody() { growing = true; }
void Snake::ShrinkBody() { shrinking = true;} //PJG: added shrinking getter function.

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}
