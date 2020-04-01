/*********************************************************************
** Program name: main.cpp 
** Author:       Aaron Nesbit
** Date:         10/3/19
** Description:  This is the main function source code for the program
**               MatrixCalculator. The function first asks the user to
**               choose the size of a matrix, either 2x2 or 3x3, by
**               entering '2' or '3' respectively. The function then
**               dynamically allocates memory space for the matrix
**               selected and then prompts the user using the function 
**               'readMatrix()' to enter either 4 or 9 integers to fill
**               the matrix. The determinant of the entered matrix is
**               then calculated by the function 'determinant()'. The 
**               user-entered matrix is then displayed, followed by
**               the calculated determinant. The dynamically allocated
**               memory used by the matrix is then freed and the
**               program ends.
**
**               The program is compiled by typing "make" in the
**               command line. The executable file 'MatrixCalculator'
**               is used to run the program. To remove the executables
**               created by compiling, type "make clean" in the command
**               line.
*********************************************************************/

#include <iostream>
#include "readMatrix.hpp"
#include "determinant.hpp"
using std::cin;
using std::cout;
using std::endl;

int main()
{
   int matrixSize; // Variable for matrix size initialized


// User asked to choose size of matrix: 2x2 by selecting '2'
//                                      3x3 by selecting '3'
   cout << "Select size of the matrix to calculate determinant of:" << endl;
   cout << "2x2 (enter 2) or 3x3 (enter 3)" << endl;
   cin >> matrixSize;

   
// Memory for matrix of size matrixSize is now dynamically allocated
   int** array = new int*[matrixSize];
   for(int i = 0; i < matrixSize; ++i)
   {
      array[i] = new int[matrixSize];
   } 


// The function readMatrix() is now called to prompt user to enter
// integers to fill in the matrix
   readMatrix(array, matrixSize); 


// The matrix is now displayed in square format to the user
   cout << "You have entered the following matrix:" << endl;
   for(int i = 0; i < matrixSize; i++)
   {
      for(int j = 0; j < matrixSize; j++)
      {
         cout << array[i][j] << "\t";
      } 
      cout << endl;
   }   

   
// The determinant of the matrix is now calculated by calling 
// the function determinant()and then the result is displayed
   cout << "The determinant of this matrix is: "
        << determinant(array, matrixSize)
        << endl;


// The dynamically allocated memory used by the matrix is now freed
   for(int i = 0; i < matrixSize; ++i)
   {
      delete [] array[i];
   }
   delete [] array;

   return 0;      // Program ends
}
