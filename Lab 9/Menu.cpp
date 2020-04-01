/*********************************************************************
** Program name:  Lab 9 (Menu.cpp)
** Author:        Aaron Nesbit
** Date:          11/28/19
** Description:   This is the source code for the menu function
*********************************************************************/

#include <iostream>
#include "input_validation.hpp"
#include "BufferSim.hpp"
#include "Palindrome.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
* Summary: menu() - this is the menu function for Lab 9
*/
void menu()
{
   bool exit = false;
   
   do
   {
      // Display main menu
      cout << endl;
      cout << "==========================" << endl;
      cout << "===  Welcome to Lab 9! ===" << endl;
      cout << "==========================" << endl;
      cout << "What would you like to do?" << endl;
      cout << " 1. Simulate a buffer     " << endl;
      cout << " 2. Create a palindrome   " << endl;
      cout << " 3. Exit the program      " << endl;
      cout << "==========================" << endl;
      cout << " Your choice: ";

      // User makes a choice
      int choice = int_validate_3_choice();

      switch(choice)
      {
         case 1:        // Simulate a buffer
         {
            buffer_simulation();
            break;
         }
         case 2:        // Create a palindrome
         {
            make_palindrome();
            break;
         }
         case 3:        // Exit the program
         {
            exit = true;
            cout << endl;
            cout << "OK, goodbye!" << endl;
            cout << endl;
            break;
         }
      }
   }while(!exit); 
}
