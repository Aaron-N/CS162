/*********************************************************************
** Program name:  Project 4 (Die.cpp)
** Author:        Aaron Nesbit
** Date:          11/20/19
** Description:   This is the implementation file for the class Die
*********************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Die.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;


/*
* Summary: Constructor
*/
Die::Die(int sides)
{
   rollValue = -1;      // Roll value initialized
   setSides(sides);     // Set die sides
}


/*
* Summary: Destructor
*/
Die::~Die(){}


/*
* Summary:   setSides() - die side setter function
* Parameter: number of die sides
*/
void Die::setSides(int sides)
{
   this->sides = sides;
}


/*
* Summary: getSides() - die side getter function
* Returns: number of die sides
*/
int Die::getSides()
{
   return sides;
}


/*
* Summary: getRollValue() - roll value getter function
* Returns: die roll value
*/
int Die::getRollValue()
{
   return rollValue;
}


/*
* Summary: roll() -  rolls a die and returns the result
* Returns: die roll value
*/
int Die::roll()
{
   rollValue = rand() % getSides() + 1;
   return rollValue;
}
