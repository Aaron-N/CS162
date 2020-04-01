/*********************************************************************
** Program name:  Project 3 (Harry_Potter.cpp)
** Author:        Aaron Nesbit
** Date:          11/4/19
** Description:   This is the source file for the class Harry_Potter
*********************************************************************/

#include <iostream>
#include "Harry_Potter.hpp"

using std::cout;
using std::endl;

/*
* Summary: Constructor
*/
Harry_Potter::Harry_Potter() : Character()
{
   this->strength_points = 10;
   this->armor = 0;
}


/*
* Summary: attack() - rolls 2 6-sided dice for attacking
* Returns: attacking rolls total
*/
int Harry_Potter::attack()
{
   int roll_1 = (rand() % 6 + 1);      // Die 1 roll
   int roll_2 = (rand() % 6 + 1);      // Die 2 roll

   return roll_1 + roll_2;             // Attack value returned
}


/*
* Summary: defend() - rolls 2 6-sided dice for defending and runs
*          calculations to determine damage taken. When Harry dies
*          the first time, he is revived by the power of Hogwarts
*          and his strength points are set to 20. If he dies again,
*          he is dead forever
*/
void Harry_Potter::defend(int a)
{
   int roll_1 = (rand() % 6 + 1);      // Die 1 roll
   int roll_2 = (rand() % 6 + 1);      // Die 2 roll
   int roll_total = roll_1 + roll_2;   // Total defense roll

   cout << "Harry Potter rolled a defense value of " << roll_total
        << endl;

   // Damage = attack value - defense roll - armor
   int damage = a - roll_total - armor;

   // Damage results
   if(damage <= 0)      // No damage taken
   {
      damage = 0;       // Damage set to 0 is less than zero
      cout << "Harry Potter defended and took no damage!" << endl;
   }
   else                 // Damage taken
   {
      cout << "Harry Potter's defense and armor reduced damage to "
           << damage << endl;
      strength_points -= damage;       // Strength points updated
      if(strength_points < 0)
      {
         strength_points = 0; // If strength points negative, set to 0
      } 
   }

   // If Harry's strength points are less than or equal to zero and he
   // has not died yet, he is revived by Hogwarts
   if(strength_points == 0 && death_count < 1)
   {
      cout << "Harry Potter dies, but is revived by the power of Hogwarts!"
           << endl << "He comes back even stronger!" << endl;
      this->strength_points = 20;     // Strength points reset to 20
      death_count = 1;                // Death count increased to 1
   }
}


/*
* Summary: get_type() - returns that this character is Harry Potter
* Returns: character type
*/
string Harry_Potter::get_type()
{
   return "Harry Potter";
}
