/*********************************************************************
** Program name:  Lab 3 (LoadedDie.hpp)
** Author:        Aaron Nesbit
** Date:          10/17/19
** Description:   This is the header file for the class LoadedDie
*********************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include "Die.hpp"

class LoadedDie : public Die
{
   public:
      LoadedDie(int);       // Constructor
      int roll();           // die roll function
                            // overloads funtion in Die.hpp
                            // when loaded die created
};

#endif
