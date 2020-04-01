/*********************************************************************
** Program name: determinant.cpp
** Author:       Aaron Nesbit
** Date:         10/3/19
** Description:  This is the source code for the function determinant()
*********************************************************************/

#include "determinant.hpp"

/*********************************************************************
*****                       determinant()                        *****
***** The int function determinant() takes in two parameters, a  *****
***** pointer to a 2D array and an integer as the size of the    *****
***** matrix. The function takes in the values inside the matrix *****
***** and calculates the determinant based on whether a 2x2 or   *****
***** 3x3 matrix is specified by matrixSize. The function then   *****
***** returns the determinant result to main().                  *****
*********************************************************************/
int determinant(int** array, int matrixSize)
{
   int result;
   if(matrixSize == 2)  // Determinant of 2x2 matrix calculation
   {
      result = array[0][0]*array[1][1]-array[0][1]*array[1][0];
   }
   else                 // Determinant of 3x3 matrix calculation
      result = array[0][0]*(array[1][1]*array[2][2]-array[1][2]*array[2][1])
             -array[0][1]*(array[1][0]*array[2][2]-array[1][2]*array[2][0])
             +array[0][2]*(array[1][0]*array[2][1]-array[1][1]*array[2][0]);
  
   return result;       // Result returned to main()
}

