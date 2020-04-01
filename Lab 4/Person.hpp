/*********************************************************************
** Program name:  Lab 4 (Person.hpp)
** Author:        Aaron Nesbit
** Date:          10/23/19
** Description:   This is the header file for the class Person
*********************************************************************/

#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::string;

class Person
{
   protected:
      string name;
      int age;

   public:
      Person();                    // Default constructor
      Person(string);               // Constructor with name
      virtual ~Person();           // Destructor
      virtual void do_work() = 0;  // Work calculation function
      virtual void print_info();   //
      virtual string get_name();   //
};

#endif
