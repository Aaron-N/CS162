/*********************************************************************
** Program name:  Project 3 (Game.cpp)
** Author:        Aaron Nesbit
** Date:          11/7/19
** Description:   This is the implementation file for the class Game
*********************************************************************/

#include <iostream>
#include "Game.hpp"
#include "Character.hpp"
#include "input_validation.hpp"
#include "Barbarian.hpp"
#include "Blue_Men.hpp"
#include "Harry_Potter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"

using std::cout;
using std::endl;
using std::exit;


/*
* Summary: Constructor
*/
Game::Game()
{
   player_one = NULL;
   player_two = NULL;
}


/*
* Summary: Destructor
*/
Game::~Game(){}


/*
* Summary: menu() - this is the main menu for selecting characters
*/
void Game::menu()
{
   cout << "====================================================" << endl;
   cout << "Welcome to Fantasy Combat!" << endl;
   cout << "What would you like to do?" << endl;
   cout << "  1. Play the game        " << endl;
   cout << "  2. Exit the game        " << endl;
   cout << "====================================================" << endl;
   cout << "(Enter your choice)       " << endl;

   int selection = int_validate_2_choice();

   if(selection == 2)
   {
      cout << "OK, goodbye!" << endl;
      exit(0);
   }

   int player = 1;
   while(player <= 2)
   {
      cout << "===================================================="
           << endl;
      cout << "Which character would you like Player " << player 
           << " to fight as?     " << endl;
      cout << "   1. Vampire     " << endl;
      cout << "   2. Barbarian   " << endl;
      cout << "   3. Blue Men    " << endl;
      cout << "   4. Medusa      " << endl;
      cout << "   5. Harry Potter" << endl;
      cout << "===================================================="
           << endl;
   cout << "(Enter your choice)       " << endl;

      int choice = int_validate_5_choice();

      switch(choice)
      {
         case 1:
         {
            play_as_Vampire();
            break;
         }
         case 2:
         {
            play_as_Barbarian();
            break;
         }
         case 3:
         {
            play_as_Blue_Men();
            break;
         }
         case 4:
         {
            play_as_Medusa();
            break;
         }
         case 5:
         {
            play_as_Harry_Potter();
            break;
         }
      }
      player++;       
   }
   
   // Begin the battle
   fight();

   // Dynamically allocated memory is freed
   delete player_one;
   delete player_two;
   player_one = NULL;
   player_two = NULL;

   // Play/quit menu appears again
   cout << "What would you like to do now?" << endl;
   cout << "  1. Play again               " << endl;
   cout << "  2. Exit the game            " << endl;
   cout << "(Enter your choice)           " << endl;

   int replay = int_validate_2_choice();

   if(replay == 2)
   {
      cout << "OK, goodbye!" << endl;
      exit(0);
   }
   else
   {
      menu();
   }
}


/*
* Summary: play_as_Vampire() - creates a new Vampire object and assigns
*          it to either Player One or Player Two
*/
void Game::play_as_Vampire()
{
   if(player_one == NULL)
   {
      cout << "Player 1 has chosen to fight as a Vampire" << endl;
      player_one = new Vampire();
   }
   else
   {
      cout << "Player 2 has chosen to fight as a Vampire" << endl;
      player_two = new Vampire();
   }
}


/*
* Summary: play_as_Barbarian() - creates a new Barbarian object and assigns
*          it to either Player One or Player Two
*/
void Game::play_as_Barbarian()
{
   if(player_one == NULL)
   {
      cout << "Player 1 has chosen to fight as a Barbarian" << endl;
      player_one = new Barbarian();
   }
   else
   {
      cout << "Player 2 has chosen to fight as a Barbarian" << endl;
      player_two = new Barbarian();
   }
}


