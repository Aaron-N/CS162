/*********************************************************************
** Program name:  Project 4 (Medusa.cpp)
** Author:        Aaron Nesbit
** Date:          11/19/19
** Description:   This is the implementation file for the class Medusa
*********************************************************************/

#include "Medusa.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;


/*
* Summary: Constructor
*/
Medusa::Medusa() : Character("Medusa", 3, 8, 1)
{
   // Dice quantities and # of sides declared
   attackRoll.numDice = 2;
   attackRoll.numDiceSides = 6;
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
Medusa::~Medusa()
{
   for(int i = 0; i < attackRoll.numDice; i++)
   {
      delete attackDice[i];  // Clear attack dice array
   }
   delete [] attackDice;     // Delete attack dice array
   
   for (int i = 0; i < defenseRoll.numDice; i++)
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
int Medusa::attack(Character *defender)
{
   int attackTotal = 0;
   int currentRoll = 0;
   for (int i = 0; i < attackRoll.numDice; i++)
   {
      currentRoll  = attackDice[i]->roll();
      attackTotal += currentRoll;
   }
   if (attackTotal == 12)    // Medusa uses Glare attack!
   {
      attackTotal = 1000;
   }
   return attackTotal;
}


/*
* Summary:   defend() - function for calculating fighter's defense roll
*            and strength after being attacked
* Parameter: opponent's attack roll
*/
void Medusa::defend(int attackScore)
{
   int defenseTotal = 0;
   int currentRoll = 0;
   for(int i = 0; i < defenseRoll.numDice; i++)
   {
      currentRoll  = defenseDice[i]->roll();
      defenseTotal += currentRoll;
   }

   // Calculate damage taken and adjust strength
   int damage = max(attackScore - defenseTotal - this->getArmor(), 0);
   int newStrength = this->getStrength() - damage;
   this->setStrength(newStrength);
}
