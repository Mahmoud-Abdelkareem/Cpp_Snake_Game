#include <iostream>
#include "SDL.h"
#include "obstacle.h"

void Obstacle:: putObstacle(){

    SDL_Point point;

    for(int i=0; i<_grid_width/2; i++)
    {
        point.x = i + (_grid_width/4);
        point.y = _grid_height/2;
        obstaclePoints.emplace_back(point);
    }
 
}

 std::vector<SDL_Point> Obstacle:: getObstacle(){
     return obstaclePoints;
 }

 bool Obstacle::ObstacleCell(int x, int y)
{
  for (auto const &point : obstaclePoints)
  {
    if (x == point.x && y == point.y)
    {
      return true;
    }
  }
  return false;
}