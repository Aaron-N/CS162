/*********************************************************************
** Program name:  Lab 3 (Game.cpp)
** Author:        Aaron Nesbit
** Date:          10/15/19
** Description:   This is the implementation file for the class Game
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"
#include "input_validation.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Player.hpp"

using std::cout;
using std::endl;

/* 
* Summary:  Default Constructor
*/
Game::Game(){}


/*
* Summary:    game_play() - this function contains the game logic.
*             It handles all the user input collection and holds
*             the process for the game rounds. It also posts round
*             by round statistics and the final results of the game,
*             and asks user if they'd like to play again or exit
*             upon completion
*/ 
void Game::game_play()
{
   int game_status; 
   int num_die_sides;
   int die_type;
   int game_rounds;

   // Ask user if they want to play game or exit 
   cout << "Welcome to Dice War!" << endl;
   cout << "Play game? (Enter 1)" << endl;
   cout << "Exit game? (Enter 2)" << endl;

   // User input validated
   game_status = integer_validator();
   while(game_status < 1 || game_status > 2)
   {
      cout << "Selection must be 1 or 2! Try again!" << endl;
      game_status = integer_validator();
   }

   // If user has selected 'play game', the program runs until
   // they choose to exit
   while(game_status == 1)
   {

      // If user has chosen to play, pointers to die objects for each
      // player created
      Die *die_one;
      Die *die_two;

   
      // User asked for number of sides for Player One die
      cout << "For Player One, how many sides does die have? "
           << "(choose at least 2)" << endl;
      // User input validated
      num_die_sides = integer_validator();
      while(num_die_sides < 2)
      {
         cout << "The die must have at least 2 sides! Try again1" << endl;
         num_die_sides = integer_validator();
      }
   

      // User asked what type of die Player One will use
      cout << "For Player One, what type of die will be used?" << endl;
      cout << "Normal die (Enter 1) or loaded die? (Enter 2) " << endl;
      // User input validated
      die_type = integer_validator();
      while(die_type < 1 || die_type > 2)
      {
         cout << "Selection must be 1 or 2! Try again!" << endl;
         die_type = integer_validator();
      }


      // Player One die object created, based on die type selected 
      if(die_type == 1)
      {
         die_one = new Die(num_die_sides);
      }
      else
      {
         die_one = new LoadedDie(num_die_sides);
      } 
 

      // User asked for number of sides for Player Two die
      cout << "For Player Two, how many sides does die have? "
           << "(choose at least 2)" << endl;
      // User input validated
      num_die_sides = integer_validator();
      while(num_die_sides < 2)
      {
         cout << "The die must have at least 2 sides! Try again!" << endl;
         num_die_sides = integer_validator();
      }
   

      // User asked what type of die Player Two will use
      cout << "For Player Two, what type of die will be used?" << endl;
      cout << "Normal die (Enter 1) or loaded die (Enter 2) " << endl;
      // User input validated
      die_type = integer_validator();
      while(die_type < 1 || die_type > 2)
      {
         cout << "Selection must be a 1 or 2! Try again!" << endl;
         die_type = integer_validator();
      }


      // Player Two die object created, based on die type selected
      if(die_type == 1)
      {
         die_two = new Die(num_die_sides);
      }
      else
      {
         die_two = new LoadedDie(num_die_sides);
      }


      // User asked to enter how many rounds of game to play
      cout << "How many rounds of play should this game last? " 
           << "(choose at least 1)" << endl;
      // User input validated
      game_rounds = integer_validator();
      while(game_rounds < 1)
      {
         cout << "You must play at least 1 round! Try again!" << endl;
         game_rounds = integer_validator();
      }


      // Player objects now created to hold die and game stats for
      // each player
      Player *player_one = new Player(die_one);
      Player *player_two = new Player(die_two);   

   
      // Random settings for dice rolls set 
      std::srand(std::time(NULL)); 


      // Player die sides and die types displayed before game begins
      cout << endl;
      cout << "Player One will be playing using a "
           << player_one->get_die_sides() << "-sided "
           << player_one->get_die_type() << " die" << endl;
      cout << "Player Two will be playing using a "
           << player_two->get_die_sides() << "-sided "
           << player_two->get_die_type() << " die" << endl;
      cout << "++++++++++++++++++++++++++++++++++++++++++++++++++"
           << endl;

      //++++++ CODE FOR ACTUAL GAME PLAY BEGINS HERE ++++++
   
      // Variables for rounds intitiated
      int player_one_roll;           // Player One roll result
      int player_two_roll;           // Player Two roll result
      int winner;                    // Winner of round result
      int counter = 1;                 // Current round number


      // Loop for a round of play
      do
      {
         // Round starts
         cout << "Round " << counter << " begins!" << endl;

         player_one_roll = player_one->roll();  // Player One die rolled
         player_two_roll = player_two->roll();  // Player Two die rolled

         if(player_one_roll > player_two_roll)      // Player One wins
         {
            player_one->win();
            player_two->lose();
            cout << "Player One rolls: " << player_one_roll << endl;
            cout << "Player Two rolls: " << player_two_roll << endl;
            cout << "Player One wins this round!" << endl;
            cout << "---------------------------" << endl;
         }
         else if(player_one_roll < player_two_roll) // Player Two wins
         {
            player_one->lose();
            player_two->win();
            cout << "Player One rolls: " << player_one_roll << endl;
            cout << "Player Two rolls: " << player_two_roll << endl;
            cout << "Player Two wins this round!" << endl;
            cout << "---------------------------" << endl;
         }
         else                                       // Round is a draw
         {
            player_one->draw();
            player_two->draw();
            cout << "Player One rolls: " << player_one_roll << endl;
            cout << "Player Two rolls: " << player_two_roll << endl;
            cout << "This round was a draw!" << endl;
            cout << "---------------------------" << endl; 
         }


         // Counter increases by 1
         counter++;

      }while(counter <= game_rounds);

 
      // Once game runs through specified number of rounds, final
      // results are displayed
      if(player_one->get_wins() > player_two->get_wins())
      {
         cout << "+++++++++++++++++++++++++++++++++" << endl;
         cout << "PLAYER ONE IS THE FINAL WINNER!!!" << endl;
         winner = 1;
      }
      else if(player_one->get_wins() < player_two->get_wins())
      {
         cout << "+++++++++++++++++++++++++++++++++" << endl;
         cout << "PLAYER TWO IS THE FINAL WINNER!!!" << endl;
         winner = 2;
      }
      else
      {
         cout << "+++++++++++++++++++++++++++++++++" << endl;
         cout << "THE GAME HAS ENDED A DRAW!!!" << endl;
      }

      cout << "Final stats:\n" << endl;
      cout << "Player One wins:   " << player_one->get_wins() << endl;
      cout << "Player One losses: " << player_one->get_losses() << endl;
      cout << "Player One draws:  " << player_one->get_draws() << endl
           << endl;
      cout << "Player Two wins:   " << player_two->get_wins() << endl;
      cout << "Player Two losses: " << player_two->get_losses() << endl;
      cout << "Player Two draws:  " << player_two->get_draws() << endl;
      cout << "+++++++++++++++++++++++++++++++++" << endl << endl;

      // Dynamically allocated objects are now deleted
      delete player_one;
      delete player_two;
      delete die_one;
      delete die_two;

      // Ask user is they would like to play again
      cout << "Would you like to play Dice War again?" << endl;
      cout << "Play again (Enter 1)" << endl;
      cout << "Exit game (Enter 2)" << endl;
      // User input validated
      game_status = integer_validator();
      while(game_status < 1 || game_status > 2)
      {
         cout << "Selection must be 1 or 2! Try again!" << endl;
         game_status = integer_validator();
      }
   }
   

   // If user has chosen to 'exit game' program terminates
   if(game_status == 2)
   {
      cout << "Goodbye!" << endl;
      std::exit(0);
   }

}
