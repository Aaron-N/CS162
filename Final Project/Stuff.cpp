/*********************************************************************
** Program name:  Final Project (Stuff.cpp)
** Author:        Aaron Nesbit
** Date:          12/1/19
** Description:   This is the implementation file for the class Stuff
*********************************************************************/

#include "Stuff.hpp"

using std::string;

/*
* Summary: Constructor
*/
Stuff::Stuff(string name)
{
   this->name = name;
}


/*
* Summary: Destructor
*/
Stuff::~Stuff(){}


/*
* Summary: get_name() - name getter function
* Returns: name of thing Butthead gets
*/
string Stuff::get_name()
{
   return name;
}
