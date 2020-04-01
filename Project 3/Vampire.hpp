/*********************************************************************
** Program name:  Project 3 (Vampire.hpp)
** Author:        Aaron Nesbit
** Date:          11/7/19
** Description:   This is the header file for the class Vampire
*********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

using std::string;

class Vampire : public Character
{
   public:
      Vampire();             // Constructor
      int attack();          // Attacking function
      void defend(int a);    // Defending function
      string get_type();     // Character type getter
};

#endif
