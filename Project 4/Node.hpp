/*********************************************************************
** Program name: Project 4 (Node.hpp)
** Author:       Aaron Nesbit
** Date:         11/19/19
** Description:  This is the header file for the class Node
*********************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

#include "Character.hpp"

class Node
{
   private:
      Character* player;                 // Pointer to character object
      Node* next;                             // Pointer to node object
      Node* prev;                             // Pointer to node object

   public:
      Node(Character* player, Node* next, Node* prev);   // Constructor
      Node(Character* player);                           // Constructor
      Node();                                            // Constructor
      Character* getPlayer();                 // Player getter function
      void setPlayer(Character* player);      // Player setter function
      Node* getNext();                     // Next node getter function
      void setNext(Node *next);            // Next node setter function
      Node* getPrev();                     // Prev node getter function
      void setPrev(Node *prev);            // Prev node setter function
};

#endif 
