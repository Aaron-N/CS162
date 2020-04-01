/*********************************************************************
** Program name:  Lab 6 (Doubly_Linked_List.cpp)
** Author:        Aaron Nesbit
** Date:          11/5/19
** Description:   This is the implementation file for the class
**                Doubly_Linked_List
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>

#include "Doubly_Linked_List.hpp"
#include "input_validation.hpp"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;

/*
* Summary: Default constructor
*/
Doubly_Linked_List::Doubly_Linked_List()
{
   this->head = NULL;
   this->tail = NULL;
}

/*
* Summary: Destructor
*/
Doubly_Linked_List::~Doubly_Linked_List(){}


/*
* Summary: set_head() - sets the head pointer to a node
*/
void Doubly_Linked_List::set_head(Node *head)
{
   this->head = head;
}


/*
* Summary: set_tail() - sets the tail pointer to a node
*/
void Doubly_Linked_List::set_tail(Node *tail)
{
   this->tail = tail;
}


/*
* Summary:   add_node_to_head() - adds a new node to the head of the list
* Parameter: an int value to place in the new node
*/
void Doubly_Linked_List::add_node_to_head(int value)
{
   // New node memory dynamically allocated 
   Node *n = new Node(value);

   // If this node is the first node, set 'head' to point at it
   if(head == NULL)
   {
      head = n;
   }
   else  // If head pointer points to existing node, make new node head
   {
      head->set_prev(n);  // Current head node has 'prev' set to new node
      n->set_next(head);  // 'Next' pointer of new node set to old head
      head = n;           // Head pointer now set to new node
   }

   // If this node is first node, set tail to point at it
   if(tail == NULL)
   {
      tail = n;
   }

   // Traverse function displays new linked list
   traverse();
}


/*
* Summary:   add_node_to_tail() - adds a new node to the tail of the list
* Parameter: an int value to place in the new node
*/
void Doubly_Linked_List::add_node_to_tail(int value)
{
   // New node memory dynamically allocated
   Node *n = new Node(value);

   // If this node is the first node, set 'tail' to point at it
   if(tail == NULL)
   {
      tail = n;
   }
   else  // If tail pointer points to existing node, make new node tail
   {
      tail->set_next(n);  // Current tail node has 'next' set to new node
      n->set_prev(tail);  // 'Prev' pointer of new tail set to old tail
      tail = n;           // Tail pointer now set to new node
   }

   // If this node is first node, set head to point at it
   if(head == NULL)
   {
      head = n;
   }

   // Traverse function displays updated linked list
   traverse();
} 


/*
* Summary: delete_first_node() - deletes the first node in the linked list
*/
void Doubly_Linked_List::delete_first_node()
{
   // If linked list is empty, notify user
   if(head == NULL)
   {
      cout << "There currently is no node at the head to delete" << endl;
   }
   // If only 1 node exists, delete it and set head/tail pointers to NULL
   else if(head == tail)
   {
      delete head;
      head = NULL;
      tail = NULL;
   }
   else
   {
      Node *temp = head->get_next(); // Temp pointer to hold future head
      delete head;                 // Current head node deleted
      temp->set_prev(NULL);        // 'Prev' of future head points to NULL
      head = temp;                 // Head points to new head node
      temp = NULL;                 // Temp pointer set to NULL
   }

   // Traverse function displays updated linked list
   traverse();
}  


/*
* Summary: delete_last_node() - deletes the last node in the linked list
*/
void Doubly_Linked_List::delete_last_node()
{
   // If linked list is empty, notify user
   if(tail == NULL)
   {
      cout << "There currently is no node at the tail to delete" << endl;
   }
   // If only 1 node exists, delete it and set head/tail pointers to NULL
   else if(tail == head)
   {
      delete tail;
      head = NULL;
      tail = NULL;
   }
   else
   {
      Node *temp = tail->get_prev(); // Temp pointer to hold future tail
      delete tail;                 // Current tail node deleted
      temp->set_next(NULL);        // 'next' of future tail points to NULL
      tail = temp;                 // Tail points to new tail node
      temp = NULL;                 // Temp pointer set to NULL
   }

   // Traverse function displays updated linked list
   traverse();
}  


/*
* Summary: reverse_traverse() - prints out linked list from tail to head
*/
void Doubly_Linked_List::reverse_traverse()
{
   if(head == NULL && tail == NULL) // If list empty, display message
   {
      cout << "Your current linked list is empty!" << endl;
   }
   else // If list contains nodes, list is displayed in reverse
   {
      cout << "-------------------------------------------------" << endl;
      cout << "Your current linked list traversed in reverse is: " << endl;
      
      Node *ptr = tail;

      while(ptr != NULL)
      {
         cout << ptr->get_value() << " ";
         ptr = ptr->get_prev();
      }
      cout << endl;
      cout << "-------------------------------------------------" << endl;
   }
}


