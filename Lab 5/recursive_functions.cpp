/*********************************************************************
** Program name:  Lab 5 (recursive_functions.cpp)
** Author:        Aaron Nesbit
** Date:          10/28/19
** Description:   This is the source file for the recursive functions
**                used in Lab 5.
*********************************************************************/

#include <iostream>
#include <string>
#include "recursive_functions.hpp"

using std::string;
using std::cin;
using std::cout;

/*
* Summary:   reverse_string() - takes a user-entered string and reverses
*            it and prints it out using recursion.
* Parameter: a user-entered string
*/
void reverse_string(string s)
{
   int size = s.size();
      
   if(s.size() == 0)    // base case
   {
      cout << s << "\n";
   }
   else
   {
      cout << s[size - 1];
      reverse_string(s.substr(0, size - 1)); // recursive funtion call
   }
}


/*
* Summary:    calc_sum_array - takes an array of integers and calculates
*             the sum of them all.
* Parameters: Pointer to an array of integers
*             Size of the array
* Returns:    Sum of the array elements
*/
int calc_sum_of_array(int *array, int size)
{
   if(size == 0)   // base case
   {
      return 0;
   }

                                            // recursive function call
   return array[size - 1] + calc_sum_of_array(array, (size - 1));
}


/*
* Summary:    calc_triangle_number - takes an integer and calculates
*             the triangular number of the integer.
* Parameters: An integer
* Returns:    The triangular number of the integer
*/
int calc_triangle_number(int N)
{
   if(N == 1)      // base case
   {
      return N;
   }

   return N + calc_triangle_number(N - 1);  // recursive function call
}
