/*********************************************************************
** Program name:  Lab 10 (input_validation.cpp)
** Author:        Aaron Nesbit
** Date:          11/30/19
** Description:   This is the implementation file for input validation
**                for Lab 10.
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
