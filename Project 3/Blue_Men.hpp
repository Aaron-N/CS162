/*********************************************************************
** Program name:  Project 3 (Blue_Men.hpp)
** Author:        Aaron Nesbit
** Date:          10/30/19
** Description:   This is the header file for the class Blue_Men.
*********************************************************************/

#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP

#include "Character.hpp"

using std::string;

class Blue_Men : public Character
{
   public:
      Blue_Men();            // Constructor
      int attack();          // Attacking function
      void defend(int a);    // Defending function
      string get_type();     // Character type getter
};

#endif
