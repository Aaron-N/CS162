/*********************************************************************
** Program name:  Lab 9 (main.cpp)
** Author:        Aaron Nesbit
** Date:          11/28/19
** Description:   This is the main file for Lab 9. It uses STL
**                containers to simulate a buffer (using a queue)and
**                create a palindrome (using a stack).
*********************************************************************/

#include <iostream>
#include <ctime>
#include "Menu.hpp"

int main()
{
   srand(time(NULL));   // For random number generation

   menu();              // Main menu function starts program

   return 0;
}
