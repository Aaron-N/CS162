/*********************************************************************
** Program name:  Project 4 (main.cpp)
** Author:        Aaron Nesbit
** Date:          11/20/19
** Description:   This is the main() for Project 4, Fantasy Combat
**                Tournament. It runs a one-user-two-player tournament
**                between two teams of fighters, displays winners of
**                each fight, which team wins the tournament, and 
**                allows the user to view a list of the losers.
*********************************************************************/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "InputValidation.hpp"
#include "Game.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
   srand(time(NULL));   // Random number generator seeded
   
   // Display the main menu and ask the user to choose
   cout << endl;
   cout << "Welcome to Fantasy Combat Tournament!" << endl;
   cout << "What would you like to do?           " << endl;
   cout << "1. Play                              " << endl;
   cout << "2. Exit                              " << endl;

   int menuChoice = int_validate_2_choice();
   
   // Start the program
   do
   {
      if(menuChoice != 2)
      {
         Game tournament;   // Start tournament

         // Prepare the play again menu
         cout << "Would you like to" << endl;
         cout << "1. Play again    " << endl;
         cout << "2. Exit          " << endl;
         
         int replay = int_validate_2_choice();

         if(replay == 2)     // If user chooses to quit
         {
            menuChoice = 2;
         }
      }
   }while(menuChoice != 2); // Play until user choose to quit
  
   cout << endl;
   cout << "OK, goodbye!" << endl;
   cout << endl; 

   return 0;
}
