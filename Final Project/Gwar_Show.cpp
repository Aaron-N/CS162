/*********************************************************************
** Program name:  Final Project (Gwar_Show.cpp)
** Author:        Aaron Nesbit
** Date:          12/2/19
** Description:   This is the implementation file for the class
**                Gwar_Show
*********************************************************************/

#include "Gwar_Show.hpp"

using std::cout;
using std::endl;

/*
* Summary: Constructor
*/
Gwar_Show::Gwar_Show()
{
   up = NULL;
   down = NULL;
   left = NULL;
   right = NULL;
   place_number = 6;
}


/*
* Summary: description() - describes the place at the beginning of the turn
*/
void Gwar_Show::description()
{
   cout << "You're outside in front of the Gwar Show." << endl;
}


/*
* Summary: place_options() - shows user the options and actions
*/
Space * Gwar_Show::place_options(Butthead *butthead)
{
 /*  cout << "--------------------------------" << endl;
   cout << "Options:                        " << endl;
   cout << "1. Try to sneak in the side door" << endl;
   cout << "2. Go talk to Rabid Ron         " << endl;
   cout << "3. Go to the Maxi-Mart          " << endl;
   cout << "4. Go into the Show             " << endl;
*/
   int counter = 1;

   while(true)
   {
      if(butthead->get_show() == false)
      {
         cout << "--------------------------------" << endl;
         cout << "Options:                        " << endl;
         cout << "1. Try to sneak in the side door" << endl;
         cout << "2. Go talk to Rabid Ron         " << endl;
         cout << "3. Go to the Maxi Mart          " << endl;
         cout << "4. Go into the Show             " << endl;
      }
      else
      {
         return left;
      }

      int choice = int_validate_multi_choice(4);

      switch(choice)
      {
         case 1:        // Try to sneak in side door        
         {
            if(!butthead->search_things("Beavis"))
            {
               cout << "You feel bad about sneaking in without\n";
               cout << "Beavis, so you head back to the front.\n"; 
            }
            if(butthead->search_things("Beavis"))
            {
               cout << "You guys pull on the door handle as hard\n";
               cout << "as you can but it won't budge. Oh well.\n";
               cout << "You and Beavis head back to the front.\n";
            } 
            break;
         }
         case 2:        // Talk to Rabid Ron
         {
            if(butthead->search_things("backstage passes"))
            {
               cout << "You guys already won the passes!\n";
               cout << "Go into the freaking show already!\n";
            }
            else if(!butthead->search_things("Beavis"))
            {
               cout << "You start walking up to Rabid Ron when\n";
               cout << "you notice a sign that says only groups\n";
               cout << "of 2 can win the backstage passes. Dammit!\n";
               cout << "You gotta go find Beavis. You leave.\n";
            }
            else
            {
            cout << "You walk up to Rabid Ron.\n";
            cout << "Behind him is the KT&A Van and a giant round thing.\n";
            cout << "'Hey dudes! Interested in spinning the prize wheel?\n";
            cout << "Tell me your favorite Gwar album and you can take\n";
            cout << "a spin!' What an easy question, you think.\n";
            cout << "'Uhh...hello, Let There Be Gwar' you say.\n";
            cout << "'Nice! Hell-o and Let There Be Gwar!\n"; 
            cout << "You're the first person to give me two albums!\n";
            cout << "I'll give you two spins plus a bonus one\n";
            cout << "since you're such a big fan!' he exclaims.\n";
            cout << "You had no idea Gwar had more than one album\n";
            cout << "but you don't say that out loud, fortunately.\n";
            cout << "You step up to the wheel and spin it.\n";
            cout << "You win a sweet Gwar hat, but not the backstage\n";
            cout << "passes. You have two more spins though.\n";
            cout << "What do you want to do with the hat?\n";
            cout << "------------------------------------\n";
            cout << "1. Keep it                          \n";
            cout << "2. Give it to Beavis                \n";

            int prize_one = int_validate_multi_choice(2);

            switch(prize_one)
            {
               case 1:  // Keep the hat
               {
                  cout << "You put the hat in your backpack.\n";
                  butthead->add_stuff_to_things(new Stuff("Gwar hat"));
                  break;
               }
               case 2:  // Give the hat to Beavis
               {
                  cout << "You give the hat to Beavis.\n";
                  cout << "What a nice guy you are!\n";
                  break;
               }
            }
            
            cout << "You step to the wheel and spin it again.\n";
            cout << "You win a radical Gwar shirt. Dammit!\n";
            cout << "You NEED those backstage passes!\n";
            cout << "You gotta nail that last spin, coz\n";
            cout << "no one wants to end up with some Gwar\n";
            cout << "underwear next instead of those passes!\n";          
            cout << "What do you want to do with the shirt?\n";
            cout << "------------------------------------\n";
            cout << "1. Keep it                          \n";
            cout << "2. Give it to Beavis                \n";

            int prize_two = int_validate_multi_choice(2);

            switch(prize_two)
            {
               case 1:  // Keep the shirt
               {
                  if(butthead->search_things("Gwar hat"))
                  {
                     cout << "Dude, stop being so greedy!\n";
                     cout << "Plus you can't carry that much stuff!\n";
                     cout << "You give the shirt to Beavis.\n";
                  }
                  else
                  {
                     cout <<"You put the shirt in your backpack.\n";
                     butthead->add_stuff_to_things(new Stuff("Gwar shirt"));
                  }
                  break;
               }
               case 2:  // Give the shirt to Beavis
               {
                  if(!butthead->search_things("Gwar hat"))
                  {
                     cout << "What are you, a Boy Scout now?!\n";
                     cout << "Keep the shirt, you're doing all the work!\n";
                     cout << "You put the shirt in your backpack.\n";
                     butthead->add_stuff_to_things(new Stuff("Gwar shirt"));
                  }
                  else
                  {
                     cout << "Well look at you, Mr. Sharing is Caring!\n";
                     cout << "You give the shirt to Beavis.\n";
                  } 
                  break;
               }
            }
            
            cout << "Alright, this is it. The final spin.\n";
            cout << "The wheel slows down and it looks like\n";
            cout << "one of you is getting new underwear...\n";
            cout << "until it spins one more click and you\n";
            cout << "WIN THE BACKSTAGE PASSES!!!!!!!!!!!!!\n";
            cout << "'Hell yeah, you nailed it!' screams Rabid Ron,\n";	
            cout << "and he hands you the backstage passes!\n";

            butthead->add_stuff_to_things(new Stuff("backstage passes"));

            cout << "You head back to the front.\n";
            }
            break;
         }
         case 3:        // To Maxi-Mart
         {
            cout << "You head back to the Maxi-Mart.";
            return left;
            break;
         }
         case 4:        // Go into the Show
         {
            cout << "You head up to the doors leading into the show.\n";
            if(!butthead->search_things("Beavis") &&
                          !butthead->search_things("backstage passes"))
            {
               cout << "You feel bad about going to the Show without\n";
               cout << "Beavis, and you can't get past those big\n";
               cout << "bouncer dudes without a ticket.\n";
               cout << "You walk away from the doors.\n";
            }
            if(!butthead->search_things("Beavis") &&
                          butthead->search_things("backstage passes"))
            {
               cout << "You feel bad about going to the Show without\n";
               cout << "Beavis, even though you have passes to get in.\n";
               cout << "You've gotta go get him.\n";
               cout << "You walk away from the doors.\n";
            }
            if(butthead->search_things("Beavis") &&
                          !butthead->search_things("backstage passes"))
            {
               cout << "You and Beavis don't have tickets, so you\n";
               cout << "can't get past those big bouncer dudes.\n";
               cout << "You walk away from the doors\n";
            }
            if(butthead->search_things("Beavis") &&
                          butthead->search_things("backstage passes"))
            {
               cout << "'Backstage passes, huh? Rock on!\n";
               cout << "says the Head Bouncer. He puts VIP\n";
               cout << "wristbands on you and Beavis and you\n";
               cout << "guys head through the doors.\n";
               cout << "Whoah, so many chicks to try and score with!\n";
               cout << "The show is amazing and ends seconds\n";
               cout << "before your hands are permanently\n";
               cout << "stuck making devil horns. THAT WAS SO COOL!\n";
               cout << "Security finds you guys and leads both of you\n";
               cout << "backstage, where GWAR surprises you with...\n";
               cout << "A GIANT ALL-YOU-CAN-EAT NACHO BAR!!!\n";
               butthead->set_show();
            }
            break;
         }
      }
      counter++;
   }
}


/*
* Summary: set_up() - sets the up pointer to another space 
*/
void Gwar_Show::set_up(Space * place)
{
   up = place;
}


/*
* Summary: set_down() - sets the down pointer to another space
*/
void Gwar_Show::set_down(Space * place)
{
   down = place;
}


/*
* Summary: set_left() - sets the left pointer to another space
*/
void Gwar_Show::set_left(Space * place)
{
   left = place;
}


/*
* Summary: set_right() - sets the right pointer to another place
*/
void Gwar_Show::set_right(Space * place)
{
   right = place;
}


/*
* Summary: get_place_number() - returns the place number of the space
*/
int Gwar_Show::get_place_number()
{
   return place_number;
}
