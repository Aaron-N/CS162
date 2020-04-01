/*********************************************************************
** Program name:  Project 4 (Queue.hpp)
** Author:        Aaron Nesbit
** Date:          11/19/19
** Description:   This is the header file for the class Queue
*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Character.hpp"
#include "Node.hpp"

class Queue
{
   private:
      Node* head;
      void setHead(Node* n);

   public:
      Queue();                                             // Constructor
      ~Queue();                                             // Destructor
      Node* addBack(Character *playerPtr = NULL);     // Add node to back
      bool removeFront();                   // Remove front node function
      void printItem(Node* item);                  // Print item function
      void printList();                            // Print list function
      Node* getHead();                            // Head getter function
      Character* getFront();                // Front node getter function
      void clearList();                            // Clear list function
      bool isEmpty();                      // List empty checker function 
};

#endif
