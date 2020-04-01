/*********************************************************************
** Program name:  Lab 8 (main.cpp)
** Author:        Aaron Nesbit
** Date:          11/19/19
** Description:   This is the main() file for Lab 8. It opens four
**                text files and creates arrays containing the values
**                within. A simple search then runs, prompting the user
**                to enter a target value, and then displays the results
**                for each file. A bubble sort is then run, and the
**                results are displayed for each file. Lastly, a binary
**                search is run, and the results are displayed.
*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "input_validation.hpp"
#include "algorithms.hpp"
#include "stream_functions.hpp"

using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::endl;

int main()
{
   // Declaration of variables   
   ifstream input_file;
   ofstream output_file;
   string filename;
   int value;
   int target;
   int counter;

   // Arrays are created
   int original[19];
   int early[20];
   int middle[20];
   int end[20];


   // Text files opened and copied to arrays
   cout << "The provided .txt files are now being opened and their contents"
        << endl
        << "are being copied into arrays for searching and sorting..."
        << endl;
   cout << endl;
   open_copy(input_file, "original.txt", original);
   open_copy(input_file, "early.txt", early);
   open_copy(input_file, "middle.txt", middle);
   open_copy(input_file, "end.txt", end);


   // The arrays are now displayed
   cout << "Here are the arrays:" << endl;
   cout << endl;

   cout << "original.txt:  ";
   for(int i = 0; i < 19; i++)
   {
      cout << original[i] << " ";
   }
   cout << endl;   

   cout << "early.txt:     ";
   for(int i = 0; i < 20; i++)
   {
      cout << early[i] << " ";
   }
   cout << endl;   

   cout << "middle.txt:    ";
   for(int i = 0; i < 20; i++)
   {
      cout << middle[i] << " ";
   }
   cout << endl;   

   cout << "end.txt:       ";
   for(int i = 0; i < 20; i++)
   {
      cout << end[i] << " ";
   }
   cout << endl;   
   cout << endl;


   // Each array is now searched using the simple search algorithm
   // and the results are displayed
   cout << "A simple search algorithm will now search each array"
        << endl
        << "for whatever integer value you'd like to find." << endl;
   cout << "What integer value would you like to search for? " << endl;

   target = validate_any_int();             // input validated

   cout << "original.txt: ";
   simple_search(original, 19, target);  // simple search function called

   cout << "early.txt:    ";
   simple_search(early, 20, target);     // simple search function called

   cout << "middle.txt:   ";
   simple_search(middle, 20, target);    // simple search function called

   cout << "end.txt:      ";
   simple_search(end, 20, target);       // simple search function called
   cout << endl;
   cout << endl;
   

   // Each array is now sorted using a bubble sort algorithm and the
   // results are displayed and written to a user-specified file
   cout << "Each array will now be sorted using a bubble sort algorithm,"
        << endl;
   cout << "and the results will be displayed and saved to output files"
        << endl;
   cout << "that you will specify." << endl;
   cout << endl;

   cout << "original.txt is now being bubble sorted..." << endl; 
   sort_write(output_file, original, 19);   // sort function called
   cout << endl;
   cout << "early.txt is now being bubble sorted..." << endl;
   sort_write(output_file, early, 20);      // sort function called
   cout << endl;
   cout << "middle.txt is now being bubble sorted..." << endl;
   sort_write(output_file, middle, 20);     // sort function called
   cout << endl;
   cout << "end.txt is now being bubble sorted..." << endl;
   sort_write(output_file, end, 20);        // sort function called
   cout << endl;

   // Lastly, each array is now searched for a user-specified value using 
   // a binary search algorithm and the results are displayed
   cout << "Lastly, each array will be searched for a value you will"
        << endl;
   cout << "specify by using a binary search algorithm." << endl;
   cout << "What integer value would you like to search for?" << endl;

   target = validate_any_int();   // Input validated

   cout << "original.txt: ";
   binary_search(original, 19, target);  // binary search function called

   cout << "early.txt:    ";
   binary_search(early, 20, target);     // binary search function called

   cout << "middle.txt:   ";
   binary_search(middle, 20, target);    // binary search function called

   cout << "end.txt:      ";
   binary_search(end, 20, target);       // binary search function called
   cout << endl;
   cout << "OK, that's it, goodbye!\n";  // program ends!
   cout << endl;

   return 0;
}
