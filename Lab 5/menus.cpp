/*********************************************************************
** Program name:  Lab 5 (menus.cpp)
** Author:        Aaron Nesbit
** Date:          10/29/19
** Description:   This is the implementation file for the menu
**                functions of Lab 5.
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include "menus.hpp"
#include "input_validation.hpp"
#include "recursive_functions.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::exit;
using std::getline;

/*
* Summary:  main_menu() - this function creates the main menu and calls
*           the appropriate submenu based on user selection
*/
void main_menu()
{
   cout << "Welcome to Lab 5!" << endl;
   int selection;
   while(true)
   {
      cout << "--------------------------------------------------" << endl;
      cout << "What recursive function would you like to try out?" << endl;
      cout << "1. Reverse a string" << endl;
      cout << "2. Calculate the sum of an array of integers" << endl;
      cout << "3. Calculate the triangular number of an integer" << endl;
      cout << "4. None, exit the program" << endl;
      cout << "Enter your selection (1, 2, 3 or 4):" << endl;
 
      selection = int_validate_4_choice();

      switch(selection)
      {
         case 1:   // Reversing a string chosen
         {
            reverse_menu();
            break;
         }
         case 2:   // Calculate the sum of integer array chosen
         {
            sum_array_menu();
            break;
         }
         case 3:   // Calculate triangular # of integer chosen
         {
            triangle_num_menu();
            break;
         }
         case 4:   // User choses to exit program
         {
         cout << "Goodbye!" << endl;
         exit(0);
         }
      }
   } 
}


/*
* Summary: reverse_menu() - prompts user to enter a string, calls the
*          function reverse_string() to reverse the string, then displays
*          the result
*/
void reverse_menu()
{
   string input;
   
   // User prompted to enter string
   cout << "Enter a string you'd like to reverse:" << endl;

   getline(cin, input);      // String entered
   reverse_string(input);    // String reverse function called
}


/*
* Summary: sum_array_menu() - prompts user to enter array size and
*          array elements, calls the function calc_sum_of_array()
*          to calculate the sum of the array, the displays the result
*/
void sum_array_menu()
{
   int size;
   int value;

   // User prompted to enter array size
   cout << "Enter the size of the array you'd like to use:" << endl;
  
   size = validate_positive_int();     // Input validated

   int array[size];                    // Array created
   int counter = 0;                    // Counter initialized

   while(counter < size)  // User enters elements until size reached
   {
      cout << "Enter an integer value for the element at position "
           << (counter + 1) << " of the array:" << endl;
      value = validate_any_int();      // Input validated
      array[counter] = value;          // Value added to array
      counter++;                       // Counters increase by 1
   }

   // Sum of array displayed
   cout << "The sum of the array you entered is "
        << calc_sum_of_array(array, size) << endl;
}


/*
* Summary: triangle_num_menu() - prompts use for integer input,
*          calls the function calc_triangle_number() to calculate
*          the triangle number, then displays the result
*/
void triangle_num_menu()
{
   int N;

   // User prompted to enter integer for calculation
   cout << "What positive integer would you like to calculate the "
        << "triangular number of?" << endl;

   N = validate_positive_int();        // Input validated

   // Triangular number displayed
   cout << "The triangular number of " << N << " is "
        << calc_triangle_number(N) << endl;
}
