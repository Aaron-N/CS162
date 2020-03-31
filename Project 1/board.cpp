/*********************************************************************
** Program name:   Program 1 (board.cpp)
** Author:         Aaron Nesbit
** Date:           10/7/19
** Description:    This is the implementation file for the class
**                 Board. It sets colors for squares, changes colors
**                 of squares, and checks whether or not the ant is
**                 out of bounds.
*********************************************************************/

#include <iostream>
#include <string>
#include "board.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Constructor for board
Board::Board(char** bd, int rs, int cs)
{
   board = bd;
   rows = rs;
   columns = cs;
}

// Getter for rows
int Board::getRows()
{
   return rows;
}
   
// Getter for columns
int Board::getColumns()
{
   return columns;
}

// Returns color of square. If no color, it turns it white
char Board::getColor(int x, int y)
{
   char clr = board[x][y];
   if(clr != '#' && clr != ' ')
   {
      return ' ';
   }
   return clr;
}

// Switches square color to black or white depending on status
void Board::switchColor(int x, int y)
{
   char status = getColor(x, y);
   if(status == ' ') // switches from white to black
   {
      board[x][y] = '#';
   }
   else              // switches from black to white
   {
      board[x][y] = ' ';
   }
}

// Looks at current ant coordinates to make sure it is in bounds
bool Board::antInBounds(int x, int y)
{
   if(x < 0)          // off board left side check
   {
      return true;
   }
   if(x > rows-1)     // off board right side check
   {
      return true;
   }
   if(y < 0)          // off board top side check
   {
      return true;
   }
   if(y > columns-1)  // off board bottom side check
   {
      return true;
   }
   return false;      // if ant position in bounds, returns false
}

