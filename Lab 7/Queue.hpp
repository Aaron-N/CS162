/*********************************************************************
** Program name:  Lab 7 (Queue.hpp)
** Author:        Aaron Nesbit
** Date:          11/12/19
** Description:   This is the header file for the class Queue
*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP


struct QueueNode
{
   int val;
   QueueNode *next;
   QueueNode *prev;
 
   // Constructor
   QueueNode(int v, QueueNode *p = NULL, QueueNode *n = NULL)
   {
      val = v;
      prev = p;
      next = n;
   }
};

class Queue
{
   private: 
      QueueNode *head = NULL;

   public:
      Queue();                    // Default constructor
      ~Queue();                   // Destructor
      bool isEmpty();             // Check if queue is empty function
      void addBack(int val);      // Add new node to back function
      int getFront();             // Head node value getter
      void removeFront();         // Remove head node function
      void printQueue();          // Print the current queue function
      void menu();                // Main menu function
};

#endif
