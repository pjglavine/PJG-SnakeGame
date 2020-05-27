# PJG-SnakeGame
A simple 2D Snake game built using C++ and SDL. This is my capstone project for the C++ Nanodegree program with Udacity.

[Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The goal in the game is to grow your snake as big as possible by eating the food (yellow blocks) and avoiding the poison (red blocks). While eating food grows the snake, eating poison will cause your snake and your score to shrink. If the snake size is small (only one blue block) and it eats poison it will die and it's game over. The walls are also deadly to the snake so avoid running into those! The snake is controlled using the arrow keys with the ENTER key allowing the player to pause and unpause games in progress.

The game utilizes several SDL libraries to render the game, receive controller input and output audio such as music and in-game event sounds. All game sounds and music were created by me using BeepBox https://beepbox.co.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.
