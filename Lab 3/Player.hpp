/*********************************************************************
** Program name:  Lab 3 (Player.hpp)
** Authot:        Aaron Nesbit
** Date:          10/17/19
** Description:   This is the header file for the class Player
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Die.hpp"
#include "LoadedDie.hpp"

using std::string;

class Player
{
   private:
      Die *selected_die;     // Pointer to die object
      int wins;              // Variable to store win count
      int losses;            // Variable to store loss count
      int draws;             // Variable to store draw count

   public:
      Player(Die *die);      // Constructor
      ~Player();             // Destructor
      int get_die_sides();   // Getter that returns # sides from die object
      string get_die_type(); // Getter that returns die type from die object
      int roll();            // Getter that returns roll from die object
      void win();            // Function that adds 1 to player win count
      void lose();           // Function that adds 1 to player loss count
      void draw();           // Function that adds 1 to player draw count
      int get_wins();        // Getter that returns # of player wins
      int get_losses();      // Getter that returns # of player losses
      int get_draws();       // Getter that returns # of player draws
};

#endif
