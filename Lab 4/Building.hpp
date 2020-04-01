/*********************************************************************
** Program name:  Lab 4 (Building.hpp)
** Author:        Aaron Nesbit
** Date:          10/24/19
** Description:   This is the header file for the class Building
*********************************************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP

// #include <iostream>
// #include <string>

using std::string;

class Building
{
   private:
      string name;                   // Building name
      string address;                // Building address
      int size;                      // Building square footage

   public:
      Building();                    // Default constructor
      Building(string, string, int); // Construct with name, address, size
      ~Building();                   // Destructor
      void print_info();             // Prints building info
};

#endif
