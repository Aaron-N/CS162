/*********************************************************************
** Program name:  Project 2 (Animal.cpp)
** Author:        Aaron Nesbit
** Date:          10/21/19
** Description:   This is the implementation file for the class Animal
*********************************************************************/

#include "Animal.hpp"

/*
* Summary: Default constructor
*/
Animal::Animal()
{
   age = 1;
   cost = 0;
   number_of_babies = 1;
   base_food_cost = 10;
   payoff = 0;
   type = "Generic Animal";
}

/*
* Summary:    Animal contructor with age
* Parameters: Animal age
*/
Animal::Animal(int a)
{
   age = a;
}

/*
* Summary: Destructor
*/
Animal::~Animal(){}

/*
* Summary: get_age() - animal age getter function
* Returns: Age of animal
*/
int Animal::get_age()
{
   return age;
}

/*
* Summary: get_cost() - animal cost getter function
* Returns: Cost of animal
*/
int Animal::get_cost()
{
   return cost;
}

/*
* Summary: get_number_of_babies() - # of babies getter function
* Returns: # of babies animal can have
*/
int Animal::get_number_of_babies()
{
   return number_of_babies;
}

/*
* Summary: get_base_food_cost() - base food cost getter function
* Returns: Base food cost for animal
*/
int Animal::get_base_food_cost()
{
   return base_food_cost;
}

/*
* Summary: get_payoff() - payoff getter function
* Returns: payoff of animal
*/
int Animal::get_payoff()
{
   return payoff;
}

/*
* Summary: get_type() - animal type getter function
* Returns: type of animal
*/
string Animal::get_type()
{
   return type;
}

/*
* Summary - age_one_day() - makes all animals one day older
*/
void Animal::age_one_day()
{
   age++;
}
