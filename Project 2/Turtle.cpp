/*********************************************************************
** Program name:  Project 2 (Turtle.cpp)
** Author:        Aaron Nesbit
** Date:          10/21/19
** Description:   This is the implementation file for the class Turtle
*********************************************************************/

#include "Turtle.hpp"

/*
* Summary: Default constructor
*/
Turtle::Turtle() : Animal()
{
   cost = 100;
   number_of_babies = 10;
   base_food_cost = 5;
   payoff = cost * .05;
   type = "Turtle";
}

/*
* Summary:    Constructor with age
* Parameters: Constructor with age
*/
Turtle::Turtle(int a) : Animal()
{
   cost = 100;
   number_of_babies: 10;
   base_food_cost = 5;
   payoff = cost * .05;
   type = "Turtle";
   age = 0;
} 
