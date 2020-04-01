/*********************************************************************
** Program name:  Project 3 (Game.hpp)
** Author:        Aaron Nesbit
** Date:          11/7/19
** Description:   This is the header file for the class Game
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "Blue_Men.hpp"
#include "Medusa.hpp"
#include "Harry_Potter.hpp"

class Game
{
   private:
      Character *player_one;           // Pointer to Player 1 object
      Character *player_two;           // Pointer to Player 2 object

   public:
      Game();                          // Constructor
      ~Game();                         // Destructor
      void menu();                     // Menu function
      void play_as_Vampire();          // Vampire creation function
      void play_as_Barbarian();        // Barbarian creation function
      void play_as_Blue_Men();         // Blue Men creation function
      void play_as_Medusa();           // Medusa creation function
      void play_as_Harry_Potter();     // Harry Potter creation function
      void fight();                    // Combat logic function
};

#endif
