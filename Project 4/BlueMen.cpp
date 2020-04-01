/*********************************************************************
** Program name:  Project 4 (BlueMen.cpp)
** Author:        Aaron Nesbit
** Date:          11/20/19
** Description:   This is the implementation file for the class BlueMen
*********************************************************************/

#include "BlueMen.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;

/*
* Summary: Constructor
*/
BlueMen::BlueMen() : Character("Blue Men", 3, 12, 1)
{
   // Dice quantities and # of sides declared
   attackRoll.numDice = 2;
   attackRoll.numDiceSides = 10; 
   defenseRoll.numDice = 3;
   defenseRoll.numDiceSides = 6;

   // Array for attack dice created
   attackDice = new Die*[attackRoll.numDice];
   for (int i = 0; i < attackRoll.numDice; i++)
   {
      attackDice[i] = new Die(attackRoll.numDiceSides);
   }

   // Array for defense dice created
   defenseDice = new Die*[defenseRoll.numDice];
   for (int i = 0; i < defenseRoll.numDice; i++)
   {
      defenseDice[i] = new Die(defenseRoll.numDiceSides);
   }
}


/*
* Summary: Destructor
*/
BlueMen::~BlueMen()
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
int BlueMen::attack(Character *defender)
{
   int attackTotal = 0;
   int currentRoll = 0;
   for (int i = 0; i < attackRoll.numDice; i++)
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
void BlueMen::defend(int attackScore)
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


/*
* Summary: setStrength() - function for changing defense dice quantities
*          based on current strength points of the fighter
* Parameter: strength points of the fighter          
*/ 
void BlueMen::setStrength(int strength)
{
   // Verify number of defense dice to be used
   Character::setStrength(strength);
   int newDiceNum = 0;
   if(strength > 8 && strength <= 12)      // Strength points from 9-12
   {
      newDiceNum = 3;                      // 3 defense dice used
   }
   else if(strength > 4 && strength <= 8)  // Strength points from 5-8 
   {
      newDiceNum = 2;                      // 2 defense dice used
   }
   else if(strength > 0 && strength <= 4)  // Strength points from 1-4
   {
      newDiceNum = 1;                      // 1 defense die used
   }

   // Create new defense dice array if quantities have changed
   if(newDiceNum != defenseRoll.numDice)
   {
      for(int i = 0; i < defenseRoll.numDice; i++)
      {
         delete defenseDice[i];   // Clear defense dice array
      }
      delete [] defenseDice;      // Delete defense dice array

      // Update quantity of defense dice
      defenseRoll.numDice = newDiceNum;

      // Create new array
      defenseDice = new Die*[defenseRoll.numDice];
      for(int i = 0; i < defenseRoll.numDice; i++)
      {
         defenseDice[i] = new Die(defenseRoll.numDiceSides);
      }
   }
}
