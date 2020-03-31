/*********************************************************************
** Program name:  Program 1 (ant.cpp)
** Author:        Aaron Nesbit
** Date:          10/7/19
** Description:   This is the implementation file for the class Ant.
**                It stores the ant's location and moves itself via
**                a pointer to the board.
**
**                The initial direction the ant faces is up (1)
**                Ant facing right is direction (2)
**                Ant facing down is direction (3)
**                Ant facing left is direction (4)
*********************************************************************/

#include <iostream>
#include "ant.hpp"

using std::cin;
using std::cout;
using std::endl;

// Constructor for ant
Ant::Ant(Board* bd, int x, int y)
{
   board = bd;
   xPosition = x;
   yPosition = y;
   direction = 1;
}

// Getter for x position
int Ant::getRow()
{
   return xPosition;
}

// Getter for y position
int Ant::getColumn()
{
   return yPosition;
} 

// Ant movement function
// ADD MORE TO DESCRIPTION
void Ant::move(int x, int y)
{
   if(board->getColor(x, y) == ' ')  // If ant is on a white space
   {
      if(direction == 1)       // Ant facing up
      {
         direction = 2;        // Turns right to face right
      }
      else if(direction == 2)  // Ant facing right
      {
         direction = 3;        // Turns right to face down
      }
      else if(direction == 3)  // Ant facing down
      {
         direction = 4;        // Turn right to face left
      }
      else if(direction == 4)  // Ant facing left
      {
         direction = 1;        // Turn right to face up
      }
   }
   else     // If ant is on black space
   {
      if(direction == 1)       // Ant facing up
      {
         direction = 4;        // Turn left to face left
      }
      else if(direction == 2)  // Ant facing right
      {
         direction = 1;        // Turn left to face up
      }
      else if(direction == 3)  // Ant facing down
      {
         direction = 2;        // Turn left to face right
      }
      else if(direction == 4)  // Ant facing left
      {
         direction = 3;        // Turn left to face down      
      }
   }

   // Use current position to switch square color before leaving
   board->switchColor(x, y);

   // Ant takes a step forward
   if(direction == 1)          // Ant facing up
   {
      xPosition = x-1;         // Take 1 step up
   }
   else if(direction == 2)     // Ant facing right
   {
      yPosition = y+1;         // Take 1 step right
   }
   else if(direction == 3)     // Ant facing down
   {
      xPosition = x+1;         // Take 1 step down
   }
   else if(direction == 4)     // Ant facing left
   {
      yPosition = y-1;         // Take 1 step left
   }


   // ADD CHECK TO SEE IF ANT STILL IN BOUNDS HERE
   if(board->antInBounds(xPosition, yPosition))
   {
      if(direction == 1)       // Ant has crossed top boundary
      {
         xPosition = xPosition + 1; // Moves ant back inbounds
         direction = 3;        // Turns ant 180 so it faces down
      }
      else if(direction == 2)  // Ant has crossed right boundary
      {
         yPosition = yPosition - 1; // Moves ant back inbounds
         direction = 4;        // Turns ant 180 so it faces left
      }
      else if(direction == 3)  // Ant has crossed bottom boundary
      {
         xPosition = xPosition - 1; // Moves ant back inbounds
         direction = 1;        // Turns ant 180 so it faces up
      }
      else if(direction == 4)  // Ant has crossed left boundary
      {
         yPosition = yPosition + 1; //Moves ant back inbounds
         direction = 2;        // Turns ant 180 so it faces right
      }
   }
}
