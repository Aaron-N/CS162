/*********************************************************************
** Program name: readMatrix.cpp
** Author:       Aaron Nesbit
** Date:         10/3/19
** Description:  This is the source code for the function readMatrix()
*********************************************************************/

#include <iostream>
#include "readMatrix.hpp"
using std::cin;
using std::cout;
using std::endl;

/*********************************************************************
*****                      readMatrix()                          *****
***** The void function readMatrix() takes in two parameters, a  *****
***** pointer to a 2D array and an integer as the size of a      *****
***** matrix. The function then prompts the user to enter either *****
***** 4 or 9 integers, depending on whether a 2x2 or 3x3 matrix  *****
***** is specified by matrixSize. The function uses the pointer  *****
***** to the 2D array to access it and does not return anything  *****
***** to main().                                                 *****
*********************************************************************/
void readMatrix(int** array, int matrixSize)
{
   for(int i = 0; i < matrixSize; ++i)
   {
      for(int j = 0; j < matrixSize; ++j)
      {
         cout << "Enter an integer for Element " << j+1 << " of Row "
              << i+1 << ":" << endl;
         cin >> array[i][j];
      }
   }   
}
