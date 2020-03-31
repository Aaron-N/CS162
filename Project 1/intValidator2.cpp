/*********************************************************************
** Program name:  Project 1 (intValidator2.cpp)
** Author:        Aaron Nesbit
** Date:          10/13/19
** Description:   This is the implementation file containing the 
**                functions intValidator() and positiveCheck(). They
**                validate that user input is a positive integer.
*********************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include "intValidator2.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::remove;
using std::atoi;

int intValidator()
{
   string input;
   int uint;

   do
   {
      getline(cin, input);
      input.erase(remove(input.begin(),input.end(),' '),input.end());
      if(!(positiveCheck(input)))
         cout << "Error! Enter a positive integer!:" << endl;
   }while(!(positiveCheck(input)));
   uint = atoi(input.c_str());
   return uint;
}

bool positiveCheck(string input)
{
   bool message;

   for(int index = 0; index < input.size(); index++)
   {
      if(isdigit(input[index]))
         message = true;
      else
         return false;
   }
   return message;
}
