/*********************************************************************
** Program name:  Project 4 (Die.hpp)
** Author:        Aaron Nesbit
** Date:          11/20/19
** Description:   This is the header file for the class Die
*********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die
{
   protected:
      int sides;                          // Die sides variable
      int rollValue;                      // Roll value vriable

   public:
      Die(int sides = 6);                        // Constructor
      virtual ~Die();                     // Virtual destructor
      virtual int roll();          // virtual die roll function
      int getSides();              // Die sides getter function
      void setSides(int sides);    // Die sides setter function
      int getRollValue();         // Roll value getter function
};

#endif 
