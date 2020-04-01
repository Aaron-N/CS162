/*********************************************************************
** Program name:  Lab 4 (Person.cpp)
** Author:        Aaron Nesbit
** Date:          10/24/19
** Description:   This is the implementation file for the class Person
*********************************************************************/

#include "Person.hpp"

using std::string;
using std::cout;
using std::endl;
using std::srand;
using std::time;

/*
* Summary: Default constructor
*/
Person::Person(){}


/*
* Summary: Constructor with name and random age
* Parameters: Person's name
*/
Person::Person(string name)
{
   this->name = name;
   srand(time(NULL));                    // For random age below
   this->age = (rand() % 32 + 1) + 18;   // 19-50 age window
}


/*
* Summary: Destructor
*/
Person::~Person(){}


/*
* Summary: print_info() - prints out all information related to this
*          class
*/
void Person::print_info()
{
   cout << "Name: " << name << endl;
   cout << "Age:  " << age << endl;
}


/*
* Summary: get_name() - gets name of person
* Returns: name of person
*/
string Person::get_name()
{
   return name;
}

