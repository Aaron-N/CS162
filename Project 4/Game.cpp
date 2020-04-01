/*********************************************************************
** Program name:  Project 4 (Game.cpp)
** Author:        Aaron Nesbit
** Date:          11/18/19
** Description:   This is the implementation file for the class Game
*********************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include "Game.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;

/*
* Summary:  Constructor
*/
Game::Game()
{
   // Default constructor sets up teams
  
   // Create Team One lineup
   team1 = new Queue;
   team1Score = 0;

   cout << endl;
   cout << "Setting up Team One..." << endl;
   cout << "How many fighters will Team Two have? (1 minimum)" << endl;
   int team1NumPlayers = validate_positive_int();
   cout << endl;

   // Add fighters to queue,then set types
   for(int i = 0; i < team1NumPlayers; i++)
   {
      Node* n = team1->addBack(NULL);

      cout << "Choose a character type:" << endl;
      cout << "1. Vampire              " << endl;
      cout << "2. Barbarian            " << endl;
      cout << "3. Blue Men             " << endl;
      cout << "4. Medusa               " << endl;
      cout << "5. Harry Potter         " << endl;

      int charType = int_validate_5_choice();

      switch(charType)
      {
         case 1:   // Vampire
         {
            n->setPlayer(new Vampire);
            break;
         }
         case 2:   // Barbarian
         {
            n->setPlayer(new Barbarian);
            break;
         }
         case 3:   // Blue Men
         {
            n->setPlayer(new BlueMen);
            break;
         }
         case 4:   // Medusa
         {
            n->setPlayer(new Medusa);
            break;
         }
         case 5:   // Harry Potter
         {
            n->setPlayer(new HarryPotter);
            break;
         }
      }
 
      // Prompt user for name of fighter
      cout << endl;
      cout << "Enter a name for this fighter:" << endl;
      string name;  //= getString();
      getline(cin, name);
      n->getPlayer()->setName(name);
      cout << endl; 
   }

   // Create Team Two lineup
   team2 = new Queue;
   team2Score = 0;

   cout << "Setting up Team Two..." << endl;
   cout << "How many fighters will Team Two have? (1 minimum)" << endl;
   int team2NumPlayers = validate_positive_int();
   cout << endl;

   // Add fighters to queue, then set types
   for(int i = 0; i < team2NumPlayers; i++)
   {
      Node* n = team2->addBack(NULL);
  
      cout << "Choose a character type:" << endl;
      cout << "1. Vampire              " << endl;
      cout << "2. Barbarian            " << endl;
      cout << "3. Blue Men             " << endl;
      cout << "4. Medusa               " << endl;
      cout << "5. Harry Potter         " << endl;

      int charType = int_validate_5_choice();

      switch(charType)
      {
         case 1:   // Vampire
         {
            n->setPlayer(new Vampire);
            break;
         }
         case 2:   // Barbarian
         {
            n->setPlayer(new Barbarian);
            break;
         }
         case 3:   // Blue Men
         {
            n->setPlayer(new BlueMen);
            break;
         }
         case 4:   // Medusa
         {
            n->setPlayer(new Medusa);
            break;
         }
         case 5:   // Harry Potter
         {
            n->setPlayer(new HarryPotter);
            break;
         }
      }

      // Prompt user for name of fighter
      cout << endl;
      cout << "Enter a name for this fighter:" << endl;
      string name;  //= getString();
      getline(cin, name);
      n->getPlayer()->setName(name);
      cout << endl;
   }
  
   // Create the Loser Pile
   loserPile = new Queue;

   // Start the tournament
   cout << endl;
   cout << "The Tournament begins!!!" << endl;
   runTournament();
}


/*
* Summary: Destructor
*/
Game::~Game()
{
   // Delete all queues
   delete team1;
   delete team2;
   delete loserPile;
}


