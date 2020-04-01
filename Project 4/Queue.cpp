/*********************************************************************
** Program name:  Project 4 (Queue.cpp)
** Author:        Aaron Nesbit
** Date:          11/19/19
** Description:   This is the implementation file for the class Queue
*********************************************************************/

#include <iostream>
#include "Queue.hpp"

using std::cin;
using std::cout;
using std::endl;

/*
* Summary: Constructor
*/
Queue::Queue()
{
   setHead(NULL);
}


/*
* Summary: Destructor
*/
Queue::~Queue()
{
   clearList();
}


/*
* Summary: clearList() - deletes all items in the queue
*/
void Queue::clearList()
{
   if (!isEmpty())      // only runs if queue contains items
   {
      Node* n = getHead();
      do
      {
         // temp pointer created pointing to node to be deleted
         Node* garbage = n;
         // Move on to the next node
         n = n->getNext();
         // Delete the garbage node's player if it exists
         if (garbage->getPlayer() != NULL)
         {
            delete garbage->getPlayer();
         }
         // Delete the garbage node
         delete garbage;
      }while(n != NULL && n != getHead());
   }
}


/*
* Summary: addBack() - adds a new node to the back of the queue
* Retruns: a new node
*/
Node * Queue::addBack(Character *playerPtr)
{
   Node* n = new Node(playerPtr);
   if(isEmpty())   // If head does not exist yet, set head
   {
      setHead(n);
   }
   else            // If head already exists
   {
      Node* h = getHead();
      // Set the node's next to the current head
      n->setNext(h);
      // Define a pointer the current back of the queue
      Node *oldBack = h->getPrev();
      // Set the node's prev to the current back
      n->setPrev(oldBack);
      // Set the old back's next to the new node
      oldBack->setNext(n);
      // Update the head node's prev
      h->setPrev(n);
   }
   return n;
}


/*
* Summary: removeFront() - deletes the first node in queue
* Returns: true if a node was deleted
*/
bool Queue::removeFront()
{
   bool deleteResult = false;     // Initial status set
   if(!isEmpty())       // If queue is not empty, this runs
   {
      Node* h = getHead();
      Node* newHead = NULL;
      newHead = h->getNext();
      if(newHead != h)
      {
         // If this isn't the last item in the list
         newHead->setPrev(h->getPrev());
         // Set the last item's next to the new head
         // if there's more than one item in the queue
         Node* l = h->getPrev();
         l->setNext(newHead);
         // Set the head directly
         head = newHead;
      }
      else
      {
         setHead(NULL);
      }
      delete h;              // Head is deleted
      deleteResult = true;   // Status set to true
   }
   return deleteResult;      // Status returned
}


/*
* Summary: printItem() - displays a single item from the queue
* Parameter: a pointer to a node
*/
void Queue::printItem(Node *item)
{
   if(item != NULL)     // If a node exists, this runs
   {
      cout << item->getPlayer()->getName() << endl;
   }
}


/*
* Summary: printList() - prints the queue
*/
void Queue::printList()
{
   if(isEmpty())   // If queue empty, warning is displayed
   {
      cout << "This queue is empty." << endl << endl;
   }
   else
   {
      Node* n = getHead();
      do
      {
         // Print the value
         printItem(n);
         // Move on to the next
         n = n->getNext();
      }while(n != getHead());
      cout << endl;
   }
}


/*
* Summary: getHead() -  returns the first node in the queue
* Returns: first node in the queue
*/
Node *Queue::getHead()
{
   return head;
}


/*
* Summary:   setHead() - function to set the head of the queue
* Parameter: a pointer to the new head
*/
void Queue::setHead(Node *n)
{
   if(n != NULL)   // This only runs if n exists
   {
      if(isEmpty())
      {
         // If queue was empty, point everything to head
         n->setPrev(n);
         n->setNext(n);
      }
      else
      {
         // Set next of the new head to the old head if one exists
         n->setNext(head);
         n->setPrev(head->getPrev());
         // Set prev of the old head to n
         head->setPrev(n);
      }
   }
   head = n;       // Set the new head
}


/*
* Summary: isEmpty() - returns true if the queue is empty
* Returns: if queue is empty or not
*/
bool Queue::isEmpty()
{
   return getHead() == NULL;
}


/*
* Summary: getFront() - returns the value in the first node of the queue
* Returns: first node, if it exists
*/
Character* Queue::getFront()
{
   Character* result = NULL;
   if(!isEmpty())
   {
      result = getHead()->getPlayer();
   }
   return result;
}
