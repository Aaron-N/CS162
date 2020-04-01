/*********************************************************************
** Program name:  Project 4 (Game.hpp)
** Author:        Aaron Nesbit
** Date:          11/20/19
** Description:   This is the header file for the class Game
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Queue.hpp"
#include "InputValidation.hpp"

class Game
{
   private:
      Queue* team1;               // Pointer to Team One lineup
      Queue* team2;               // Pointer to Team Two lineup
      Queue* loserPile;           // Pointer to Loser Pile
      Character* player1;         // Pointer to character object (1)
      Character* player2;         // Pointer to character object (2)
      int fight;        
      int round;
      int team1Score;
      int team2Score;
      void runTournament();       // Tournament logic function
      void runFight();            // Fight logic function
      bool runRound();            // Round logic function

   public:
      Game();                     // Constructor
      ~Game();                    // Destructor
};

#endif 
