/*********************************************************************
** Program name:  Final Project (Burger_World.cpp)
** Author:        Aaron Nesbit
** Date:          12/2/19
** Description:   This is the implementation file for the class
**                Burger_World
*********************************************************************/

#include "Burger_World.hpp"
#include "Butthead.hpp"

using std::cout;
using std::endl;

/*
* Summary: Constructor
*/
Burger_World::Burger_World()
{
   up = NULL;
   down = NULL;
   left = NULL;
   right = NULL;
   place_number = 3;
}


/*
* Summary: description() - describes the place at the beginning of the turn
*/
void Burger_World::description()
{
   cout << "You are in the Lobby of Burger World." << endl;
}


/*
* Summary: place_options() - shows user the options and actions
*/
Space * Burger_World::place_options(Butthead *butthead)
{
   cout << "------------------------------" << endl;
   cout << "Options:                      " << endl;
   cout << "1. Go to the Manager's Office " << endl;
   cout << "2. Go to the Kitchen          " << endl;
   cout << "3. Go to the Dining Room      " << endl;
   cout << "4. Leave Burger World         " << endl;

   int counter = 1;

   while(true)
   {
      if(counter > 1)
      {
         cout << "------------------------------" << endl;
         cout << "Options:                      " << endl;
         cout << "1. Go to the Manager's Office " << endl;
         cout << "2. Go to the Kitchen          " << endl;
         cout << "3. Go to the Dining Room      " << endl;
         cout << "4. Leave Burger World         " << endl;
      }

      int choice = int_validate_multi_choice(4);

      switch(choice)
      {
         case 1:        // Go to the Manager's Office
         {
            cout << "You walk into the Manager's Office.\n";
            cout << "He's on the phone arguing with somebody about\n";
            cout << "Worker's Compensation or something.\n";
            cout << "Worker's Constipation. UH-HUH-HUH-HUH.\n";
            cout << "He waves you out.\n";
            cout << "You head back to the Lobby.\n";
            break;
         }
         case 2:        // Go to the Kitchen
         {
            cout << "You walk back into the Kitchen.\n";
            
            // If you haven't found Beavis yet
            if(!butthead->search_things("Beavis")
                              && butthead->get_found_Beavis() == false)
            {
               butthead->set_found_Beavis();     // Beavis found
               cout << "Burgers are smoking on the grill and the fryer\n";
               cout << "alarms are going off, but you don't see Beavis.\n";
               cout << "You hear a banging sound behind you. You turn\n";
               cout << "around and look and see Beavis waving at you\n";
               cout << "through the window of the freezer door. 'What\n";
               cout << "are you doing in there, buttmunch?' you ask.\n";
               cout << "'I'm locked in! You gotta find Stewart, he's\n";
               cout << "the only one that knows the code! He's at\n";
               cout << "school for some dumb meeting!' he screams.\n";
               cout << "What do you want to do?\n";
               cout << "-----------------------------\n";
               cout << "1. Leave                     \n";
               cout << "2. Try to guess the door code\n";
               int choice = int_validate_multi_choice(2);
               switch(choice)
               {
                  case 1:    // Leave and go find Stewart
                  {
                     cout << "You decide to leave.\n";
                     cout << "You head back to the Lobby.\n";
                     break;
                  }
                  case 2:    // Try to guess the door code
                  {
                     cout << "You decide to guess the door code.\n";
                     cout << "The key pad on the lock has the numbers\n";
                     cout << "0 through 9 on it. You know the code is\n";
                     cout << "always three digits long, but not 000.\n";
                     cout << "What's your guess?: ";
                     int guess = int_validate_multi_choice(999);
                     if(guess == 666)  // Door code guessed!
                     {
                        cout << "The door unlocks and Beavis is free!\n";
                        cout << "Get out of here!\n";
                        butthead->add_stuff_to_things(new Stuff("Beavis"));
                     }
                     else              // Door code wrong
                     {
                        cout << "Dammit, that didn't work!\n";
                        cout << "You need to go find Stewart and get\n";
                        cout << "the code from him!\n";
                        cout << "You head back out to the Lobby\n";
                     }
                     break;
                  }
               }
            }
            // If you already found Beavis but he's still locked in the 
            // freezer
            else if(!butthead->search_things("Beavis")
                                 && butthead->get_found_Beavis() == true)
            {
               cout << "Those burgers are beyond charred now.\n";
               cout << "Beavis is still locked in the freezer.\n";
               cout << "What do you want to do?\n";
               cout << "-----------------------------\n";
               cout << "1. Leave                     \n";
               cout << "2. Try to guess the door code\n";
               int choice = int_validate_multi_choice(2);
               switch(choice)
               {
                  case 1:    // Leave 
                  {
                     cout << "You decide to leave.\n";
                     cout << "You head back to the Lobby.\n";
                     break;
                  }
                  case 2:    // Try to guess the door code
                  {
                     cout << "You decide to guess the door code.\n";
                     cout << "The key pad on the lock has the numbers\n";
                     cout << "0 through 9 on it. You know the code is\n";
                     cout << "always three digits long, but not 000.\n";
                     cout << "What's your guess? ";
                     int guess = int_validate_multi_choice(999);
                     if(guess == 666)       // Door code guessed!
                     {
                        cout << "The door unlocks and Beavis is free!\n";
                        cout << "Get out of here!\n";
                        butthead->add_stuff_to_things(new Stuff("Beavis"));
                     }
                     else                   // Door code wrong
                     {
                        cout << "Dammit, that didn't work!\n";
                        cout << "You need to go find Stewart and get\n";
                        cout << "the code from him!\n";
                        cout << "You head back out to the Lobby\n";
                     }
                     break;
                  }     
               }
            }
            // If you already freed Beavis
            else if(butthead->search_things("Beavis"))
            {
               cout << "Uhhh...you already rescued Beavis!\n";
               cout << "Get out of here!\n";
               cout << "You head back out to the Lobby.\n"; 
            }
            break;
         }
         case 3:        // Go to the Dining Room
         {
            cout << "You walk into the Dining Room.\n";
            cout << "A lady is screaming and pointing down at her tray.\n";
            cout << "There's a rat sitting on it looking up at her.\n";
            cout << "'I'm gonna report this! This is a health violation!'"
                 << " she says!\n";
            cout << "'Yeah, the food here sucks!' you reply.\n";
            cout << "You head back to the Lobby.\n";
            break;
         }
         case 4:        // Leave Burger World
         {
            return right;
            break;
         }
      }
      counter++;
   }
}


/*
* Summary: set_up() - sets the up pointer to another space 
*/
void Burger_World::set_up(Space * place)
{
   up = place;
}


/*
* Summary: set_down() - sets the down pointer to another space
*/
void Burger_World::set_down(Space * place)
{
   down = place;
}


/*
* Summary: set_left() - sets the left pointer to another space
*/
void Burger_World::set_left(Space * place)
{
   left = place;
}


/*
* Summary: set_right() - sets the right pointer to another place
*/
void Burger_World::set_right(Space * place)
{
   right = place;
}


/*
* Summary: get_place_number() - returns the place number of the space
*/
int Burger_World::get_place_number()
{
   return place_number;
}