/*
** Description: runTournament() - starts the tournament 
*/
void Game::runTournament()
{
   fight = 1;      // Fight count initialized
   do
   {
      runFight();  // Run the fight
      fight++;     // Add 1 to fight count
   }while(!team1->isEmpty() && !team2->isEmpty()); // Runs until a team
                                                   // queue is empty
                                   
   cout << "------------------------------------------" << endl;
   cout << "++++++++++++++++++++++++++++++++++++++++++" << endl; 
   cout << "The Tournament has ended!" << endl;
   cout << "Final scores:" << endl;
   cout << "Team One - " << team1Score << endl;
   cout << "Team Two - " << team2Score << endl;

   if(team1Score == team2Score)
   {
      cout << "The Tournament has ended in a tie!" << endl;
   }
   else if (team1Score > team2Score)
   {
      cout << "Team One wins!" << endl;
   }
   else if (team2Score > team1Score)
   {
      cout << "Team Two wins!" << endl;
   }
   cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;

   // Ask if user would like to see the Loser Pile  
   cout << endl;
   cout << "Would you like to see the Loser Pile?" << endl;
   cout << "1.  Yes" << endl;
   cout << "2.  No " << endl;

   int menuChoice = int_validate_2_choice(); 
   
   if (menuChoice == 1)
   {
      cout << endl;
      cout << "The Loser Pile:" << endl;
      loserPile->printList();
   }
}


/*
* Summary: runFight() - runs a fight between players from each team
*/
void Game::runFight()
{
   cout << "-------------------------------------------" << endl;
   cout << "FIGHT " << fight << endl << endl;
   round = 0;      // Reset round count
   
   // Get the players for fight
   player1 = team1->getFront();
   player2 = team2->getFront();
   cout << "Team One Fighter: " << player1->getName()
        << " (" << player1->getType() << ")" << endl;
   cout << " VS" << endl;
   cout << "Team Two Fighter: " << player2->getName()
        << " (" << player2->getType() << ")" << endl;
   
   bool everyoneAlive = true;
   
   do
   {
      everyoneAlive = runRound();
   }while(everyoneAlive);    // Fight runs until a player dies
}


/*
* Summary: runRound() - runs a round of combat
* Returns: returns true if both fighters are alive at end of round
*/
bool Game::runRound()
{
   bool everyoneAlive = true;
   round++;        // Round count increases by 1
   
   // Determine who attacks first (Team One on even rounds, Team Two on odd)
   if(fight % 2 == 0)
   {
      // Team One goes first
      int attackTotal = player1->attack(player2);
      player2->defend(attackTotal);
      
      if(player2->isAlive()) // If Player Two is still alive, they attack
      {
         attackTotal = player2->attack(player1);
         player1->defend(attackTotal);
         if(!player1->isAlive())  // If Player One dies, update status
         {
            everyoneAlive = false;
         }
       }
       else
       {
          everyoneAlive = false;
       }
   }
   else
   {
      // Team Two goes first
      int attackTotal = player2->attack(player1);
      player1->defend(attackTotal);
      
      if(player1->isAlive()) // If Player One is still alive, they attack
      {
         attackTotal = player1->attack(player2);
         player2->defend(attackTotal);
         if(!player2->isAlive())  // If Player Two dies, update status
         {
            everyoneAlive = false;
         }
      }
      else
      {
         everyoneAlive = false;
      }
   }

   if(!everyoneAlive)   // Runs if a player dies
   {
      if(player1->isAlive())           // Team One player wins 
      {
         cout << endl;
         cout << player1->getName() << " wins! Team One gets a point."
              << endl;
         loserPile->addBack(player2);  // Team Two player to loser pile
         
         player1->recover();           // Team One player heals
         team1->addBack(player1);      // Team One player to back of queue
         
         team1Score++;                 // Add a point to Team One score
      }
      else if (player2->isAlive())     // Team Two player wins
      {
         cout << endl;
         cout << player2->getName() << " wins! Team Two gets a point."
              << endl;
         
         loserPile->addBack(player1);  // Team One players to loser pile
         
         player2->recover();           // Team Two player heals
         team2->addBack(player2);      // Team Two player to back of queue
         
         team2Score++;                 // Add a point to Team Two score
      }
      
      // Remove current fighters from fronts of each queue
      team1->removeFront();
      team2->removeFront();

      // Set the players to NULL
      player1 = NULL;
      player2 = NULL;
   }
   return everyoneAlive;
}
