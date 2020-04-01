/*********************************************************************
** Program name:  Project 2 (Turtle.hpp)
** Author:        Aaron Nesbit
** Date:          10/21/19
** Description:   This is the header file for the class Turtle
*********************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"

class Turtle : public Animal
{
   public:
      Turtle();                // Default constructor
      Turtle(int);             // Constructor with age
};

#endif