/*
* Summary: traverse() - prints out linked list from head to tail
*/
void Doubly_Linked_List::traverse()
{
   if(head == NULL && tail == NULL) // If list is empty, display message
   {
      cout << "Your current linked list is empty!" << endl;
   }
   else // If list contains nodes, list is displayed
   {
      cout << "-------------------------------------------------" << endl;
      cout << "Your current linked list is: " << endl;
      
      Node *ptr = head;

      while(ptr != NULL)
      {
         cout << ptr->get_value() << " ";
         ptr = ptr->get_next();
      }
      cout << endl;
      cout << "-------------------------------------------------" << endl;
   }
}


/*
* Summary: make_list_from_file() - creates a linked list from the file 
*          file.txt
*/
void Doubly_Linked_List::make_list_from_file()
{
   // Text file opened
   ifstream input_file;
   input_file.open("list.txt", ios::in);

   if(input_file) // If input file found, proceed to create list
   {
      clear_nodes();  // Existing list cleared
      int count = 0;  // Counter for items in text file initiated
      while(input_file >> count)
      {
         // New node memory dynamically allocated
         Node *n = new Node(count);

         // If this node is the first node, set 'tail' to point at it
         if(tail == NULL)
         {
            tail = n;
         }
         else // If tail pointer points to existing node, make new node tail
         {
            tail->set_next(n); // Current tail node has 'next' set to
                               // new node
            n->set_prev(tail); // 'Prev' pointer of new tail set to old tail
            tail = n;          // Tail pointer now set to new node
         }

         // If this node is first node, set head to point at it
         if(head == NULL)
         {
            head = n;
         }
      }
   }

   // Text file closed
   input_file.close();
}


/*
* Summary: clear_nodes() - Deletes each node in the linked list and
*          frees dynamically allocated memory
*/
void Doubly_Linked_List::clear_nodes()
{
   // Temporary pointers set for current and next nodes in linked list
   Node *current = head;
   Node *next;

   // While the current node is not set to NULL
   while(current != NULL)
   {
      next = current->get_next(); // 'next' becomes the next node in list
      delete current;             // Current node is deleted
      current = next;             // Current node becomes next node in list
   }

   // Head and tail set to NULL
   head = NULL;
   tail = NULL;
} 


/*
* Summary: menu() - this is the menu function. The user is asked to
*          choose an option and then the selected process begins
*/
void Doubly_Linked_List::menu()
{
   while(true)
   {
      cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
      cout << "++              Welcome to Lab 6!              ++" << endl;
      cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
      cout << "Which linked list operation would you like to do?" << endl;
      cout << "   1. Add a new node to the head                 " << endl;
      cout << "   2. Add a new node to the tail                 " << endl;
      cout << "   3. Delete the first node in the list          " << endl;
      cout << "   4. Delete the last node in the list           " << endl;
      cout << "   5. Traverse the list in reverse               " << endl;
      cout << "   6. Print the value of the head node           " << endl;
      cout << "   7. Print the value of the tail node           " << endl;
      cout << "   8. Create the linked list from a text file    " << endl;
      cout << "   9. Exit Lab 6                                 " << endl;
      
      int choice = int_validate_9_choice();

      switch(choice)
      {
         case 1:   // Add a new node to the head
         {
            cout << "Enter the value for the node:" << endl;
            int input = validate_any_int();
            add_node_to_head(input);
            break;  
         }
         case 2:   // Add a new node to the tail
         {
            cout << "Enter the value for the node:" << endl;
            int input = validate_any_int();
            add_node_to_tail(input);
            break;
         }
         case 3:   // Delete the first node in the list
         {
            delete_first_node();
            break; 
         }
         case 4:   // Delete the last node in the list
         {
            delete_last_node();
            break;
         }
         case 5:   // Traverse the list in reverse
         {
            reverse_traverse();
            break;
         }
         case 6:   // Print the value of the head node
         {
            // If list is not empty
            if(head != NULL && tail != NULL)
            {
               cout << "The current value of the head node: "
                    << head->get_value() << endl;
            }
            // If list is empty
            else
            {
               cout << "The head node is currently empty!" << endl;
            }
            break;
         }
         case 7:   // Print the value of the tail node
         {
            // If list is not empty
            if(head != NULL && tail != NULL)
            {
               cout << "The current value of the tail node: "
                    << tail->get_value() << endl;
            }
            // If list is empty
            else
            {
               cout << "The tail node is currently empty!" << endl;
            }
            break;
         }
         case 8:   // Create the linked list from a text file
         {
            cout << "Any existing linked list will now be deleted"
                 << endl;
            cout << "New linked list now being created from file.txt!"
                 << endl;
            make_list_from_file(); // List created from txt file
            traverse();            // List is displayed
            break;
         }
         case 9:   // Exit Lab 6
         {
            cout << "OK, goodbye!" << endl;
            clear_nodes();         // Allocated memory freed
            exit(0);               // Program exited
         }
      }
   }
}
