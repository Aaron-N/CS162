/*********************************************************************
** Program name:  Project 4 (Barbarian.hpp)
** Author:        Aaron Nesbit
** Date:          11/20/19
** Description:   This the the header file for the class Barbarian
*********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian: public Character
{
   public:
      Barbarian();                      // Constructor
      ~Barbarian();                     // Destructor
      int attack(Character *defender);  // Attack function
      void defend(int attackScore);     // defend function
};

#endif

