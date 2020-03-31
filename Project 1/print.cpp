/*********************************************************************
** Program name:  Program 1 (print.cpp)
** Author:        Aaron Nesbit
** Date:          10/8/19
** Description:   This is the implementation file for the function
**                print(). It uses a pointer to Board and an Ant
**                object to print an ant on the board.
*********************************************************************/

#include <iostream>
#include "print.hpp"

using std::cout;
using std::endl;

void print(Board* bd, Ant a)
{
   int antsRow = a.getRow();       // Gets ant's X position
   int antsColumn = a.getColumn(); // Gets ant's Y position
   int rows = bd->getRows();        // Gets board height
   int columns = bd->getColumns();  // Gets board width

   // Board colors are now filled in from Board object data
   // When ant position is reached, a '*' is printed on board
   for(int i = 0; i < rows; i++)
   {
      for(int j = 0; j < columns; j++)
      {
         if(i == antsRow && j == antsColumn)
         {
            cout << '*';
         }
         else
         {
            cout << bd->getColor(i,j);
         }
      } 
      cout << endl;
   }  
} 
