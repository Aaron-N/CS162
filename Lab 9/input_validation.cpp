/*********************************************************************
** Program name:  Lab 9 (input_validation.cpp)
** Author:        Aaron Nesbit
** Date:          11/29/19
** Description:   This is the implementation file for input validation
**                for Lab 9.
*********************************************************************/

#include <iostream>
#include <algorithm>
#include "input_validation.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::remove;
using std::atoi;


/*
* Summary:  int_validate_3_choice() - this is the input validation
*           function for the 3-choice menus
* Returns:  validated user-entered integer
*/
int int_validate_3_choice()
{
   string input;
   int validated_input;
   do
   {
      do
      {
         // user enters input in the form of a string
         getline(cin, input);

         // any spaces in input are erased
         input.erase(remove(input.begin(), input.end(), ' '), input.end());

         // if any non-digits are in input, user prompted warned and
         // asked to enter valid input
         if(!(digit_check(input)))
         {
            cout << "Invalid input! Enter 1, 2, or 3! Try again!" << endl;
            cin.clear();
         }
      }while(!(digit_check(input))); // loop runs until input is valid

      // validated input converted from string to integer
      validated_input = atoi(input.c_str());
      
      if(validated_input < 1 || validated_input > 3)
      {
         cout << "Invalid input! Enter 1, 2, or 3! Try again!" << endl;
      }      

   }while(validated_input < 1 || validated_input > 3);

   // validated input returned
   return validated_input;
}


/*
* Summary:  int_validate_0_to_100() - this input validation function
*           verifies integers ranging from 0 to 100
* Returns:  validated user-entered integer
*/
int int_validate_0_to_100()
{
   string input;
   int validated_input;
   do
   {
      do
      {
         // user enters input in the form of a string
         getline(cin, input);

         // any spaces in input are erased
         input.erase(remove(input.begin(), input.end(), ' '), input.end());

         // if any non-digits are in input, user prompted warned and
         // asked to enter valid input
         if(!(digit_check(input)))
         {
            cout << "Invalid input! Enter an integer between 0 and 100!"
                 << " Try again!" << endl;
            cin.clear();
         }
      }while(!(digit_check(input))); // loop runs until input is valid

      // validated input converted from string to integer
      validated_input = atoi(input.c_str());
      
      if(validated_input < 0 || validated_input > 100)
      {
         cout << "Invalid input! Enter an integer between 0 and 100!"
              << "  Try again!" << endl;
      }      

   }while(validated_input < 0 || validated_input > 100);

   // validated input returned
   return validated_input;
}


/*
* Summary:  validate_positive_int() - this is the input validation
*           function for verifying input is a positive integer
* Returns:  validated user-entered positive integer
*/
int validate_positive_int()
{
   string input;
   int validated_input;
   do
   {
      do
      {
         // user enters input in the form of a string
         getline(cin, input);

         // any spaces in input are erased
         input.erase(remove(input.begin(), input.end(), ' '), input.end());

         // if any non-digits are in input, user prompted warned and
         // asked to enter valid input
         if(!(digit_check(input)))
         {
            cout << "Invalid input! Enter a positive integer! Try again!"
                 << endl;
            cin.clear();
         }
      }while(!(digit_check(input))); // loop runs until input is valid

      // validated input converted from string to integer
      validated_input = atoi(input.c_str());
      
      // check if input is less than 1
      if(validated_input < 1)
      {
         cout << "Invalid input! Enter a positive integer! Try again!"
              << endl;
      }      

   }while(validated_input < 1);

   // validated input returned
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
   
   // String checked to verify it only contains digits
   for(int i = 0; i < input.size(); i++)
   {
      if(isdigit(input[i]))
      {
         message = true;      // string only contains digits
      }
      else
      {
         return false;        // string contains non-digits
      }
   }   
   return message;
}
