/*********************************************************************
** Program name:  Lab 3 (LoadedDie.cpp)
** Author:        Aaron Nesbit
** Date:          10/17/19
** Description:   This is the implementation file for the class
**                LoadedDie. It inherits from the class Die but
**                overrides the roll function to roll higher
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LoadedDie.hpp"

/*
* Summary:    Loaded die constructor
*             Inherits attributes from Die class
* Parameters: Takes int parameter to set how many sides die has
*/ 
LoadedDie::LoadedDie(int sides) : Die(sides)
{
   die_type = "loaded";
}


/*
* Summary:  Overload function that rolls a biased random number between
*           1 and the number of sides that the die has
* Returns:  The biased die roll result
*/
int LoadedDie::roll()
{
   if((rand() % 2 + 1) == 1) // Random roll checked
   {
      return(rand() % N + 1); // If condition met, returns normal roll
   }
   return N; // If condition not met, returns max possible roll result
}

