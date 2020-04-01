/*********************************************************************
** Program name:  Lab 2 (output_letters.cpp)
** Author:        Aaron Nesbit
** Date:          10/12/19
** Description:   This is the source code for the function
**                output_letters()
*********************************************************************/

#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>
#include "output_letters.hpp"

using std::ofstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;

/*
* Summary:   output_letters() asks user for output file name and 
*            then outputs the frequencies of letters counted to
*            the output file
* Parameter: A user-specified output filestream
* Parameter: Pointer to an array of integers containing frequency
*            of letters
* Returns:   Letter frequency counts to an output file
*/
void output_letters(ofstream& output, int* array)
{
   string outputFilename;  // Variable for output file name declared

   // User asked for output file name for current paragraph
   cout << "Enter output .txt file name(s) to hold letter frequency counts"
        << endl;
   cout << "(You'll be prompted for this for each paragraph analyzed):"
        << endl;
   cin >> outputFilename;  // User provides name for current output file
   output.open(outputFilename); // Specified output file opened

   // Letter frequencies read from array and then sent to output file
   for(int i = 0; i <= 25; i++)
   {
      char letter = (i + 97);
      output << letter << ": " << array[i] << "\n";
   }

   // Output file closed
   output.close();

   // Array values reset to zero to determine if next line after
   // paragraph is blank, and then will be used by next paragraph
   // encountered
   for(int i = 0; i < 26; i++)
   {
      array[i] = 0;
   }
}
