/*********************************************************************
** Program name:  Project 4 (Vampire.hpp)
** Author:        Aaron Nesbit
** Date:          11/20/19
** Description:   This is the header file for the class Vampire
*********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire: public Character
{
   public:
      Vampire();                                    // Constructor
      ~Vampire();                                    // Destructor
      int attack(Character *defender);          // Attack function
      void defend(int attack);                  // Defend function
};

#endif
