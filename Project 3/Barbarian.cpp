/*********************************************************************
** Project name:  Project 3 (Barbarian.cpp)
** Author:        Aaron Nesbit
** Date:          10/30/19
** Description:   This is the source file for the class Barbarian
*********************************************************************/

#include <iostream>
#include "Barbarian.hpp"

using std::cout;
using std::endl;
using std::string;

/*
* Summary: Constructor
*/
Barbarian::Barbarian() : Character()
{
   this->strength_points = 12;         // Strength points set
   this->armor = 0;                    // Armor value set
}


/*
* Summary: attack() - rolls 2 6-sided dice for attacking
* Returns: attacking rolls total
*/
int Barbarian::attack()
{
   int roll_1 = (rand() % 6 + 1);      // Die 1 roll
   int roll_2 = (rand() % 6 + 1);      // Die 2 roll
   
   return roll_1 + roll_2;             // Attack value returned
}


/*
* Summary: defend() - rolls 2 6-sided dice for defending and runs
*          calculations to determine damage taken
*/
void Barbarian::defend(int a)
{
   int roll_1 = (rand() % 6 + 1);      // Die 1 roll
   int roll_2 = (rand() % 6 + 1);      // Die 2 roll
   int roll_total = roll_1 + roll_2;   // Total defense roll

   cout << "The Barbarian rolled a defense value of " << roll_total
        << endl;

   // Damage = attack value - defense roll - armor
   int damage = a - roll_total - armor;

   // Damage results
   if(damage <= 0)      // No damage taken
   {
      damage = 0;       // Damage set to 0 if less than zero
      cout << "The Barbarian defended and took no damage!" << endl;
   }
   else                 // Damage taken
   {
      cout << "The Barbarian's defense and armor reduced damage to "
           << damage << endl;
      strength_points -= damage;       // Strength points updated
      if(strength_points < 0)
      {
         strength_points =0; // If strength points negative, set to 0
      }
   }   
}


/*
* Summary: get_type() - returns that this character is a Barbarian
* Returns: character type
*/
string Barbarian::get_type()
{
   return "Barbarian";
}

