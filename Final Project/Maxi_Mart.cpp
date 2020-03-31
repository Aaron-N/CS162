/*********************************************************************
** Program name:  Final Project (Maxi_Mart.cpp)
** Author:        Aaron Nesbit
** Date:          12/2/19
** Description:   This is the implementation file for the class
**                Maxi_Mart
*********************************************************************/

#include "Maxi_Mart.hpp"

using std::cout;
using std::endl;

/*
* Summary: Constructor
*/
Maxi_Mart::Maxi_Mart()
{
   up = NULL;
   down = NULL;
   left = NULL;
   right = NULL;
   place_number = 5;
}


/*
* Summary: description() - describes the place at the beginning of the turn
*/
void Maxi_Mart::description()
{
   cout << "You're standing in front of the Maxi-Mart." << endl;
}


/*
* Summary: place_options() - shows user the options and actions
*/
Space * Maxi_Mart::place_options(Butthead *butthead)
{
   cout << "------------------------------" << endl;
   cout << "Options:                      " << endl;
   cout << "1. Go inside the Maxi-Mart    " << endl;
   cout << "2. Leave the Maxi-Mart        " << endl;
   cout << "3. Talk to Todd & Gina        " << endl;
   cout << "4. Head next door to the Gwar Show" << endl;

   int counter = 1;

   while(true)
   {
      if(counter > 1)
      {
         cout << "------------------------------" << endl;
         cout << "Options:                      " << endl;
         cout << "1. Go inside the Maxi-Mart    " << endl;
         cout << "2. Leave the Maxi-Mart        " << endl;
         cout << "3. Talk to Todd & Gina        " << endl;
         cout << "4. Head next door to the Gwar Show" << endl;
      }

      int choice = int_validate_multi_choice(4);

      switch(choice)
      {
         case 1:        
         {
            cout << "You walk into the Maxi-mart.\n";
            cout << "It's just like a 7-11 but cooler.\n";
            cout << "The Owner is behind the register glaring at you\n";
            cout << "as usual, even though you and Beavis haven't\n";
            cout << "tried to pick up chicks there in like a week.\n";
            cout << "You walk over and look at the nachos, but they're\n";
            cout << "stale and full of bugs as usual. GROSS.\n";
            cout << "You head back outside.\n";
            break;
         }
         case 2:        // To Street
         {
            cout << "You leave the Maxi-Mart.\n";
            return down; 
            break;
         }
         case 3:
         {
            cout << "You walk over to Todd & Gina, They're sitting on\n";
            cout << "the hood of Todd's green Plymouth Duster.\n";
            cout << "Todd's cool. 'What do YOU want?' he says to you.\n";
            cout << "'Just give him a dollar to make him go away!'\n";
            cout << "Gina says, without hesitation. You really want\n";
            cout << "to join his gang someday, so you leave before\n";
            cout << "he gets mad and kicks your ass.\n";
            break;
         }
         case 4:        // To Gwar Show
         {
            cout << "You head next door to the Gwar Show.\n";
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
void Maxi_Mart::set_up(Space * place)
{
   up = place;
}


/*
* Summary: set_down() - sets the down pointer to another space
*/
void Maxi_Mart::set_down(Space * place)
{
   down = place;
}


/*
* Summary: set_left() - sets the left pointer to another space
*/
void Maxi_Mart::set_left(Space * place)
{
   left = place;
}


/*
* Summary: set_right() - sets the right pointer to another place
*/
void Maxi_Mart::set_right(Space * place)
{
   right = place;
}


/*
* Summary: get_place_number() - returns the place number of the space
*/
int Maxi_Mart::get_place_number()
{
   return place_number;
}
