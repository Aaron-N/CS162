/*********************************************************************
** Program name:  Project 4 (Vampire.cpp)
** Author:        Aaron Nesbit
** Date:          11/21/19
** Description:   This is the implementation file for the class Vampire
*********************************************************************/

#include "Vampire.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;

/*
* Constructor
*/
Vampire::Vampire() : Character("Vampire", 1, 18, 1)
{
   // Dice quantities and # of sides declared
   attackRoll.numDice = 1;
   attackRoll.numDiceSides = 12;
   defenseRoll.numDice = 1;
   defenseRoll.numDiceSides = 6;

   // Array for attack dice created
   attackDice = new Die*[attackRoll.numDice];
   for(int i = 0; i < attackRoll.numDice; i++)
   {
      attackDice[i] = new Die(attackRoll.numDiceSides);
   }

   // Array for defense dice created
   defenseDice = new Die*[defenseRoll.numDice];
   for(int i = 0; i < defenseRoll.numDice; i++)
   {
      defenseDice[i] = new Die(defenseRoll.numDiceSides);
   }
}


/*
* Summary: Destructor
*/ 
Vampire::~Vampire()
{
   for(int i = 0; i < attackRoll.numDice; i++)
   {
      delete attackDice[i];  // Clear attack dice array
   }
   delete [] attackDice;     // Delete attack dice array
   
   for(int i = 0; i < defenseRoll.numDice; i++)
   {
      delete defenseDice[i]; // Clear defense dice array
   }
   delete [] defenseDice;    // Delete defense dice array
}


/*
* Summary:   attack() - function for calculating fighter's attack roll
* Parameter: pointer to Character object
* Returns:   attack roll total
*/
int Vampire::attack(Character *defender)
{
   int attackTotal = 0;
   int currentRoll = 0;
   for(int i = 0; i < attackRoll.numDice; i++)
   {
      currentRoll  = attackDice[i]->roll();
      attackTotal += currentRoll;
   }
   return attackTotal;
}


/*
* Summary:   defend() - function for calculating fighter's defense roll
*            and strength after being attacked
* Parameter: opponent's attack roll
*/
void Vampire::defend(int attackScore)
{
   // Determine if Vampire charms opponent into not attacking
   int charmed = rand() % 2;
   if(charmed == 1)
   {
      // No damage inflicted
   }
   else
   {
      int defenseTotal = 0;
      int currentRoll = 0;
      for (int i = 0; i < defenseRoll.numDice; i++)
      {
         currentRoll  = defenseDice[i]->roll();
         defenseTotal += currentRoll;
      }

      // Calculate damage taken and adjust strength
      int damage = max(attackScore - defenseTotal - this->getArmor(), 0);
      int newStrength = this->getStrength() - damage;
      this->setStrength(newStrength);
   }
}
