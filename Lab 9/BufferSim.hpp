/*********************************************************************
** Program name:  Lab 9 (BufferSim.hpp)
** Author:        Aaron Nesbit
** Date:          11/29/19
** Description:   This is the header file for the buffer simulation
**                functions
*********************************************************************/

#ifndef BUFFERSIM_HPP
#define BUFFERSIM_HPP

#include <queue>

using std::queue;

// Function prototypes
void buffer_simulation();                 // Buffer simulator function
void print_buffer(queue <int> bufferIn);  // Buffer print function

#endif
