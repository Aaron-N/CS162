/*********************************************************************
** Program name:  Project 3 (Barbarian.hpp)
** Author:        Aaron Nesbit
** Date:          10/30/19
** Description:   This is the header file for the class Barbarian.
*********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

using std::string;

class Barbarian : public Character    
{
   public:
      Barbarian();                // Constructor
      int attack();               // Attacking function
      void defend(int a);         // Defending function
      string get_type();          // Character type getter
};

#endif
