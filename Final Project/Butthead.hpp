/*********************************************************************
** Program name:  Final Project (Butthead.hpp)
** Author:        Aaron Nesbit
** Date:          11/30/19
** Description:   This is the header file for the class Butthead
*********************************************************************/

#ifndef BUTTHEAD_HPP
#define BUTTHEAD_HPP

#include <vector>
#include <iostream>
#include "Stuff.hpp"

using std::vector;
using std::string;

class Butthead
{
   private:
      vector<Stuff*> things;      // Vector to hold items declared
      int time;                   // Private variables declared
      bool found_Beavis;
      bool found_Stewart;
      bool show;

   public:
      Butthead();                           // Constructor
      ~Butthead();                          // Destructor
      void add_stuff_to_things(Stuff *);    // Add items to vector
      void get_things();                    // Get items in vector
      bool search_things(string);           // Search for item in vector
      int get_time();                       // Remainining game time getter
      int decrease_time(int);               // Time decrease function
      bool get_found_Beavis();              // If Beavis found yet getter
      bool set_found_Beavis();              // If Beavis found yet setter
      bool get_found_Stewart();             // If Stewart found yet getter 
      bool set_found_Stewart();             // If Stewart found yet setter
      bool get_show();     // Did Beavis and Butthead get into show getter  
      bool set_show();     // Did Beavis and Butthead get into show setter
};

#endif
