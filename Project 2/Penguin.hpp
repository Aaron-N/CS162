/*********************************************************************
** Program name:  Project 2 (Penguin.hpp)
** Author:        Aaron Nesbit
** Date:          10/21/19
** Description:   This is the header file for the class Penguin
*********************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"

class Penguin : public Animal
{
   public:
      Penguin();            // Default constructor
      Penguin(int);         // Constructor with age
};

#endif
