/*********************************************************************
** Program name:  Lab 3 (Die.hpp)
** Author:        Aaron Nesbit
** Date:          10/15/19
Description:      This is the header file the class Die
*********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

#include <string>

using std::string;

class Die
{
   public:
      Die(int);                 // Constructor
      ~Die();                   // Destructor
      int get_die_sides();      // # of die sides getter function
      string get_die_type();    // die type getter function
      virtual int roll();       // die roll function
                                // virtual so derived LoadedDie class
                                // can overload it with biased version

   protected:
      int N;                    // variable for # of sides of die
      string die_type;          // variable for die type selected
};

#endif
