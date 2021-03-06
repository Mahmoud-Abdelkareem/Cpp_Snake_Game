#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height, Obstacle &obstacle)
    : snake(grid_width, grid_height, obstacle),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)),
      _obstacle(obstacle) {
  PlaceFood();
  setSpeed();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, poisonFood, bonusFood);

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
  int x, y, z, w, q, m;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    z = random_w(engine);
    w = random_h(engine);
    q = random_w(engine);
    m = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      poisonFood.x = z;
      poisonFood.y = w;
      bonusFood.x = q;
      bonusFood.y = m;
      return;
    }
    //check that the location is not occupied by obstacle item
    if(!_obstacle.ObstacleCell(x, y)) {
      food.x = x;
      food.y = y;
      poisonFood.x = z;
      poisonFood.y = w;
      bonusFood.x = q;
      bonusFood.y = m;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
  else if(poisonFood.x == new_x && poisonFood.y == new_y) {
    score--;
    if(score < 0)
    {
      std::cout<<"Game Over !"<<std::endl;
      snake.alive = false;
    }
    snake.speed -= 0.05;
    PlaceFood(); 
  }
  else if (bonusFood.x == new_x && bonusFood.y == new_y) {
    if(score == 0)
    {
      score++;
    }
    else
    {
      score *= 2;
    }
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.04;
  }
}


int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }

void Game::setSpeed()
{
  std::cout<<"######### Choose Game Difficulty ########"<<std::endl;
  std::cout<<" 1- Easy "<<std::endl;
  std::cout<<" 2- Medium "<<std::endl;
  std::cout<<" 3- Hard "<<std::endl;
  std::cin>> Game::gameType;
  if(Game::gameType == 1)
  {
    snake.speed = 0.1f;
  }
  else if(Game::gameType == 2)
  {
    snake.speed = 0.2f;
  }
  else if(Game::gameType == 3)
  {
    snake.speed = 0.3f;
  }
}
