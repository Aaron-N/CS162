/*********************************************************************
** Program name:  Lab 4 (Instructor.cpp)
** Author:        Aaron Nesbit
** Date:          10/24/19
** Description:   This is the implementation file for the class
**                Instructor
*********************************************************************/

#include "Instructor.hpp"

using std::string;
using std::cout;
using std::endl;

/*
* Summary: Default constructor
*/
Instructor::Instructor(){}


/*
* Summary:    Constructor with name and rating
* Parameters: Instructor name
*             Instructor rating
*/
Instructor::Instructor(string name, double rating)
{
   this->name = name;
   this->age = (rand() % 30 + 1) + 29;     //  30-60 random age

   // Ensuring that rating is in the 0.0 to 5.0 range
   if(rating > 5.0)
   {
      this->rating = 5.0;
   }
   else if(rating < 0.0)
   {
      this->rating = 0.0;
   }
   else
   {
      this->rating = rating;
   }
}


/*
* Summary: print_info() - prints out all information related to instructor
*/
void Instructor::print_info()
{
   cout << "Name:   " << name << endl;
   cout << "Age:    " << age << endl;
   cout << "Rating: " << rating << endl;
}


/*
* Summary: do_work() - generates random hours instructor does work and
*          then prints them out
*/
void Instructor::do_work()
{
   cout << name << " graded papers for " << (rand() % 8 + 2) << " hours"
        << endl;
}


/*
* Summary: get_name() - gets name of instructor
* Returns: name of instructor
*/
string Instructor::get_name()
{
   return name;
}
