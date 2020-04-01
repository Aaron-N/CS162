/*********************************************************************
** Program name:  Lab 9 (BufferSim.cpp)
** Author:        Aaron Nesbit
** Date:          11/29/19
** Description:   This is the source file for the buffer simulation
**                function
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <queue>
#include "BufferSim.hpp"
#include "input_validation.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;
using std::queue;

/*
* Summary: buffer_simulation() - this function simulates a buffer. It
*          asks the user to specify how many rounds the simulation will
*          run, the percentage chance to put a randomly generated number
*          at the end of the buffer, and the percentage chance to take out
*          a randomly generated number from the front of the buffer.
*          Round results are displayed to the screen, along with the
*          current buffer length and the current average buffer length.
*/
void buffer_simulation()
{
   // Ask user how many rounds they would like to run simulation
   cout << endl;
   cout << "How many rounds of buffer simulation would you like to run?"
        <<endl;
   cout << "(Pick a reasonable number greater than 0 or you're going to"
        << endl;
   cout << " be doing a heck of a lot of scrolling to see what happened)"
        << endl;
   
   int rounds = validate_positive_int();

   // Ask user what percentage chance they want that the randomly
   // generated number N is added to the end of the buffer
   cout << endl;
   cout << "What percentage chance to put a randomly generated" << endl;
   cout << "number at the end of the buffer would you like?" << endl;
   cout << "(Enter an integer between 0 and 100)" << endl;

   int append_random = int_validate_0_to_100();

   // Ask user what percentage chance they want that the randomly
   // generated number N at the front of the buffer is removed
   cout << endl; 
   cout << "What percentage chance to remove a randomly generated" << endl;
   cout << "number from the front of the buffer would you like?" << endl;
   cout << "(Enter an integer between 0 and 100)" << endl;

   int remove_random = int_validate_0_to_100();

   cout << endl;

   // Variables declared for simulation rounds 
   int N;
   int appending_number;
   int removing_number;
   double average_length;

   // Queue created
   queue <int> buffer;

   for(int i = 0; i < rounds; i++)
   {
      cout << "Round " << (i + 1) << endl;
      cout << "-------------" << endl;

      N = rand() % 1000 + 1;      // Random number to be placed in queue

      // See if N will be added to the end of the buffer queue
      appending_number = rand() % 100 + 1;
      if(appending_number <= append_random)
      {
         cout << "Number appended to buffer" << endl;
         buffer.push(N);
      }
      else
      {
         cout << "Number not appended to buffer" << endl;
      }

      // See if the front number in the buffer queue is removed
      removing_number = rand() % 100 + 1;
      if(removing_number <= remove_random && !buffer.empty())
      {
         cout << "Removing number from front of buffer" << endl;
         buffer.front();
         buffer.pop();
      }      
      else
      {
         cout << "Number not removed from buffer" << endl;
      }
   
      // Print out current buffer
      print_buffer(buffer);    
  
      // Display buffer length
      cout << "Current buffer length = " << buffer.size() << endl;

      // Display average length of buffer
      cout << "Current average length of buffer = ";
      cout << fixed << setprecision(10);
      if(i > 0) // Average length for rounds 2 and higher
      {
         average_length = (average_length * i + buffer.size())
                          / (i + 1);
         cout << average_length;
      }
      else    // Average length equals buffer size in Round 1
      {
         average_length = buffer.size();
         cout << average_length;
      }
      cout << endl << endl;
   }
}


/*
* Summary:   print_buffer() - this function prints out the buffer for
*            each round
* Parameter: the queue the buffer is stored in
*/
void print_buffer(queue <int> bufferIn)
{
   // Print out current buffer
   cout << "Current buffer: " << endl;
   while(!bufferIn.empty())
   {
      cout << bufferIn.front() << " ";
      bufferIn.pop();
   }
   cout << endl;    
}
