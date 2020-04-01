/*********************************************************************
** Program name:  Lab 3 (input_validation.cpp)
** Author:        Aaron Nesbit
** Date:          10/15/19
** Description:   This is the implementation file for input validation
**                for Lab 3.
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
* Summary:  integer_validator() - this is the main input validation
*           function. 
* Returns:  validated user-entered integer
*/
int integer_validator()
{
   string input;
   int validated_input;
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
         cout << "Invalid input! Try again!" << endl;
         cin.clear();
      }
   }while(!(digit_check(input))); // loop runs until input is valid

   // validated input converted from string to integer
   validated_input = atoi(input.c_str());   

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
