/*********************************************************************
** Program name:  Lab 2 (count_letters.cpp)
** Author:        Aaron Nesbit
** Date:          10/11/19
** Description:   This is the source code for the function
**                count_letters()
*********************************************************************/

#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>
#include "count_letters.hpp"

using std::ifstream;
using std::string;
using std::getline;

/*
* Summary:   count_letters() counts the letter frequencies in a user-
*            specified .txt file and stores the counts to an array
* Parameter: A user-specified input filestream
* Parameter: Pointer to an array of integers
* Returns:   Letter frequency counts to array
*/
void count_letters(ifstream& input, int* array)
{
   string mixedcaseParagraph;   // Variable for initial string declared
   string lowercaseParagraph; // Variable for converted string declared
   
   // User-specified input file accessed and current paragraph loaded  
   getline(input, mixedcaseParagraph);

   // If current paragraph not empty, paragraph converted to lowercase
   // and then letter frequencies are counted and the values obtained
   // are stored in the array declared in main()
   if(!mixedcaseParagraph.empty())
   {
      for(int i = 0; i < mixedcaseParagraph.length(); i++)
      {
        lowercaseParagraph += tolower(mixedcaseParagraph[i]); 
      }
      
      for(int i = 0; i < lowercaseParagraph.length(); i++)
      {
         for(int letter = 97; letter <= 122; letter++)
         {
            if(lowercaseParagraph[i] == letter)
            {
               array[letter - 97]++;
            }
         }
      }
   }
}
