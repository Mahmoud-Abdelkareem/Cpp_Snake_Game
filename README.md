# CPPND: Capstone Snake Game Example
This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program.

# Newly Added features:
1- Adding an obstacle in the middle of the screen and if the snake head hits it the game ends, also we need to add it in the checking before placing the new food.
2- Adding bonus food at the same time with normal food, if the snake gets it score is doubled if not zero, if the score is zero it increases to one and the speed increse by rate more than the normal increase.
3- Adding poison food at the same time with normal food and bonus food, if the snake gets it the speed decreases and score decrease by one, if the score become less than zero the game is over and user has to close the game by himself, and if the speed becomes less than zero the game is over and user has to close the game by himself.
4- Adding the ability of the user to choose to begin the game or to quit it and if the user chooses invalid option it will not be taken.
5- Adding the ability of the user to choose the initial speed of the game (easy,medium,hard).

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