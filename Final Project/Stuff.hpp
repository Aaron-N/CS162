/*********************************************************************
** Program name:  Final Project (Stuff.hpp)
** Author:        Aaron Nesbit
** Date:          12/1/19
** Description:   This is the header file for the class Stuff
*********************************************************************/

#ifndef STUFF_HPP
#define STUFF_HPP

#include <string>

using std::string;

class Stuff
{
   private:
      string name;                          // Private variable declared

   public:
      Stuff(string);                        // Constructor
      virtual ~Stuff();                     // Virtual destructor
      string get_name();                    // Name getter
};

#endif
