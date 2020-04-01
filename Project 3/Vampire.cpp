/*********************************************************************
** Program name:  Project 3 (Vampire.cpp)
** Author:        Aaron Nesbit
** Date:          11/7/19
** Description:   This is the implementation file for the class Vampire
*********************************************************************/

#include <iostream>
#include "Vampire.hpp"

using std::cout;
using std::endl;
using std::string;

/*
* Summary: Constructor
*/
Vampire::Vampire() : Character()
{
   this->strength_points = 18;
   this->armor = 1;
}


/*
* Summary: attack() - rolls 1 12-sided die for attacking
* Returns: attacking roll total
*/
int Vampire::attack()
{
   int roll = (rand() % 12 + 1);       // Attack roll

   return roll;
}


/*
* Summary: defend() - rolls a 2-sided die to determine if the Vampire
*          uses Charm against opponent to prevent attack, and rolls a
*          6-sided die for defending and runs calculations to determine
*          damage taken
*/
void Vampire::defend(int a)
{
   int charm = (rand() % 2);           // Charm roll
   int roll = (rand() % 6) + 1;        // Defend roll
   int damage;

   // If Vampire uses charm, opponent attack is neutralized
   if(charm == 1)
   {
      cout << "Vampire used Charm and was not attacked!" << endl;
      damage = 0;
   }
   else
   {
      cout << "Vampire rolled a defense value of " << roll << endl;

      // Damage = opponent attack value - defense roll - armor
      damage = a - roll - armor;

      if(damage <= 0)   // No damage taken
      {
         damage = 0;    // Damage set to 0 if less than zero
         cout << "Vampire defended and took no damage!" << endl;
      }
      else              // Damage taken
      {
         cout << "Vampire's defense and armor reduced inflicted "
              << "damage to " << damage << endl;
         strength_points -= damage;    // Strength points updated
         if(strength_points < 0)
         {
            strength_points = 0; // If strength points negative, set to 0
         }
      }
   }
}


/*
* Summary: get_type() - returns that this character is a Vampire
* Returns: character type
*/
string Vampire::get_type()
{
   return "Vampire";
}

