/*********************************************************************
** Program name:  Program 2 (Tiger.cpp)
** Author:        Aaron Nesbit
** Date:          10/21/19
** Description:   This is the implementation file for the class Tiger
*********************************************************************/

#include "Tiger.hpp"

/*
* Summary: Default constructor
*/
Tiger::Tiger() : Animal()
{
   cost = 10000;
   base_food_cost = 50;
   payoff = cost * .2;
   type = "Tiger";
}

/*
* Summary: Constructor with age
* Parameters: Tiger age
*/
Tiger::Tiger(int a) : Animal()
{
   cost = 10000;
   base_food_cost = 50;
   payoff = cost * .2;
   type = "Tiger";
   age = 0;
}
