/*********************************************************************
** Program name:  Final Project (Buttheads_House.cpp)
** Author:        Aaron Nesbit
** Date:          12/2/19
** Description:   This is the implementation file for the class
**                Buttheads_House
*********************************************************************/

#include "Buttheads_House.hpp"
#include "Butthead.hpp"
#include "Stuff.hpp"

using std::cout;
using std::endl;

/*
* Summary: Constructor
*/
Buttheads_House::Buttheads_House()
{
   up = NULL;
   down = NULL;
   left = NULL;
   right = NULL;
   place_number = 1;
}


/*
* Summary: description() - describes the place at the beginning of the turn
*/
void Buttheads_House::description()
{
   cout << "You're in your living room." << endl;
}


/*
* Summary: place_options() - shows user the options and actions
*/
Space * Buttheads_House::place_options(Butthead * butthead)
{
   cout << "------------------------------" << endl;
   cout << "Options:                      " << endl;
   cout << "1. Leave your House           " << endl;
   cout << "2. Go to your Room            " << endl;
   cout << "3. Go to the Kitchen          " << endl;
   cout << "4. Go Upstairs                " << endl;

   int counter = 1;

   while(true)
   {
      if(counter > 1)
      {
         cout << "------------------------------" << endl;
         cout << "Options:              " << endl;
         cout << "1. Leave your House   " << endl;
         cout << "2. Go to your Room    " << endl;
         cout << "3. Go to the Kitchen  " << endl;
         cout << "4. Go Upstairs        " << endl;
      }

      int choice = int_validate_multi_choice(4);

      switch(choice)
      {
         case 1:        // Head out to Street
         {
            cout << "You head out the front door.\n";
            return up;
            break;
         }
         case 2:        // Butthead's Bedroom
         {
            cout << "You walk into your bedroom.\n";
            if(!butthead->search_things("backpack"))
            {
               cout << "You grab your backpack.\n";
               butthead->add_stuff_to_things(new Stuff("backpack"));
               cout << "You pause and look up at the Carmen Electra\n";
               cout << "poster on the ceiling over your bed and whisper\n";
               cout << "'Come to Butthead' just like you always do.\n";
               cout << "You head back to the living room.\n";
            }
            else
            {
               cout << "You pause and look up at the Carmen Electra\n";
               cout << "poster on the ceiling over your bed and whisper\n";
               cout << "'Come to Butthead' just like you always do.\n";
               cout << "You head back to the living room.\n";
            }
            break;
         }
         case 3:        // The Kitchen
         {
            cout << "You walk into the kitchen. You've already eaten all\n";
            cout << "the good snacks, so there's no reason to hang out.\n";
            cout << "You head back to the living room.\n";
            break;
         }
         case 4:        // Upstairs
         {
            cout << "Your Mom's bedroom is up here. The door is closed\n";
            cout << "as usual. Huh. Does she even still live here? \n";
            cout << "You head back downstairs to the living room.\n"; 
            break;
         }
      }
      counter++;
   }
}


/*
* Summary: set_up() - sets the up pointer to another space 
*/
void Buttheads_House::set_up(Space * place)
{
   up = place;
}


/*
* Summary: set_down() - sets the down pointer to another space
*/
void Buttheads_House::set_down(Space * place)
{
   down = place;
}


/*
* Summary: set_left() - sets the left pointer to another space
*/
void Buttheads_House::set_left(Space * place)
{
   left = place;
}


/*
* Summary: set_right() - sets the right pointer to another place
*/
void Buttheads_House::set_right(Space * place)
{
   right = place;
}


/*
* Summary: get_place_number() - returns the place number of the space
*/
int Buttheads_House::get_place_number()
{
   return place_number;
}
