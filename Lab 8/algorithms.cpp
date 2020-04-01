/*********************************************************************
** Program name:  Lab 8 (algorithms.cpp)
** Author:        Aaron Nesbit
** Date:          11/19/19
** Description:   This is the implementation file for the search and
**                sort functions for Lab 8.
*********************************************************************/

#include <iostream>
#include "algorithms.hpp"

using std::cout;
using std::endl;

/*
* Summary:    simple_search() - function for searching an array for a
*             user-specified integer value
* Parameters: integer array to search
*             size of array
*             integer value to search for
* Returns:    whether or not value was found
*/
int simple_search(const int array[], int size, int value)
{
   int index = 0;
   while(index < size) // While the position is less than the array size
   {
      if(array[index] == value)   // If target value is found
      {
         cout << "Target value found" << endl;
         return 0;
      }
      index++;
   }
   cout << "Target value not found" << endl; // If target value not found
   return 1;
}


/*
* Summary:   bubble_sort() - function that uses the bubble sort algorithm
*            to sort an array of integers. Based on the bubble sort code
*            on p.615 of "C++ Early Objects" 9th ed Gaddis/Walters/Muganda 
* Parameter: integer array to sort 
*            size of array
*/
void bubble_sort(int array[], int size)
{
   int temp;
   bool swap;

   do
   {
      swap = false;                   // Swap status initialized to false
      for(int count = 0; count < (size - 1); count++)
      {
         if(array[count] > array[count + 1]) // If current number greater
         {                                   // than the next number
            temp = array[count];
            array[count] = array[count + 1]; // Number positions swapped
            array[count + 1] = temp;
            swap = true;                     // Swap status set to true
         }
      }
   }while(swap);  // Loop again if a swap occurred
}


/*
* Summary: binary_search() - function that searches an array for a user-
*          specified integer value by utilizing a binary search algorithm
*
*/
int binary_search(const int array[], int size, int value)
{
   int first = 0;
   int last = size - 1;
   int middle;
   int position = -1;
   bool found = false;

   while(!found && first <= last) // If value not found and the first value
   {                              // is less than / equal to the last value
      middle = (first + last)/2;
      if(array[middle] == value)  // If the middle value = target value
      {
         found = true;            // Status set to true
         position = middle;
         cout << "Target value found" << endl; // User told target found
         return 0;
      }
      else if(array[middle] > value) // If middle greater than target value
      {
         last = middle - 1;
      }
      else                           // If middle less than target value
      {
         first = middle +1;
      }
   }
   cout << "Target value not found" << endl; // If target value not found
   return 1;
}
