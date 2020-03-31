/*********************************************************************
** Program name:  Final Project (Street.cpp)
** Author:        Aaron Nesbit
** Date:          12/2/19
** Description:   This is the implementation file for the class
**                Street
*********************************************************************/

#include "Street.hpp"

using std::cout;
using std::endl;

/*
* Summary: Constructor
*/
Street::Street()
{
   up = NULL;
   down = NULL;
   left = NULL;
   right = NULL;
   place_number = 2;
}


/*
* Summary: description() - describes the place at the beginning of the turn
*/
void Street::description()
{
  // Generate random number for street scenario each time player enters  
  int scenario = (rand() % 8 + 1);

  switch(scenario)
  {
     case 1:
     {
        cout << "You're on the street.\n";
        cout << "Mr. Anderson is standing in the front yard staring at\n";
        cout << "the tree that you and Beavis cut down that fell on his\n";
        cout << "house this morning. That was cool. Uh-huh-huh-huh.\n";
        break;
     }
     case 2:
     {
        cout << "You're on the street.\n";
        cout << "You hear Mr. Anderson in his backyard screaming.\n";
        cout << "'What the hell?! My goddamn pool is full of concrete\n";
        cout << "again?! It must've been those damn hooligans\n";
        cout << "Buffcoat and Beaver!\n";
        cout << "It's a good thing you guys threw that jerk-hammer into\n";
        cout << "the pool as you were pouring the concrete earlier, or\n";
        cout << "you'd probably still be stuck there.\n"; 
        break;
     }
     case 3:
     {
        cout << "You're on the street.\n";
        cout << "Mr. Anderson is laying face down on the ground\n";
        cout << "surrounded by FBI agents with their guns drawn.\n";
        cout << "'Dammit, I'm a veteran! Yeah it was my damn bowling\n";
        cout << "ball that blew up, but you can't treat me like this!'\n";
        cout << "he yells. You overhear one of the FBI agents say into\n";
        cout << "his radio 'Copy that, the Mad Bomber is in custody'.\n";
        cout << "About time they caught that guy, you think.\n";
        break;
     }
     case 4:
     {
        cout << "You're on the street.\n";
        cout << "Mr. Anderson is taking down a Yard Sale sign in his\n";
        cout << "front yard. 'Dammit, where the hell are those boys?!\n";
        cout << "Maybe they know what the hell happened to my TV?\n";
        cout << "I'll see if I can find my dang Purple Heart in the\n";
        cout << "meantime...' You know Beavis totally made $5 off that\n";
        cout << "piece of crap.\n";
        break;
     }
     case 5:
     {
        cout << "You're on the street.\n";
        cout << "It's strangely quiet out here.\n";
        cout << "'Where the hell is Mr. Anderson?', you wonder.\n";
        cout << "Maybe one of those damn buzzard-hawks he always\n";
        cout << "talks about got him.\n";
        break;
     }
     case 6:
     {
        cout << "You're on the street.\n";
        cout << "Mr. Anderson is pulling his golf bag out of the trunk\n";
        cout << "of his car when a man stops as he walks by. 'What do\n";
        cout << "you say, Tom! How'd you hit 'em?' he asks. 'Boy, I\n";
        cout << "tell ya what, Dusty! I felt like a one-legged cat\n";
        cout << "trying to bury turds on a frozen pond out there today!\n";
        cout << "You should sell him back all those balls of his that\n";
        cout << "you and Beavis have been stealing, you could probably\n";
        cout << "buy something really cool with the money.\n";
        break;
     }
     case 7:
     {
        cout << "You're on the street.\n";
        cout << "Mr. Anderson is standing in his garage when he looks\n";
        cout << "up and yells at you 'Hey, you look kind of familiar.\n";
        cout << "Aren't you one of the kids who ran off with my riding\n";
        cout << "mower last week?' 'Uhhh...no,' you say. 'Ah hell!' he\n";
        cout << "replies. 'What I'd give for five minutes alone with\n";
        cout << "those little ding-dongs.'\n";
        cout << "Whatever, dude.\n";
        break;
     }
     case 8:
     {
        cout << "You're on the street.\n";
        cout << "Mr. Anderson is drinking a beer and staring down at\n";
        cout << "his dog in the front yard. 'Dammit, who the hell spray\n";
        cout << "painted you, boy?! That's the third time this month!\n";
        cout << "You remember how much it sucked getting that paint\n";
        cout << "off of your hands. Uh-huh-huh-huh.\n";
        break;
     }
  }
}


/*
* Summary: place_options() - shows user the options and actions
*/
Space * Street::place_options(Butthead *butthead)
{
   cout << "------------------------------" << endl;
   cout << "Options:                      " << endl;
   cout << "1. Go to the Maxi_Mart        " << endl;
   cout << "2. Go back to your house      " << endl;
   cout << "3. Go to Burger World         " << endl;
   cout << "4. Go to Highland High        " << endl;

   int counter = 1;

   while(true)
   {
      if(counter > 1)
      {
         cout << "------------------------------" << endl;
         cout << "Options:   " << endl;
         cout << "1. Go to the Maxi-Mart   " << endl;
         cout << "2. Go back to your house " << endl;
         cout << "3. Go to Burger World    " << endl;
         cout << "4. Go to Highland High   " << endl;
      }

      int choice = int_validate_multi_choice(4);

      switch(choice)
      {
         case 1:        // To Maxi_Mart
         {
            return up;
            break;
         }
         case 2:        // To Butthead's House
         {
            return down;
            break;
         }
         case 3:        // To Burger World
         {
            return left;
            break;
         }
         case 4:        // To Highland High
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
void Street::set_up(Space * place)
{
   up = place;
}


/*
* Summary: set_down() - sets the down pointer to another space
*/
void Street::set_down(Space * place)
{
   down = place;
}


/*
* Summary: set_left() - sets the left pointer to another space
*/
void Street::set_left(Space * place)
{
   left = place;
}


/*
* Summary: set_right() - sets the right pointer to another place
*/
void Street::set_right(Space * place)
{
   right = place;
}


/*
* Summary: get_place_number() - returns the place number of the space
*/
int Street::get_place_number()
{
   return place_number;
}
