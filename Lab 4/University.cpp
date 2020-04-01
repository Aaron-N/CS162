/*********************************************************************
** Program name:  Lab 4 (University.cpp)
** Author:        Aaron Nesbit
** Date:          10/23/19
** Description:   This is the implementation file for the class 
**                University
*********************************************************************/

#include "University.hpp"
#include "input_validation.hpp"

using std::vector;
using std::cout;
using std::endl;
using std::exit;
using std::srand;
using std::time;

/*
* Summary: Default constructor
*/
University::University()
{
   name = "Oregon State University";
}

/*
* Summary: Destructor
*/
University::~University(){}

/*
* Summary: start()
*/
void University::start()
{
   int selection;

   // Start menu displayed
   cout << "Welcome to the OSU Information System simulation!" << endl;
   cout << "What would you like to do?" << endl;
   cout << "1. Begin simulation" << endl;
   cout << "2. Exit" << endl;

   selection = int_validate_2_choice();

   // Program exited if user chooses to
   if(selection == 2)
   {
      clear_vectors();
      cout << "Goodbye!" << endl;
      exit(0);
   }

   // If user chooses to begin simulation
   // Students, instructors and buildings instantiated
   Person *s1 = new Student("Aaron", 3.9); 
   Person *s2 = new Student("Bela", 2.5);
   Person *s3 = new Student("Elvira", 3.7);
   Person *s4 = new Student("Stephanie", 3.5);

   Person *i1 = new Instructor("Professor Albert", 4.9);
   Person *i2 = new Instructor("Instructor Grace", 4.5);

   Building *b1 = new Building("Goss Stadium", "430 SW Langton Pl",56386);
   Building *b2 = new Building("Autzen House", "811 SW Jefferson Ave",9674);
   Building *b3 = new Building("Clark Laboratory", "3260 SW Campus Way",
                               7987);
   Building *b4 = new Building("Kelley Engineering Center",
                               "110 SW Park Terrace", 152166);
   Building *b5 = new Building("Milne Computer Center",
                               "1800 SW Campus Way", 23441);

   add_person(s1);
   add_person(s2);
   add_person(s3);
   add_person(s4);
   add_person(i1);
   add_person(i2);
   add_building(b1);
   add_building(b2);
   add_building(b3);
   add_building(b4);
   add_building(b5);

   // Program loop
   while(true)
   {
      main_menu();
   } 
   
   clear_vectors();
}


/*
* Summary: main_menu() - User is given 4 options to choose from
*/
void University::main_menu()
{
   // Initiate randomization for ages of students and instructors
   srand(time(NULL));

   cout << "------------------------------" << endl;
   cout << "What would you like to do?" << endl;
   cout << "1. Print information about all the buildings" << endl;
   cout << "2. Print information of everyone at the University" << endl;
   cout << "3. Choose a person to do work" << endl;
   cout << "4. Exit the program" << endl;

   int choose = int_validate_4_choice();  // Input validation

   switch(choose)
   {
      case 1:     // Prints information about all buildings
      {
         print_building_info();
         break;
      }
      case 2:     // Prints information about all people
      {
         print_person_info();
         break;
      }
      case 3:     // Opens menu to choose who works
      {
         who_works_menu();
         break;
      }
      case 4:     // Exits program
      {
         clear_vectors();
         cout << "Goodbye!" << endl;
         exit(0);
      }
   }   
}


/*
* Summary:    add_building()- adds a building object to the Building vector
* Parameters: pointer to Building vector
*/
void University::add_building(Building *b)
{
   buildings.push_back(b);
}


/*
* Summary:    add_person()- adds a person object to the Person vector
* Parameters: pointer to Person vector
*/
void University::add_person(Person *p)
{
   people.push_back(p);
}


/*
* Summary: print_building_info() - prints out information for each
*          building in the vector of building objects
*/
void University::print_building_info()
{
   vector<Building*>::iterator it;    // Iterator declared
   int i = 0;

   cout << "Buildings at the University:" << endl;

   for(it = buildings.begin(); it != buildings.end(); it++, i++)
   {
      buildings.at(i)->print_info();
      cout << "------------------------------" << endl;
   }
}


/*
* Summary: print_person_info() - prints out information for each
*          person in the vector of person objects
*/
void University::print_person_info()
{
   vector<Person*>::iterator it;     // Iterator declared
   int i = 0;

   cout << "People at the University:" << endl;

   for(it = people.begin(); it != people.end(); it++, i++)
   {
      people.at(i)->print_info();
      cout << "------------------------------" << endl;
   }
}


/*
* Summary: who_works_menu() - Lists all the people at the university
*          and asks user to choose one of them to do work
*/
void University::who_works_menu()
{
   // List all people in person vector
   vector<Person*>::iterator it;
   int i = 0;
   int selection;

   cout << "People at the university:" << endl;
 
   // Names printed out
   for(it = people.begin(); it != people.end(); it++, i++)
   {
      cout << (i + 1) << ". " << people.at(i)->get_name() << endl;
   }

   cout << "Who would you like to do work?" << endl;

   selection = int_validate_6_choice();  // Input validated

   // Once person is selected, do work function runs
   people.at(selection - 1)->do_work();
}


/*
* Summary: clear_vectors() - clears building and person vectors and
*          deletes the pointers
*/
void University::clear_vectors()
{

   // Objects in building vector are cleared
   for(auto it = buildings.begin(); it != buildings.end(); ++it)
   {
      // Delete whatever value pointer at iterator's position points to
      delete *it;
   }
   buildings.clear();

   // Objects in people vector are cleared
   for(auto it = people.begin(); it != people.end(); ++it)
   {
      // Delete whatever value pointer at iterator's position points to
      delete *it;
   }
   people.clear(); 
}

