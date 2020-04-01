/*********************************************************************
** Program name:  Lab 9 (Palindrome.cpp)
** Author:        Aaron Nesbit
** Date:          11/29/19
** Description:   This is the source file for palindrome()
*********************************************************************/

#include <iostream>
#include <stack>
#include <string>
#include "Palindrome.hpp"

using std::stack;
using std::string;
using std::cin;
using std::cout;
using std::getline;
using std::endl;

/*
* Summary: make_palindrome() - this is the palindrome generation function.
*          It prompts the user to enter a string and then generates a
*          palindrome and displays it. 
*/
void make_palindrome()
{
   // User prompted to enter a string to convert to palindrome
   string stringInput;
   cout << endl;
   cout << "Enter a string to be converted into a palindrome:" << endl;
   getline(cin, stringInput);

   // If user hits return without entering any characters, prompt them
   // to try again
   while(stringInput.length() < 1)
   {
      cout << "You didn't enter anything! Try again!" << endl;
      cin.clear();
      getline(cin, stringInput);
   }

   // Stack created
   stack <char> palindrome;

   // String characters individually pushed to stack
   for(char c : stringInput)
   {
      palindrome.push(c);
   }

   // Palindrome now displayed
   cout << endl;
   cout << "Your palindrome: " << stringInput;
   while(!palindrome.empty())
   {
      cout << palindrome.top();
      palindrome.pop();
   }
   cout << endl;
}
 
