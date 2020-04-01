/*********************************************************************
** Program name:  Lab 4 (Student.hpp)
** Author:        Aaron Nesbit
** Date:          10/23/19
** Description:   This is the header file for the class Student
*********************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"

using std::string;

class Student : public Person
{
   protected:
      double GPA;

   public:
      Student();                   // Default constructor
      Student(string, double);     // Constructor with randomized age
      virtual void do_work();      // Work calculation function
      virtual void print_info();   //
      virtual string get_name();   //
};

#endif
