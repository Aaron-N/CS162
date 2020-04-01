/*********************************************************************
** Program name:  Lab 4 (Building.cpp)
** Author:        Aaron Nesbit
** Date:          10/24/19
** Description:   This is the implementation file for the class Building
*********************************************************************/

#include <iostream>
#include <string>
#include "Building.hpp"

using std::string;
using std::cout;
using std::endl;

/*
* Summary: Default constructor
*/
Building::Building(){}

/*
* Summary: Constructor with building name, address and square footage
* Parameters: Building name
*             Building address
*             Building square footage
*/
Building::Building(string name, string address, int size)
{
   this->name = name;
   this->address = address;
   this->size = size;
}


/*
* Summary: Destructor
*/
Building::~Building(){}


/*
* Summary: print_info() - prints out all building information
*/
void Building::print_info()
{
   cout << "Name:    " << name << endl;
   cout << "Address: " << address << endl;
   cout << "Size:    " << size << " square feet" << endl;
}
