/*********************************************************************
** Program name:  Final Project (Buttheads_House.hpp)
** Author:        Aaron Nesbit
** Date:          12/2/19
** Description:   This is the header file for the class Buttheads_House
*********************************************************************/

#ifndef BUTTHEADS_HOUSE_HPP
#define BUTTHEADS_HOUSE_HPP

#include "Space.hpp"

class Buttheads_House : public Space
{
   private:
      Space *up;                                 // Private variables
      Space *down;                               // and pointers declared
      Space *left;
      Space *right;
      int place_number;

   public:
      Buttheads_House();                         // Constructor
      virtual void description();                // Place description
      virtual Space* place_options(Butthead *);  // Player options in place
      virtual void set_up(Space *);              // 'Up' pointer setter
      virtual void set_down(Space *);            // 'Down' pointer setter
      virtual void set_left(Space *);            // 'Left' pointer setter
      virtual void set_right(Space *);           // 'Right' pointer setter
      virtual int get_place_number();            // Place number getter
};

#endif
