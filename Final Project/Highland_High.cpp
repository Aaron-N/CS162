/*********************************************************************
** Program name:  Final Project (Highland_High.cpp)
** Author:        Aaron Nesbit
** Date:          12/2/19
** Description:   This is the implementation file for the class
**                Highland_High
*********************************************************************/

#include "Highland_High.hpp"

using std::cout;
using std::endl;

/*
* Summary: Constructor
*/
Highland_High::Highland_High()
{
   up = NULL;
   down = NULL;
   left = NULL;
   right = NULL;
   place_number = 4;
}


/*
* Summary: description() - describes the place at the beginning of the turn
*/
void Highland_High::description()
{
   cout << "You walk into Highland High. School's out for the day,\n";
   cout << "but there's still a lot going on. You see a poster for\n";
   cout << "Positive Acting Teens today in Room 123.\n";
   cout << "PATsies. UH-HUH-HUH-HUH.\n"; 
}


/*
* Summary: place_options() - shows user the options and actions
*/
Space * Highland_High::place_options(Butthead *butthead)
{
   cout << "------------------------------" << endl;
   cout << "Options:                      " << endl;
   cout << "1. Go to the Library          " << endl;
   cout << "2. Go to the Gym              " << endl;
   cout << "3. Leave Highland High        " << endl;
   cout << "4. Go to Room 123             " << endl;

   int counter = 1;

   while(true)
   {
      if(counter > 1)
      {
         cout << "------------------------------" << endl;
         cout << "Options:                      " << endl;
         cout << "1. Go to the Library          " << endl;
         cout << "2. Go to the Gym              " << endl;
         cout << "3. Leave Highland High        " << endl;
         cout << "4. Go to Room 123             " << endl;
      }

      int choice = int_validate_multi_choice(4);

      switch(choice)
      {
         case 1:        // Go to the Library
         {
            cout << "You head to the Library.\n";
            cout << "You walk in to see Mr. Van Driessen and a group\n";
            cout << "of students gathered around a computer.\n";
            cout << "'And this, class, is the computer that will act as\n";
            cout << "our gateway to the information super highway! Now,\n";
            cout << "I know that all of you will use this responsibly\n";
            cout << "while working on your CS 162 Final Projects, m'kay?\n";
            cout << "OK, if there are no further questions, we'll get\n";
            cout << "back to our discussion about comparing the speeds\n";
            cout << "of iterative and recursive algorithms, m'kay?'\n";
            cout << "You already know memory speeds are MUCH slower\n";
            cout << "than processor speeds so iterative algorithms will\n";
            cout << "get faster than recursive algorithms as the number\n";
            cout << "function calls increase, so you leave the Library.\n";
            break;
         }
         case 2:        // Go to the Gym
         {
            cout << "You head towards the Gym.\n";
            cout << "As you're about to turn the corner and head down\n";
            cout << "the hall you freeze when you hear the voices of\n";
            cout << "Coach Buzzcut and Principle McVicker.\n";
            cout << "'Have you seen Beavis and Butthead?' Coach Buzzcut\n";
            cout << "shouts. 'They're supposed to be in detention!'\n";
            cout << "'Oh..uh..uh..NO! Those boys are driving me crazy!!\n";
            cout << "Uh..oh..dammit I need my heart pills!!!'\n";
            cout << "Prinicpal McVicker shakily replies.\n";
            cout << "It sounds like they're heading your way so\n";
            cout << "you take off before they discover you!\n";
            break;
         }
         case 3:        // To Street
         {
            cout << "You leave Highland High.\n";
            return left;
            break;
         }
         case 4:        // Go to Room 123 - Stewart's location
         {
            if(butthead->search_things("door code (666)"))
            {
               cout << "You already got the door code from Stewart!\n";
               cout << "Go get Beavis!\n";
            }
            else
            {
            cout << "You head to Room 123.\n";
          
            // If Butthead has already found Stewart previously and 
            // he has his backpack and he found Beavis already
            if(butthead->get_found_Stewart() == true
                                && butthead->search_things("backpack")
                                && butthead->get_found_Beavis() == true)
            {
               cout << "The PATsies meeting has just ended and Stewart\n";
               cout << "is standing outside the classroom door.\n";
               cout << "'Hey, you're back!' he exclaims, as you reach\n";
               cout << "into your backpack.\n";
               cout << "'Yeah, I'm back, dillhole. Here's your stupid\n";
               cout << "shirt' you grumble as you hand it to him.\n";
               cout << "'Thanks! The door code is 666! So metal, right?\n";
               cout << "Say hi to Beavis for me! Let's hang out soon!'\n";
               cout << "'Uhh...whatever' you reply.\n";
               cout << "You leave to go free Beavis.\n"; 
               butthead->add_stuff_to_things(new Stuff("door code (666)"));
            }
  
            // If Butthead has already found Stewart previously and
            // does not have his backpack and he found Beavis already
            else if(butthead->get_found_Stewart() == true
                               && !butthead->search_things("backpack")
                               && butthead->get_found_Beavis() == true)
            {
               cout << "The PATsies meeting has started and the door\n";
               cout << "is closed. You don't have your backpack yet\n";
               cout << "so Stewart won't give you the door code anyway.\n";
               cout << "You need to go home and get it, so you leave.\n";
            }

            // If Butthead has not found Stewart previously and he has
            // his backpack and he found Beavis already
            else if(butthead->get_found_Stewart() == false
                               && butthead->search_things("backpack")
                               && butthead->get_found_Beavis() == true)
            {
               cout << "The door is open and you look inside.\n";
               cout << "The PATsies meeting hasn't started yet.\n";
               cout << "'Hey Butthead!' a voice says from behind you.\n";
               cout << "You turn around. It's Stewart.\n";
               cout << "'Uhhh...hey Stewart, what's the door code for\n";
               cout << "for the Burger World freezer? Beavis says you\n";
               cout << "like know it or something' you say.\n";
               cout << "'Yeah, I do, but why do you need it?' he asks.\n";
               cout << "'I can't tell you, it's a secret' you whisper.\n";
               cout << "OK, well...since you won't tell me why, you\n";
               cout << "have to give me back my Winger t-shirt first.\n";
               cout << "You took it from me in the locker room after\n";
               cout << "gym class yesterday and never gave it back.'\n";
               cout << "he whines. 'Oh yeah, that's right. Here's your\n";
               cout << "stupid shirt' you say as you pull it out\n";
               cout << "of your backpack.\n";
               cout << "'Thanks! The door code is 666! So metal, right?\n";
               cout << "Say hi to Beavis for me! Let's hang out soon!'\n";
               cout << "'Uhh...whatever' you reply.\n";
               cout << "You leave to go free Beavis.\n";                
               butthead->set_found_Stewart();
               butthead->add_stuff_to_things(new Stuff("door code (666)"));
            }

            // If Butthead has not found Stewart previously and he does
            // not have his backpack and he found Beavis already
            else if(butthead->get_found_Stewart() == false
                               && !butthead->search_things("backpack")
                               && butthead->get_found_Beavis() == true
                               && !butthead->search_things("Beavis"))
            {
               cout << "The door is open and you look inside.\n";
               cout << "The PATsies meeting hasn't started yet.\n";
               cout << "'Hey Butthead!' a voice says from behind you.\n";
               cout << "You turn around. It's Stewart.\n";
               cout << "'Uhhh...hey Stewart, what's the door code for\n";
               cout << "for the Burger World freezer? Beavis says you\n";
               cout << "like know it or something' you say.\n";
               cout << "'Yeah, I do, but why do you need it?' he asks.\n";
               cout << "'I can't tell you, it's a secret' you whisper.\n";
               cout << "OK, well...since you won't tell me why, you\n";
               cout << "have to give me back my Winger t-shirt first.\n";
               cout << "You took it from me in the locker room after\n";
               cout << "gym class yesterday and never gave it back.'\n";
               cout << "he whines. 'Oh yeah, that's right' you say.\n";
               cout << "It's in my backpack, but I don't have it\n";
               cout << "with me. I need to go home and get it. I'll\n";
               cout << "be back, loser. Don't go anywhere!' you growl.\n";
               cout << "'OK, I won't!' Stewart says gleefully.\n";
               cout << "You leave.\n";
               butthead->set_found_Stewart();
            }

            // If Butthead doesn't know where Beavis is yet
            else if(butthead->get_found_Beavis() == false)
            {
               cout << "The door is open and you look inside.\n";
               cout << "You see Stewart sitting in a chair listening\n";
               cout << "to music on his Walkman and banging his head\n";
               cout << "with his eyes closed. You step out of the\n";
               cout << "door so he doesn't see you. What a dork.\n";
               cout << "You leave.\n";
            }

            // If Butthead has already freed Beavis before finding Stewart
            else if(butthead->search_things("Beavis")
                               && butthead->get_found_Stewart() == false)
            {
               cout << "The door is closed and the lights are off.\n";
               cout << "Looks like the PATsies meeting is over.\n";
               cout << "You and Beavis leave.\n";
            }
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
void Highland_High::set_up(Space * place)
{
   up = place;
}


/*
* Summary: set_down() - sets the down pointer to another space
*/
void Highland_High::set_down(Space * place)
{
   down = place;
}


/*
* Summary: set_left() - sets the left pointer to another space
*/
void Highland_High::set_left(Space * place)
{
   left = place;
}


/*
* Summary: set_right() - sets the right pointer to another place
*/
void Highland_High::set_right(Space * place)
{
   right = place;
}


/*
* Summary: get_place_number() - returns the place number of the space
*/
int Highland_High::get_place_number()
{
   return place_number;
}
