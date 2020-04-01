/*********************************************************************
** Program name:  Lab 8 (stream_functions.hpp)
** Author:        Aaron Nesbit
** Date:          11/19/19
** Description:   This is the headed file for the stream functions
**                for Lab 8.
*********************************************************************/

#ifndef STREAM_FUNCTIONS_HPP
#define STREAM_FUNCTIONS_HPP

using std::ifstream;
using std::string;
using std::ofstream;

// Function prototypes
void open_copy(ifstream&, string, int[]); // Open file & copy to array
void sort_write(ofstream&, int[], int); // Sort array &  create results file

#endif
