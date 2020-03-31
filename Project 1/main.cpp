/*********************************************************************
** Program name:  Project 1 (main.cpp)
** Author:        Aaron Nesbit
** Date:          10/7/19
** Description:  This is the main file for Project 1.
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "menu.hpp"
#include "intValidator2.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
   int choose = menu();
   while(choose == 1)
   {
      int boardColumns;
      int boardRows = 0;
      int simSteps = 0;
      int antColumn = 0;
      int antRow = 0;
      int counter = 0;


      // User prompted to enter desired board width
      // Input validated to be positive integer by intValidator()
      // Input then checked to verify it is within allowed range
      cout << "Enter an integer between 2 and 80 to set board width:"
           << endl;
      boardColumns = intValidator();
      while(boardColumns < 2 || boardColumns > 81 || cin.fail())
      {
         cout << "Entered board width out of range. Try again!" << endl;
         cin.clear();
         cin.ignore();
         boardColumns = intValidator();
      }


      // User prompted to enter desired board height
      // Input validated to be positive integer by intValidator()
      // Input then checked to verify it is within allowed range
      cout << "Enter an integer between 2 and 60 to set board height:"
           << endl;
      boardRows = intValidator();
      while(boardRows < 2 || boardRows > 60 || cin.fail())
      {
         cout << "Entered board height out of range. Try again!" << endl;
         cin.clear();
         cin.ignore();
         boardRows = intValidator();
      }

/*
      // User asked if they would like ant to be placed randomly on board
      char random;
      cout << "Would you like to randomly place the ant on the board?"
           << endl;
      cout << "1. Yes" << endl;
      cout << "2. No" << endl;
      cout << "Enter your choice (1 or 2):" << endl;
      cin.ignore();
      cin >> random;
      while(random != '1' && random != '2' )
      {
         cout << "Invalid choice! Try again! (1 or 2):" << endl;
         cin.ignore();
         cin >> random; 
      }
      if(random == '1')
      {
         srand(time(NULL));
         antColumn = rand() % boardColumns;
         antRow = rand() % boardRows;
         cout << "Randomly chosen ant starting X-coordinate: "
              << antColumn << endl;
         cout << "Randomly chosen ant starting Y-coordinate: "
              << antRow << endl;
      }
      
*/
      // User prompted to enter desired ant starting X position on board
      // Input validated to be positive integer by intValidator()
      // Input then checked to verify it is within allowed range
//    if(random == '2')
      {
      cout << "Enter a starting X-coordinate for the ant" << endl;
      cout << "(An integer between 0 and " << boardColumns -1
           << "):" << endl;
      antColumn = intValidator();
      while(antColumn < 0 || antColumn > boardColumns - 1 || cin.fail())
      {
         cout << "Entered starting X-coordinate out of range. Try again!"
              << endl;
         cin.clear();
         cin.ignore();
         antColumn = intValidator();
      }  
      }

      // User prompted to enter desired ant starting Y position on board
      // Input validated to be positive integer by intValidator()
      // Input then checked to verify it is with allowed range
//    if(random == '2')
      {
      cout << "Enter a starting Y-coordinate for the ant" << endl;
      cout << "(An integer between 0 and " << boardRows - 1
           << "):" << endl;
      antRow = intValidator();
      while(antRow < 0 || antRow > boardRows - 1 || cin.fail())
      {
         cout << "Entered starting Y-coordinate out of range. Try again!"
              << endl;
         cin.clear();
         cin.ignore();
         antRow = intValidator(); 
      }
      }

      // User prompted to enter desired number of simulation steps
      // Input validated to be positive integer by intValidator()
      // Input then checked to verify it is within allowed range
      cout << "Enter the desired number of simulation steps to run"
           << endl;
      cout << "(An integer between 1 and 12000):" << endl;
      simSteps = intValidator();
      while(simSteps < 1 || simSteps > 12000 || cin.fail())
      {
         cout << "Entered number of simulation steps out of range. "
              << "Try again!" << endl;
         cin.clear();
         cin.ignore();
         simSteps = intValidator();
      }


      // 2D array dynamically allocated using user-entered row size
      // (boardRows) and column size (boardColumns)
      char **array = new char*[boardRows];
      for(int i = 0; i < boardRows; i++)
      {
         array[i] = new char[boardColumns];
      }   


      // Board and Ant objects created using user-entered values
      Board *board = new Board(array, boardRows, boardColumns);
      Ant ant(board, antRow, antColumn); 

      
      // Simulation runs through steps below until user-entered 
      // number of steps (simSteps) is reached
      while(counter < simSteps)
      {
         counter = counter+1;     // Counter increments up 1
         int currentRow = ant.getRow();  // Gets current X
         int currentColumn = ant.getColumn(); // Gets current Y
         ant.move(currentRow, currentColumn); // Move the ant
         print(board, ant);   // Prints board with ant on it
      }      


      // 2D array dynamically allocated memory is freed
      for(int i = 0; i < boardRows; i++)
      {
         delete [] array[i];
      }
      delete [] array;

      cout << "Simulation complete!" << endl;
      choose = menu();
   }
   // If user picks 'Quit', program ends
   if(choose == 2)
   {
      cout << "Goodbye!" << endl;
      return 0;
   }
}
