/*********************************************************************
** Program name: Lab 2 (main.cpp)
** Author:       Aaron Nesbit
** Date:         10/8/19
** Description:  This is the main function source code for the program
**               LetterCounter. The program first asks the user to
**               enter the filename of a .txt file to be analyzed. The
**               program then proceeds to count the frequency of each 
**               letter of the alphabet in a paragraph until it reaches
**               the 'end of file' character. The program then prompts
**               the user to enter an output file name for the results.
**               The program continues this process until it has gone
**               through all paragraphs in the input file, then the
**               program ends.
**
**               The program is compiled by typing "make" in the 
**               command line. The executable file 'LetterCounter'
**               is used to run the program. To remove the executables
**               created by compiling, type "make clean" in the command
**               line.
*********************************************************************/

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "count_letters.hpp"
#include "output_letters.hpp"
#include "arrayChecker.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

int main()
{
   // Variables declared
   ifstream input;
   string fileName;

   // Array holding letter count initialized
   int letters[26] = {0};   

   // User prompted to enter .txt file to be analyzed
   cout << "Enter .txt file you would like the letter frequency count of:"
        << endl;
   cin >> fileName;
   
   // Program attempts to open user-entered .txt file
   input.open(fileName);

   // If user-entered .txt file not found, the program terminates
   if(!input)
   {
      cout << "Unable to open .txt file you entered. Program terminated."
           << endl;
      return 1;      // Program terminates
   }

   // Program runs through counting process for current paragraph
   // until it reaches EOF
   while(input.peek() != EOF)
   {
      // Letter frequency counting begins
      count_letters(input, letters);

      // If array contains value, it is output to file
      // If it is empty, nothing happens
      if(!arrayChecker(letters))
      {
         // Output file for current paragraph created
         ofstream output;
         output_letters(output, letters);
      }
   }

   // User-entered .txt file closed
   input.close(); 

   // User notified that analysis is complete
   cout << "Letter frequency counting complete!" << endl;
   cout << "Results in output file(s) you specified!" << endl;
   return 0;
}
