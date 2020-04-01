/*********************************************************************
** Program name:  Lab 6 (Node.cpp)
** Author:        Aaron Nesbit
** Date:          11/5/19
** Description:   This is the implementation file for the class Node
*********************************************************************/

#include "Node.hpp"

/*
* Summary: Default constructor
*/
Node::Node()
{
   this->next = NULL;
   this->prev = NULL;
}


/*
* Summary:    Constructor
* Parameter:  integer value to place in node
*/
Node::Node(int value)
{
   this->val = value;
   this->next = NULL;
   this->prev = NULL;
}


/*
* Summary: Destructor
*/
Node::~Node(){}


/*
* Summary: set_next() - sets 'next' pointer for this node
* Parameter:
*/
void Node::set_next(Node *next1)
{
   this->next = next1;
}


/*
* Summary: set_prev() - sets 'previous' pointer for this node
* Parameter:
*/
void Node::set_prev(Node *prev1)
{
   this->prev = prev1;
}


/*
* Summary: get_value() - returns the variable contained in a node
* Return:  integer value
*/
int Node::get_value()
{
   return this->val;
}


/*
* Summary: get_next() - returns the pointer to the next node
* Return:  pointer to next node
*/
Node* Node::get_next()
{
   return this->next;
}


/*
* Summary: get_prev() - returns the pointer to the previous node
* Return:  pointer to previous node
*/
Node* Node::get_prev()
{
   return this->prev;
}

