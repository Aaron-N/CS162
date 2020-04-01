/*********************************************************************
** Program name:  Lab 4 (Student.cpp)
** Author:        Aaron Nesbit
** Date:          10/23/19
** Description:   This is the implementation file for the class Student
*********************************************************************/

#include "Student.hpp"

using std::string;
using std::cout;
using std::endl;

/*
* Summary: Default constructor
*/
Student::Student(){}


/*
* Summary:    Constructor
* Parameters: User-defined name
*             User-defined GPA
*             Random age
*/
Student::Student(string name, double GPA)
{
   this->name = name;
   this->GPA = GPA;
   this->age = (rand() % 32 + 1) + 18;  // Random age generator
}


/*
* Summary: do_work() - a virtual function that generates a random number
*          of hours that a student does homework
*/
void Student::do_work()
{
   cout << name << " did " << (rand() % 6 + 1) << " hour(s) of homework"
        << endl;
}


/*
* Summary: print_info() - a virtual function that prints out the student's
*          name, age and GPA
*/
void Student::print_info()
{
   cout << "Name: " << name << endl;
   cout << "Age:  " << age << endl;
   cout << "GPA:  " << GPA << endl;
}


/*
* Summary: get_name() - a virtual function that gets the name of the
*          student
*/
string Student::get_name()
{
   return name;
}  
