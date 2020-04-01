/*********************************************************************
** Program name:  Program 2 (Penguin.cpp)
** Author:        Aaron Nesbit
** Date:          10/21/19
** Description:   This is the implementation file for the class Penguin
*********************************************************************/

#include "Penguin.hpp"

/*
* Summary:  Default constructor
*/
Penguin::Penguin() : Animal()
{
   cost = 1000;
   number_of_babies = 5;
   payoff = cost * .1;
   type = "Penguin";
}

/*
* Summary:    Constructor with age
* Parameters: Penguin age
*/
Penguin::Penguin(int a) : Animal()
{
   cost = 1000;
   number_of_babies = 5;
   payoff = cost * .1;
   type = "Penguin";
   age = 0;
}
