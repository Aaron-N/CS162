/*********************************************************************
** Program name:  Project 4 (Medusa.hpp)
** Author:        Aaron Nesbit
** Date:          11/19/19
** Description:   This is the header file for the class Medusa
*********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa: public Character
{
   public:
      Medusa();                                      // Constructor
      ~Medusa();                                      // Destructor
      int attack(Character *defender);           // Attack function
      void defend(int attack);                   // Defend function
};

#endif
