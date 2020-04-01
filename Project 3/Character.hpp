/*********************************************************************
** Program name:  Project 3 (Character.hpp)
** Author:        Aaron Nesbit
** Date:          10/30/19
** Desciption:    This is the header file for the abstract class
**                Character.
*********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

using std::string;

class Character
{
   protected:
      int strength_points;
      int armor;
      
   public:
      Character();                   // Constructor
      virtual ~Character();          // Virtual destructor
      virtual int attack() = 0;      // Pure virtual attack function
      virtual void defend(int) = 0;  // Pure virtual defend function
      int get_armor();               // Armor getter function
      int get_strength_points();     // Strength point getter function
      virtual string get_type() = 0; // Pure virtual character type getter
};

#endif
