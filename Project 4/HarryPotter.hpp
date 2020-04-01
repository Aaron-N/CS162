/*********************************************************************
** Program name:  Project 4 (HarryPotter.hpp)
** Author:        Aaron Nesbit
** Date:          11/19/19
** Description:   This is the header file for the class HarryPotter
*********************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter: public Character
{
   public:
      HarryPotter();                                 // Constructor
      ~HarryPotter();                                 // Destructor
      int attack(Character *defender);           // Attack function
      void defend(int attack);                   // Defend function
      void resetStrength();              // Strength reset function
};

#endif
