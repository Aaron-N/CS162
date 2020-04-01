/*********************************************************************
** Program name:  Project 2 (Tiger.hpp)
** Author:        Aaron Nesbit
** Date:          10/21/19
** Description:   This is the headed file for the class Tiger
*********************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

class Tiger : public Animal
{
   public:
      Tiger();                     // Default constructor
      Tiger(int);                  // Constructor with age
};

#endif
