/*********************************************************************
** Program name:  Project 4 (Character.cpp)
** Author:        Aaron Nesbit
** Date:          11/18/19
** Description:   This is the implementation file for the class Character
*********************************************************************/

#include "Character.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
* Summary: Constructor
*/
Character::Character(string charType, int armor, int strength, int numLives){
   this->charType = charType;
   this->name = charType;
   this->armor = armor;
   this->currentStrength = strength;
   this->startStrength = strength;
   this->numLives = numLives;
   this->isDead = false;
   this->currentLife = 0;
}


/*
* Summary: Destructor
*/
Character::~Character(){}


/*
* Summary: getArmor() - armor getter function
* Returns: character's armor points
*/
int Character::getArmor()
{
   return armor;
}


/*
* Summary: getStrength() - strength points getter function
* Returns: character's strength points
*/
int Character::getStrength()
{
   return currentStrength;
}


/*
* Summary:   setStrength() - strength getter function
* Parameter: character's strength
*/
void Character::setStrength(int strength)
{
   this->currentStrength = strength;
   if (strength <= 0)
   {
      // Increment the current life
      currentLife++;
      // Check to see if they're out of lives
      if(currentLife == numLives)
      {
         isDead = true;
      }
      else
      {
         resetStrength();
      }
   }
}


/*
* Summary: getAttack() - attack roll getter function
* Returns: character's attack roll
*/
roll_t Character::getAttack()
{
   return attackRoll;
}


/*
* Summary: getDefense() - defense roll getter function
* Returns: character's defense roll
*/
roll_t Character::getDefense()
{
   return defenseRoll;
}


/*
* Summary: getType() - character type getter function
* Returns: character's type
*/
string Character::getType()
{
   return charType;
}


/*
* Summary: isAlive() - returns whether character is alive or dead
* Returns: live or dead
*/
bool Character::isAlive()
{
   return !isDead;
}


/*
* Summary: resetStrength() - if character revives, strength is reset
*/
void Character::resetStrength()
{
   setStrength(startStrength);
}


/*
* Summary: getName() - character name getter function
* Returns: character's name
*/
string Character::getName()
{
   return name;
}


/*
* Summary: setName() - character name setter function
*/
void Character::setName(string name)
{
   this->name = name;
}


/*
* Summary: getStrengthCapacity() - character strength getter function
* Returns: character's strength
*/ 
int Character::getStrengthCapacity()
{
   return startStrength;
}


/*
* Summary: recover() - character recovers a random amount of strength
*          points if they win fight
*/
void Character::recover()
{
   int RecoveredStrength = 
     rand() % (getStrengthCapacity() + 1 - getStrength()) + getStrength();
   setStrength(RecoveredStrength);
}
