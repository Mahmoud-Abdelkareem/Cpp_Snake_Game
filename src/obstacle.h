#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "SDL.h"
#include <vector>

class Obstacle {
 public:
    //constructor
    Obstacle(int grid_width, int grid_height): _grid_width(grid_width),_grid_height(grid_height){
        putObstacle();
    }
    bool ObstacleCell(int x, int y); //check if the coordinates are obstacle cell or not
    std::vector<SDL_Point> getObstacle(); //return vector contains obstacle points
     
   
private:
    void putObstacle(); //to put the obstacle on screen
    std::vector <SDL_Point> obstaclePoints;
    size_t _grid_width, _grid_height;
};


#endif