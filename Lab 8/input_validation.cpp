/*********************************************************************
** Program name:  Lab 8 (input_validation.cpp)
** Author:        Aaron Nesbit
** Date:          11/19/19
** Description:   This is the implementation file for input validation
**                for Lab 8.
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
* Summary:  validate_any_int() - this is the input validation
*           function for verifying input is an integer
* Returns:  validated user-entered positive integer
*/
int validate_any_int()
{
   string input;
   int validated_input;
   
   do
   {
      // user enters input in the form of a string
      getline(cin, input);

      // any spaces in input are erased
      input.erase(remove(input.begin(), input.end(), ' '), input.end());

      // if any non-digits are in input, save for a "-" sign,
      // user warned and prompted to enter valid input
      if(!(is_integer(input)))
      {
         cout << "Invalid input! Enter an integer! Try again!"
              << endl;
         cin.clear();
      }
   }while(!(is_integer(input))); // loop runs until input is valid

   // validated input converted from string to integer
   validated_input = atoi(input.c_str());
      
   // validated input returned
   return validated_input;
}


/*
* Summary:    Input validation helper function that verifies input
*             entered only contains digits. "-" is allowed only if
*             it is the first element in the string
* Parameters: User-entered string
* Returns:    True/false confirmation of string status 
*/
bool is_integer(string input)
{
   bool message;

   if(input == "")
   {
      return false;
   }

   if(input[0] == '-')  // if first element is a negative sign
   {
      for(int i = 1; i < input.size(); i++)
      {
         if(isdigit(input[i]))
         {
            message = true;  // remainder of string only digits
         }
         else
         {
            return false;    // non-digits occur later in string
         } 
      }
   }
   else   // if first element is not a negative sign
   {
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
   }   
   return message;
}
