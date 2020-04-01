/*********************************************************************
** Program name:  Project 4 (Node.cpp)
** Author:        Aaron Nesbit
** Date:          11/19/19
** Description:   This is the implementation file for the class Node
*********************************************************************/

#include "Node.hpp"

/*
* Summary:    Constructor with 3 parameters
* Parameters: pointer to a Character object
*             pointer to a Node object
*             pointer to a Node object
*/
Node::Node(Character* player, Node *next, Node *prev)
{
   setPlayer(player);
   setNext(next);
   setPrev(prev);
}


/*
* Summary:   Constructor with 1 parameter
* Parameter: pointer to a Character object
*/
Node::Node(Character* player)
{
   setPlayer(player);
   setNext(NULL);
   setPrev(NULL);
}


/*
* Summary: Default constructor
*/
Node::Node()
{
   setPlayer(NULL);
   setNext(NULL);
   setPrev(NULL);
}


/*
* Summary: getPlayer() - player getter function
* Returns: player
*/
Character* Node::getPlayer()
{
   return player;
}


/*
* Summary:   setPlayer() - player setter function
* Parameter: pointer to a Character object
*/
void Node::setPlayer(Character* player)
{
   this->player = player;
}


/*
* Summary: getNext() - gets next node in the queue
* Returns: the next node in the queue
*/
Node* Node::getNext()
{
   return this->next;
}


/*
* Summary:   setNext() - sets the next node in the queue
* Parameter: pointer to a Node object
*/
void Node::setNext(Node *next)
{
   this->next = next;
}


/*
* Summary: getPrev() - gets previous node in the queue
* Returns: the previous node in the queue
*/
Node* Node::getPrev()
{
   return this->prev;
}


/*
* Summary:   setPrev() - sets the previous node in the queueu
* Parameter: pointer to a QueueNode object
*/ 
void Node::setPrev(Node *prev)
{
   this->prev = prev;
}
