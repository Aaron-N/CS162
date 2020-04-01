/*********************************************************************
** Program name:  Project 4 (Character.hpp)
** Author:        Aaron Nesbit
** Date:          11/18/19
** Description:   This is the header file for the class Character
*********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include "Die.hpp"

using std::string;

struct roll_t
{                                 // Die struct
   int numDice;
   int numDiceSides;
};

class Character
{
   protected:                     // Variables declared
      string charType;
      string name;
      roll_t attackRoll;
      roll_t defenseRoll;
      int armor;
      int currentStrength;
      int startStrength;
      int numLives;
      int currentLife;
      bool isDead;
      Die** attackDice;
      Die** defenseDice;

   public:
      Character(string charType, int armor = 0,      
                int strength = 12, int numLives = 1);      // Constructor
      virtual ~Character();                                 // Destructor
      virtual int attack(Character *defender) = 0; // Pure virtual attack
      virtual void defend(int attackScore) = 0;    // Pure virtual defend
      virtual void setStrength(int strength);  // Virtual strength setter
      virtual void resetStrength();             // Virtual strength reset
      int getArmor();                            // Armor getter function
      int getStrength();                      // Strength getter function
      int getStrengthCapacity();          // Max strength getter function
      void recover();                       // Strength recovery function
      bool isAlive();                   // Character alive check function
      roll_t getAttack();                  // Attack roll getter function
      roll_t getDefense();                // Defense roll getter function
      string getType();                           // Type getter function
      string getName();                           // Name getter function
      void setName(string name);                  // Name setter function
};

#endif 
