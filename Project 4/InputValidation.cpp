/*********************************************************************
** Program name:  Project 4 (InputValidation.cpp)
** Author:        Aaron Nesbit
** Date:          11/18/19
** Description:   This is the implementation file for InputValidation
*********************************************************************/

#include <iostream>
#include <algorithm>
#include "InputValidation.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::remove;
using std::atoi;

/*
* Summary: int_validate_2_choice() - this is the input validation
*          function for the 2-choice menus
* Returns: validated user-entered integer
*/
int int_validate_2_choice()
{
   string input;
   int validated_input;
   do
   {
      do
      {
         getline(cin, input);
         input.erase(remove(input.begin(), input.end(), ' '), input.end());
         if(!(digit_check(input)))
         {
            cout << "Invalid input! Enter 1 or 2! Try again!" << endl;
            cin.clear();
         }
      }while(!(digit_check(input)));
      validated_input = atoi(input.c_str());
      if(validated_input < 1 || validated_input > 2)
      {
         cout << "Invalid input! Enter 1 or 2! Try again!" << endl;
      }
   }while(validated_input < 1 || validated_input > 2);
   return validated_input;
}

/*
* Summary: int_validate_5_choice() - this is the input validation
*          function for the 5-choice menus
* Returns: validated user-entered integer
*/
int int_validate_5_choice()
{
   string input;
   int validated_input;
   do
   {
      do
      {
         getline(cin, input);
         input.erase(remove(input.begin(), input.end(), ' '), input.end());
         if(!(digit_check(input)))
         {
            cout << "Invalid input! Enter 1, 2, 3, 4 or 5! Try again!"
                 << endl;
            cin.clear();
         }
      }while(!(digit_check(input)));
      validated_input = atoi(input.c_str());
      if(validated_input < 1 || validated_input > 5)
      {
         cout << "Invalid input! Enter 1, 2, 3, 4 or 5! Try again!"
              << endl;
      }
   }while(validated_input < 1 || validated_input > 5);
   return validated_input;
}


/*
* Summary: validate_positive_int() - this is the input validation
*          function for verifying input is a positive integer
* Returns: validated user-entered positive integer
*/
int validate_positive_int()
{
   string input;
   int validated_input;
   do
   {
      do
      {
         getline(cin, input);
         input.erase(remove(input.begin(), input.end(), ' '), input.end());
         if(!(digit_check(input)))
         {
            cout << "Enter 1 or more! Try again!" << endl;
            cin.clear();
         }
      }while(!(digit_check(input)));
      validated_input = atoi(input.c_str());
      if(validated_input < 1)
      {
         cout << "Enter 1 or more! Try again!" << endl;
      }
   }while(validated_input < 1);
   return validated_input;
}


/*
* Summary:    Input validation helper function that verifies input
*             entered only contains digits
* Parameters: User-entered string
* Returns:    True/false confirmation of string status
*/
bool digit_check(string input)
{
   bool message;

   // String check to verify it only contains digits
   for (int i = 0; i < input.size(); i++)
   {
      if(isdigit(input[i]))
      {
         message = true;     // string only contains digits
      }
      else
      {
      return false;          // string contains non-digits
      }
   }
   return message;
}
