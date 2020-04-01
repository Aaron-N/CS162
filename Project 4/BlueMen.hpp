/*********************************************************************
** Program name:  Project 4 (BlueMen.hpp)
** Author:        Aaron Nesbit
** Date:          11/20/19
** Description:   This is the header file for the class BlueMen
*********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"

class BlueMen: public Character
{
   public:
      BlueMen();                        // Constructor
      ~BlueMen();                       // Destructor
      int attack(Character *defender);  // Attack function
      void defend(int attack);          // Defense function
      void setStrength(int strength);   // Strength adjustment function
};

#endif
