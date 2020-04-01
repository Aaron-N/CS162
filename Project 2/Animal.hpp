/*********************************************************************
** Program name:  Program 2 (Animal.hpp)
** Author:        Aaron Nesbit
** Date:          10/21/19
** Description:   This is the heade file for the class Animal
*********************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

using std::string;

class Animal
{
   protected:
      int age;                     // Animal age variable
      int cost;                    // Animal cost variable
      int number_of_babies;        // Animal # of babies variable
      int base_food_cost;          // Animal base food cost variable
      int payoff;                  // Animal payoff variable
      string type;                 // Animal type variable

   public:
      Animal();                    // Default Constructor
      Animal(int);                 // Constructor with age
      ~Animal();                   // Destructor
      int get_age();               // Age getter function
      int get_cost();              // Cost getter function
      int get_number_of_babies();  // Number of babies getter function
      int get_base_food_cost();    // Base food cost getter function
      int get_payoff();            // Payoff getter function
      string get_type();           // Animal type getter function
      void age_one_day();          // Age animals by one day function
};

#endif
