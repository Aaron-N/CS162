/*********************************************************************
** Program name:  Lab 7 (Queue.cpp)
** Author:        Aaron Nesbit
** Date:          11/12/19
** Description:   This is the implementation file for the class Queue
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include "Queue.hpp"
#include "input_validation.hpp"

using std::cout;
using std::endl;

/*
* Summary: Default constructor
*/
Queue::Queue(){}


/*
* Summary: Destructor
*/
Queue::~Queue()
{
   // Any existing nodes are deleted
   while(!isEmpty())
   {
      removeFront();
   }
}


/*
* Summary: isEmpty() - checks if there are any values in the queue
*/
bool Queue::isEmpty()
{
   if(head == NULL)  // The queue is empty
   {
      return true;
   }
   else              // The queue is not empty
   {
      return false;
   }
}


/*
* Summary:   addBack() - adds a node to the back of the queue
* Parameter: user-entered integer value
*/
void Queue::addBack(int val)
{
   if(!isEmpty())       // If a node already exists
   {
      QueueNode *temp = head->prev;
      QueueNode *newNode = new QueueNode(val, head->prev, head);
      temp->next = newNode;
      head->prev = newNode;
   }
   else                 // If no node exists
   {
      head = new QueueNode(val);
      head->next = head;
      head->prev = head;
   }
}


/*
* Summary: getFront() - returns the current value of the head node
* Returns: value of the head node
*/
int Queue::getFront()
{
   if(!isEmpty())
   {
      return head->val;      // Current head value returned
   }
}


/*
* Summary: removeFront() - removes the current head node
*/
void Queue::removeFront()
{
   if(!isEmpty())            // If the queue is not empty
   {
      if(head->next == head) // If there is only one node
      {
         delete head;        // Head deleted
         head = NULL;        // Head pointer set to NULL
      }
      else
      {
         QueueNode *oldHead = head;  // Temp pointer to hold head
         head = head->next;          // Head set to next node
         head->prev = oldHead->prev; // New head previous set to
                                     // old head's previous
         oldHead->prev->next = head; // Old head's previous set to 
                                     // point to new head
         delete oldHead;             // Old head node deleted
      }
   }
   else       // The queue is empty
   {
      cout << "There is no front node to remove, the queue is empty!"
           << endl;
   }
}


/*
* Summary: printQueue() - prints the current values in the queue
*/
void Queue::printQueue()
{
   if(!isEmpty())
   {
      cout << "The current queue is:" << endl;
      cout << head->val << " ";        // Head is displayed first
      QueueNode *temp = head->next;
      while(temp != head) // Moves through queue until head is reached
      {
         cout << temp->val << " ";     // Value displayed
         temp = temp->next;            // temp pointer moved to next node
      }
      cout << endl;
   }
   else
   {
      cout << "There is nothing to display, the queue is currently "
           << "empty!" << endl;
   }
}


/*
* Summary: menu() - this is the main menu function
*/
void Queue::menu()
{
   while(true)
   {
      // The menu is displayed and the user makes a choice
      cout << endl;
      cout << "========================================" << endl;
      cout << "=====          Lab 7 Menu          =====" << endl;
      cout << "========================================" << endl;
      cout << "What would you like to do?              " << endl;
      cout << "1.  Add a value to the back of the queue" << endl;
      cout << "2.  Display the current front node value" << endl;
      cout << "3.  Remove the front node               " << endl;
      cout << "4.  Display the current queue           " << endl;
      cout << "5.  Exit the program                    " << endl;
      cout << endl;
      cout << "Your selection: ";

      int choice = int_validate_5_choice();

      switch(choice)
      {
         case 1:      // Add a value to the back of the queue
         {
            cout << "Enter the integer value you'd like to add:" << endl;
            int value = validate_any_int();
            addBack(value);
            break;
         }
         case 2:      // Display the front value
         {
            if(isEmpty())
            {
               cout << "There is no front node value to display,"
                    << " the queue is currently empty!" << endl;
            }
            else
            {
               cout << "The current value of the front node is "
                    << getFront() << endl;
            }
            break;
         }
         case 3:      // Remove the front node
         {
            if(!isEmpty())
            {
               cout << "The front node has been removed!" << endl;
            }
            removeFront();
            break;
         }
         case 4:      // Display the queue's contents
         {
            printQueue();
            break;
         }
         case 5:      // Exit the program
         {
            cout << "OK, goodbye!" << endl;
            cout << endl;
            return;
         }
      }
   }
}
