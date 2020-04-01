/*********************************************************************
** Program name:  Lab 2 (arrayChecker.cpp)
** Author:        Aaron Nesbit
** Date:          10/12/19
** Description:   This is the source code for the function
**                arrayChecker()
*********************************************************************/

#include "arrayChecker.hpp"

/*
* Summary :   arrayChecker() confirms whether or not the pointed to
*             array is empty
* Parameter:  Pointer to an array
* Returns:    'true' if empty, 'false' if not empty
*/
bool arrayChecker(int* array)
{
   for(int i = 0; i < 26; i++) // Value for each letter checked
   {
      if(array[i] != 0)
      {
         return false;
      }
   }
   return true;
}
