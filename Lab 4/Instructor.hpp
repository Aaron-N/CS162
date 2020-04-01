/*********************************************************************
** Program name:  Lab 4 (Instructor.hpp)
** Author:        Aaron Nesbit
** Date:          10/24/19
** Description:   This is the header file for the class Instructor
*********************************************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "Person.hpp"

using std::string;

class Instructor : public Person
{
   protected:
      double rating;
   
   public:
      Instructor();                // Default constructor
      Instructor(string, double);  // Constructor with name and rating
      virtual void print_info();   // Prints instructor information
      virtual void do_work();      // Instructor work hours generator
      virtual string get_name();   // Instructor name getter
};

#endif
