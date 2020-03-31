/*********************************************************************
** Program name:  Final Project (Game.hpp)
** Author:        Aaron Nesbit
** Date:          12/1/19
** Description:   This is the header file for the class Game
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Butthead.hpp"
#include "Buttheads_House.hpp"
#include "Street.hpp"
#include "Burger_World.hpp"
#include "Highland_High.hpp"
#include "Maxi_Mart.hpp"
#include "Gwar_Show.hpp"

class Game
{
   private:
      Butthead *butthead;                        // Private pointers
      Space *current_space;                      // declared
      Space *buttheads_house;
      Space *street;
      Space *burger_world;
      Space *highland_high;
      Space *maxi_mart;
      Space *gwar_show;

   public:
      Game();                                   // Constructor
      ~Game();                                  // Destructor
      void menu();                              // Start menu function
      void map(Space *);                        // Map function
};

#endif
