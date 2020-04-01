/*********************************************************************
** Program name:  Lab 3 (Die.cpp)
** Author:        Aaron Nesbit
** Date:          10/16/19
** Description:   This is the implementation file for the class Die
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include "Die.hpp"

using std::string;

/*
* Summary:   Constructor
* Parameter: Takes int parameter to set how many sides die has
*/
Die::Die(int sides)
{
   N = sides;
   die_type = "normal";
}


/*
* Summary:   Default Destructor
*/
Die::~Die(){}


/*
* Summary:  get_die_sides() - number of die sides getter function
* Returns:  the number of sides the die has
*/
int Die::get_die_sides()
{
   return N;
}


/*
* Summary:  get_die_type() - die type getter function
* Returns:  whether the die is normal or loaded
*/
string Die::get_die_type()
{
   return die_type;
}


/*
* Summary:  roll() - rolls a random number between 1 and the number of
*           sides the die has.
* Returns:  The die roll result
*/
int Die::roll()
{
   return (rand() % N + 1);
}
