/*********************************************************************
** Program name:  Lab 6 (Node.hpp)
** Author:        Aaron Nesbit
** Date:          11/5/19
** Description:   This is the header file for the class Node
*********************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>

class Node
{
   private:
      Node* next;              // Pointer to the next Node object
      Node* prev;              // Pointer to the previous Node object
      int val;                 // Integer value the specific Node contains

   public:
      Node();                  // Constructor
      Node(int);               // Constructor with integer value
      ~Node();                 // Destructor
      void set_next(Node *);   // 'next' pointer setter function
      void set_prev(Node *);   // 'prev' pointer setter function
      int get_value();         // Node value getter function
      Node* get_next();        // 'next' pointer getter function
      Node* get_prev();        // 'prev' pointer getter function
};

#endif
