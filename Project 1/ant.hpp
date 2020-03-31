/*********************************************************************
** Program name:   Project 1 (ant.hpp)
** Author:         Aaron Nesbit
** Date:           10/7/19
** Description:    This is the header file for the class Ant.
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "board.hpp"

class Ant
{
   private:
      Board* board;
      int xPosition;
      int yPosition;
      int direction;

   public:
      Ant(Board*, int, int);
      int getRow();
      int getColumn();
      void move(int, int);
};
#endif
