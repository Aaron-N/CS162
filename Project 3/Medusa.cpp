/*********************************************************************
** Program name:  Project 3 (Medusa.cpp)
** Author:        Aaron Nesbit
** Date:          11/4/19
** Description:   This is the implementation file for the derived 
**                class Medusa
*********************************************************************/

#include <iostream>
#include "Medusa.hpp"

using std::cout;
using std::endl;
using std::string;

/*
* Summary: Constructor
*/
Medusa::Medusa() : Character()
{
   this->strength_points = 8;
   this->armor = 3;
}


/*
* Summary: attack() - rolls 2 6-sided die for attacking. If a 12 is
*          rolled, Medusa uses her Glare attack and her opponent is
*          turned to stone
* Returns: attacking rolls total
*/
int Medusa::attack()
{
   int roll_1 = (rand() % 6 + 1);      // Die 1 roll
   int roll_2 = (rand() % 6 + 1);      // Die 2 roll
   int roll_total = roll_1 + roll_2;   // Total attack roll
     
   // If a 12 is rolled, Medusa uses Glare attack
   if(roll_total == 12)
   {
      cout << "Medusa uses her Glare attack!" << endl;
      return 100;                      // Medusa kills opponent
   }

   return roll_total;                  // Returns attacking rolls
}


/*
* Summary: defend() - rolls 1 6-sided die for defending and runs
*          calculations to determine damage taken
*/
void Medusa::defend(int a)
{
   int roll = (rand() % 6 + 1);      // Die roll

   cout << "Medusa rolled a defense value of " << roll << endl;

   // Damage = opponent attack value - defense roll - armor
   int damage = a - roll - armor;

   // Damage results
   if(damage <= 0)      // No damage taken
   {
      damage = 0;       // Damage set to 0 if less than zero
      cout << "Medusa defended and took no damage!" << endl;
   }
   else                 // Damage taken
   {
      cout << "Medusa's defense and armor reduced damage to "
           << damage << endl;
      strength_points -= damage;       // Strength points updated
      if(strength_points < 0)
      {
         strength_points = 0;   // If strength points negative, set to 0
      }
   }
}


/*
* Summary: get_type() - returns that this character is Medusa
* Returns: character type
*/
string Medusa::get_type()
{
   return "Medusa";
}

