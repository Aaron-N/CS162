/*********************************************************************
** Program name:  Project 1 (menu.cpp)
** Author:        Aaron Nesbit
** Date:          10/7/19
** Description:   This is the implementation file for function menu().
**                It either runs Langton's Ant (user enters 1) or it
**                quits the program (user enters 2).
*********************************************************************/

#include <iostream>
#include "menu.hpp"
#include "intValidator2.hpp"

using std::cin;
using std::cout;
using std::endl;

int menu()
{
   int choose; // menu choice variable declared

   
   //User prompted to choose to start simulation or quit
   cout << "Would you like to:" << endl; 
   cout << "1. Start Langton's Ant simulation" << endl;
   cout << "2. Quit" << endl;
   cout << "Enter your choice (1 or 2):" << endl;
   choose = intValidator();

   // If user entered value other than 1 or 2, ask for valid input
   while(choose <= 0  || choose > 2)
   {
      cout << "Invalid choice! Try again! (1 or 2):" << endl;
      cin.clear();
      cin.ignore();
      choose = intValidator();
   }

   if(choose == 1) // User wants to start simulation
   {
      return 1;
   }
   else // User wants to quit simulation
   {   
      return 2;
   }
}
