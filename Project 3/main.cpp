/*********************************************************************
** Program name:  Project 3 (main.cpp)
** Author:        Aaron Nesbit
** Date:          11/7/19
** Description:   This is the main() function for Project 3
*********************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Game.hpp"

using std::srand;
using std::time;

int main()
{
   srand(time(NULL));   // Random seed for die rolls

   Game game;           // Game object created

   game.menu();         // Menu function called and game begins

   return 0;
}