/*
* Summary: play_as_Blue_Men() - creates a new Blue Men object and assigns
*          it to either Player One or Player Two
*/
void Game::play_as_Blue_Men()
{
   if(player_one == NULL)
   {
      cout << "Player 1 has chosen to fight as Blue Men" << endl;
      player_one = new Blue_Men();
   }
   else
   {
      cout << "Player 2 has chosen to fight as Blue Men" << endl;
      player_two = new Blue_Men();
   }
}


/*
* Summary: play_as_Medusa() - creates a new Medusa object and assigns
*          it to either Player One or Player Two
*/
void Game::play_as_Medusa()
{
   if(player_one == NULL)
   {
      cout << "Player 1 has chosen to fight as Medusa" << endl;
      player_one = new Medusa();
   }
   else
   {
      cout << "Player 2 has chosen to fight as Medusa" << endl;
      player_two = new Medusa();
   }
}


/*
* Summary: play_as_Harry_Potter() - creates a new Harry Potter object
*          and assigns it to either Player One or Player Two
*/
void Game::play_as_Harry_Potter()
{
   if(player_one == NULL)
   {
      cout << "Player 1 has chosen to fight as Harry Potter" << endl;
      player_one = new Harry_Potter();
   }
   else
   {
      cout << "Player 2 has chosen to fight as Harry Potter" << endl;
      player_two = new Harry_Potter();
   }
}


/*
* Summary: fight() - runs the rounds of combat until one of the players
*          is dead
*/
void Game::fight()
{
   int round = 0;
   int attack_1;
   int attack_2;
   int defense;
      
   while(player_one->get_strength_points() > 0 &&
         player_two->get_strength_points() > 0)
   {
      round += 1;

      cout << "--------------------------------------------------" << endl;

      // Round number displayed
      cout << "Round " << round << ":" << endl;
      cout << "---------" << endl;
      
      // Attacker type displayed
      cout << "Attacker (Player 1) is " << player_one->get_type() << endl;

      // Defender type, armor and strength points displayed
      cout << "Defender (Player 2) is " << player_two->get_type()
           << " and has " << player_two->get_armor() << " armor and " 
           << player_two->get_strength_points() << " strength points"
           << endl;

      // Player 1 attacks
      attack_1 = player_one->attack();

      // Attacker attack dice roll displayed
      cout << player_one->get_type() << " rolls an attack of " << attack_1
           << endl;

      // Defender defends attack
      player_two->defend(attack_1);
      
      // Defender's updated strength points displayed
      cout << player_two->get_type() << "'s strength points now "
           << player_two->get_strength_points() << endl; 

      // If Player 2 still alive, Player 2 attacks
      if(player_two->get_strength_points() > 0)
      {    
         // Attacker type displayed
         cout << "Attacker (Player 2) is " << player_two->get_type()
              << endl;

         // Defender type, armor and strength points displayed
         cout << "Defender (Player 1) is " << player_one->get_type()
              << " and has " << player_one->get_armor() << " armor and " 
              << player_one->get_strength_points() << " strength points"
              << endl;

         // Player 2 attacks
         attack_2 = player_two->attack();

         // Attacker attack dice roll displayed
         cout << player_two->get_type() << " rolls an attack of "
              << attack_2 << endl;

         // Defender defends attack
         player_one->defend(attack_2);
      
         // Defender's updated strength points displayed
         cout << player_one->get_type() << "'s strength points now "
              << player_one->get_strength_points() << endl; 
      }
   }
 
   if(player_one->get_strength_points() <= 0)
   {
      cout << "+++++++++++++++++++++++++++++++++" << endl;
      cout << "+++ The battle is over!" << endl;
      cout << "+++ " << player_two->get_type() << " (Player 2) wins!"
           << endl;
      cout << "+++++++++++++++++++++++++++++++++" << endl; 
   }
   else if(player_two->get_strength_points() <= 0)
   {
      cout << "+++++++++++++++++++++++++++++++++" << endl; 
      cout << "+++ The battle is over!" << endl;
      cout << "+++ " << player_one->get_type() << " (Player 1) wins!"
           << endl;
      cout << "+++++++++++++++++++++++++++++++++" << endl; 
   }
}

