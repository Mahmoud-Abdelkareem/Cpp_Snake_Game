#include <iostream>
#include "gamemode.h"


bool GameMode::StartGame()
{
    int key;
    std::cout << " ##### WELCOME TO SNAKE GAME #####" << std::endl;
    std::cout << " #####    Please choose   ######" << std::endl;
    std::cout << " 1. Start New Game" << std::endl;
    std::cout << " 2. Quit Game" << std::endl;

    std::cin >> key;
    
    if (key == 1)
    {
        std::cout << "Game Started, Enjoy!!" << std::endl;
        return true;
    }
    else if (key == 2)
    {
        std::cout << "Quiting Snake Game" << std::endl;
        quitGame = true;
    }
    else if ((key < 1)||(key > 2))
    {
        std::cout << "Unavailavle Choice, Please Reselect From Avaialble Options" << std::endl;
        return false;
    }
    
}
