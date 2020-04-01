/*********************************************************************
** Program name:  Project 3 (Harry_Potter.hpp)
** Author:        Aaron Nesbit
** Date:          11/4/19
** Description:   This is the header file for the class Harry_Potter
*********************************************************************/

#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP

#include "Character.hpp"

using std::string;

class Harry_Potter : public Character
{
   private:
      int death_count = 0;

   public:
      Harry_Potter();                  // Constructor
      int attack();                    // Attacking function
      void defend(int a);              // Defending function
      string get_type();               // Character type getter
};

#endif
