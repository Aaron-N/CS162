/*********************************************************************
** Program name:  Project 2 (Zoo.hpp)
** Author:        Aaron Nesbit
** Date:          10/21/19
** Description:   This is the header file for the class Zoo
*********************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"

class Zoo
{
   private:
      Animal **tigers;
      Animal **penguins;
      Animal **turtles;
      int tiger_array_size;
      int penguin_array_size;
      int turtle_array_size;
      int bank;
      int attendance_bonus;

   public:
      Zoo();                      // Default constructor
      ~Zoo();                     // Destructor
      void add_animal(Animal *);  // Function adds animal to array
      bool is_array_full(Animal **, int); // Checks if array is full
      void resize_array(Animal **&, int&); // Doubles array sizes
      void add_tiger(Animal *);   // Adds tiger to tiger array
      void add_penguin(Animal *); // Adds penguin to penguin array
      void add_turtle(Animal *);  // Adds turtle to turtle array
      void print_animals();       // Prints out all animals in zoo
      void play_game();           // Plays game 
      int get_bank_balance();     // Bank balance getter function
      void make_payment(int);     // Subtracts payment from bank balance
      void get_paid(int);         // Adds payment to bank balance
      void buy_animal_menu();     // Menu for initial animal purchases
      void buy_tiger_menu();      // Menu for initial tiger purchase
      void buy_penguin_menu();    // Menu for initial penguin purchase
      void buy_turtle_menu();     // Menu for initial turtle purchase
      void age_all_animals();     // Ages all animals 1 day
      int calc_feeding_costs();   // Calculates cost to feed all animals
      void random_event();        // Rolls a random daily event
      void sick_animal();         // Random animal gets sick
      void attendance_boom();     // Random boom in attendance
      void baby_born();           // Random animal born
      void tiger_dies();          // Tiger dies function
      void penguin_dies();        // Penguin dies function
      void turtle_dies();         // Turtle dies function
      void buy_adult_animal();    // Buys an adult animal
      int calc_payoff();          // Calculates daily payoff for animals
      void delete_arrays();       // Deletes animal arrays
};

#endif
