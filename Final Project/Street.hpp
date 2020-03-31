/*********************************************************************
** Program name:  Final Project (Street.hpp)
** Author:        Aaron Nesbit
** Date:          12/2/19
** Description:   This is the header file for the class Street
*********************************************************************/

#ifndef STREET_HPP
#define STREET_HPP

#include "Space.hpp"

class Street : public Space
{
   private:
      Space *up;                                 // Private variables
      Space *down;                               // and pointers declared
      Space *left;
      Space *right;
      int place_number;

   public:
      Street();                                  // Constructor
      virtual void description();                // Place description
      virtual Space* place_options(Butthead *);  // Player options in place
      virtual void set_up(Space *);              // 'Up' pointer setter
      virtual void set_down(Space *);            // 'Down' pointer setter
      virtual void set_left(Space *);            // 'Left' pointer setter
      virtual void set_right(Space *);           // 'Right' pointer setter
      virtual int get_place_number();            // Place number getter
};

#endif
