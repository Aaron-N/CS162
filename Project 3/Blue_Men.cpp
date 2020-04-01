/*********************************************************************
** Project name:  Project 3 (Blue_Men.cpp)
** Author:        Aaron Nesbit
** Date:          10/30/19
** Description:   This is the source file for the class Blue_Men.
*********************************************************************/

#include <iostream>
#include "Blue_Men.hpp"

using std::cout;
using std::endl;
using std::string;

/*
* Summary: Constructor
*/
Blue_Men::Blue_Men() : Character()
{
   this->strength_points = 12;
   this->armor = 3;
}


/*
* Summary: attack() - rolls 2 10-sided dice for attacking
* Returns: attacking rolls total
*/
int Blue_Men::attack()
{
   int roll_1 = (rand() % 10 + 1);
   int roll_2 = (rand() % 10 + 1);
   
   return roll_1 + roll_2;
}


/*
* Summary: defend() - rolls up to 3 6-sided dice for defending. For
*          every 4 strength points lost, the defense roll uses one
*          less die. Calculations to determine damage taken then made. 
*/
void Blue_Men::defend(int a)
{
   int roll_1;
   int roll_2;
   int roll_3;
   int roll_total;

   if(strength_points <= 4 && strength_points > 0)      // 1 defense die
   {
      roll_total = (rand() % 6 + 1);             // Total defense roll
   }
   else if(strength_points <= 8 && strength_points > 4) // 2 defense dice
   {
      roll_1 = (rand() % 6 + 1);
      roll_2 = (rand() % 6 + 1);
      roll_total = roll_1 + roll_2;              // Total defense roll
   }
   else                                                 // 3 defense dice
   {
      roll_1 = (rand() % 6 + 1);
      roll_2 = (rand() % 6 + 1);
      roll_3 = (rand() % 6 + 1);
      roll_total = roll_1 + roll_2 + roll_3;     // Total defense roll
   }
   
   cout << "The Blue Men rolled a defense value of " << roll_total << endl;

   // Damage = attack value - defense roll total - armor
   int damage = a - roll_total - armor;

   // Damage results
   if(damage <= 0)      // No damage taken
   {
      damage = 0;       // damage set to 0 if less than zero
      cout << "The Blue Men defended and took no damage!" << endl;
   }
   else
   {
      cout << "The Blue Men's defense and armor reduced damage to "
           << damage << endl;
      strength_points -= damage;
      if(strength_points < 0)
      {
         strength_points = 0; // If strength points negative, set to 0
      }
   }
}


/*
* Summary: get_type() - gets the type of character this fighter is
* Returns: character type
*/
string Blue_Men::get_type()
{
   return "Blue Men";
}

