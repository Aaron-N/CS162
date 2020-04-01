/*********************************************************************
** Program name:  Project 3 (Medusa.hpp)
** Author:        Aaron Nesbit
** Date:          11/4/19
** Description:   This is the header file for the class Medusa
*********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

using std::string;

class Medusa : public Character
{
   public:
      Medusa();              // Constructor
      int attack();          // Attacking function
      void defend(int a);    // Defending function
      string get_type();     // Character type getter
};

#endif
