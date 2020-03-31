/*********************************************************************
** Program name:   Project 1 (board.hpp)
** Author:         Aaron Nesbit
** Date:           10/7/19
** Description:    This is the header file for the class Board.
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
   private:
      char **board;
      int rows;
      int columns;

   public:
      Board(char**, int, int);
      int getRows();
      int getColumns();
      char getColor(int, int);
      void switchColor(int, int);
      bool antInBounds(int, int);
};
#endif
