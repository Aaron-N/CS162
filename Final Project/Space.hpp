/*********************************************************************
** Program name:  Final Project (Space.hpp)
** Author:        Aaron Nesbit
** Date:          12/1/19
** Description:   This is the header file for the abstract class Space
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include "Butthead.hpp"
#include "input_validation.hpp"

class Space
{
   private:
      Space *up;                                 // Private variables
      Space *down;                               // and pointers declared
      Space *left;
      Space *right;
      int place_number;

   public:
      Space();                                   // Constructor
      virtual ~Space();                          // Virtual destructor
      virtual void description() = 0;         // Pure virtual description
      virtual Space *place_options(Butthead *) = 0; // Pure virtual options
      virtual void set_up(Space *) = 0;   // Pure virtual up pointer set
      virtual void set_down(Space *) = 0; // Pure virtual down pointer set 
      virtual void set_left(Space *) = 0; // Pure virtual left pointer set
      virtual void set_right(Space *) = 0;// Pure virtual right pointer set 
      virtual int get_place_number() = 0; // Pure virtual place num getter
};

#endif
