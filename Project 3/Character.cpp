/*********************************************************************
** Program name:  Project 3 (Character.cpp)
** Author:        Aaron Nesbit
** Date:          10/30/19
** Description:   This is the source file for the abstract class
**                Character
*********************************************************************/

#include "Character.hpp"

/*
* Summary: Default constructor
*/
Character::Character(){}


/*
* Summary: Destructor
*/
Character::~Character(){}


/*
* Summary: get_strength_points() - returns a player's strength points
* Returns: strength points
*/
int Character::get_strength_points()
{
   return strength_points;
}


/*
* Summary: get_armor() - return's a player's armor points
* Returns: armor points
*/
int Character::get_armor()
{
   return armor;
}
