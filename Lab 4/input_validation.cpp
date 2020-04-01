/*********************************************************************
** Program name:  Lab 4 (input_validation.cpp)
** Author:        Aaron Nesbit
** Date:          10/22/19
** Description:   This is the implementation file for input validation
**                for Lab 4.
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
* Summary:  int_validate_2_choice() - this is the input validation
*           function for the 2-choice menus
* Returns:  validated user-entered integer
*/
int int_validate_2_choice()
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
            cout << "Invalid input! Enter 1 or 2! Try again!" << endl;
            cin.clear();
         }
      }while(!(digit_check(input))); // loop runs until input is valid

      // validated input converted from string to integer
      validated_input = atoi(input.c_str());
      
      if(validated_input < 1 || validated_input > 2)
      {
         cout << "Invalid input! Enter 1 or 2! Try again!" << endl;
      }      

   }while(validated_input < 1 || validated_input > 2);

   // validated input returned
   return validated_input;
}


/*
* Summary:  int_validate_4_choice() - this is the input validation
*           function for the 4-choice menus
* Returns:  validated user-entered integer
*/
int int_validate_4_choice()
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
            cout << "Invalid input! Enter 1, 2, 3 or 4! Try again!" << endl;
            cin.clear();
         }
      }while(!(digit_check(input))); // loop runs until input is valid

      // validated input converted from string to integer
      validated_input = atoi(input.c_str());
      
      if(validated_input < 1 || validated_input > 4)
      {
         cout << "Invalid input! Enter 1, 2, 3 or 4! Try again!" << endl;
      }      

   }while(validated_input < 1 || validated_input > 4);

   // validated input returned
   return validated_input;
}


/*
* Summary:  int_validate_6_choice() - this is the input validation
*           function for the 6-choice menus
* Returns:  validated user-entered integer
*/
int int_validate_6_choice()
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
            cout << "Invalid input! Enter 1, 2, 3, 4, 5 or 6! Try again!"
                 << endl;
            cin.clear();
         }
      }while(!(digit_check(input))); // loop runs until input is valid

      // validated input converted from string to integer
      validated_input = atoi(input.c_str());
      
      if(validated_input < 1 || validated_input > 6)
      {
         cout << "Invalid input! Enter 1, 2, 3, 4, 5 or 6! Try again!" 
              << endl;
      }      

   }while(validated_input < 1 || validated_input > 6);

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
