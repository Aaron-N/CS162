/*********************************************************************
** Program name:  Lab 4 (University.hpp)
** Author:        Aaron Nesbit
** Date:          10/23/19
** Description:   This is the header file for the class University
*********************************************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <string>
#include <vector>
#include "Building.hpp"
#include "Student.hpp"
#include "Instructor.hpp"

using std::string;
using std::vector;

class University
{
   private:
      string name;
      vector<Building*> buildings;
      vector<Person*> people;

   public:
      University();                 // Constructor
      ~University();                // Destructor
      void start();                 // Initialization of program
      void main_menu();             // Main menu for program
      void add_building(Building*); // Adds pointers to Building objects
      void add_person(Person*);     // Adds pointers to Person objects
      void print_building_info();   // Prints info for all buildings
      void print_person_info();     // Prints info of all people
      void who_works_menu();        // Menu that chooses who works
      void clear_vectors();         // Clears pointers from vectors

};

#endif
