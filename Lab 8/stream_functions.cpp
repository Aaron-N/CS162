/*********************************************************************
** Program name:  Lab 8 (stream_functions.cpp)
** Author:        Aaron Nesbit
** Date:          11/19/19
** Description:   This is the implementation file for the stream
**                functions for Lab 8.
*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "stream_functions.hpp"
#include "algorithms.hpp"

using std::ifstream;
using std::string;
using std::ofstream;
using std::cin;
using std::cout;
using std::endl;

/*
* Summary:    open_copy() - 
* Parameters: ifstream object
*             input file name
*             array of integers
*/
void open_copy(ifstream &input_file, string filename, int array[])
{
   input_file.open(filename.c_str());  // Open input file
   int value;
   int counter;

   if(!input_file) // If input file not found
   {
      cout << "Error opening file" << endl;
   }
   else            // If input file is found
   {
      counter = 0;
      while(input_file >> value)
      {
         array[counter] = value;
         counter++;
      }
   }

   input_file.close();  // Close input file
}

/*
* Summary:    sort_write()
* Parameters: ofstream object
*             array of integers
*             size of array
*/
void sort_write(ofstream &output_file, int array[], int size)
{
   string filename;
   cout << "Enter output file name(.txt):" << endl;
   getline(cin, filename);     // Get output file name from user

   output_file.open(filename); // Create the output file

   bubble_sort(array, size);   // Bubble sort the array

   cout << filename << ":  ";  // Display the output file name
   for(int i = 0; i < size; i++) 
   {
      cout << array[i] << " "; // Display the sorted array on screen
      output_file << array[i] << " "; // Save sorted array to output file
   }
   cout << endl;
   output_file.close();        // Close the output file
} 
