/*********************************************************************
** Program name:  Lab 6 (Doubly_Linked_List.hpp)
** Author:        Aaron Nesbit
** Date:          11/5/19
** Description:   This is the header file for the class Doubly_Linked_List
*********************************************************************/

#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include "Node.hpp"

class Doubly_Linked_List
{
   private:
      Node *head;                  // Pointer to first Node in list
      Node *tail;                  // Pointer to last Node in list

   public:
      Doubly_Linked_List();        // Constructor
      ~Doubly_Linked_List();       // Destructor
      void set_head(Node *);       // Set head pointer to a Node function
      void set_tail(Node *);       // Set tail pointer to a Node function
      void add_node_to_head(int);  // Add node to list head function
      void add_node_to_tail(int);  // Add node to list tail function
      void delete_first_node();    // Delete first node from list function
      void delete_last_node();     // Delete last node from list function
      void reverse_traverse();     // Reverse and display list function
      void traverse();             // Display list function
      void make_list_from_file();  // Make a list from txt file function
      void clear_nodes();          // Clear all nodes function
      void menu();                 // Program menu function
};

#endif
