/*********************************************************************
** Program name:  Final Project (Butthead.cpp)
** Author:        Aaron Nesbit
** Date:          11/30/19
** Description:   This is the implementation file for the class
**                Butthead
*********************************************************************/

#include "Butthead.hpp"

using std::cout;

/*
* Summary: Constructor
*/
Butthead::Butthead()
{
   time = 240;
   found_Beavis = false;
   found_Stewart = false;
   show = false;
}


/*
* Summary: Destructor
*/
Butthead::~Butthead()
{
   for(int i = 0; i < things.size(); i++)
   {
      delete things[i]; 
   }
}

/*
* Summary: add_stuff_to_things() - adds item to Butthead's stuff
*/
void Butthead::add_stuff_to_things(Stuff *new_item)
{
   if(things.size() < 6)
   {
      things.push_back(new_item);
   }
   else
   {
      cout << "Dude, you can't carry that much stuff!\n";
   }
}


/*
* Summary: get_things() - function that shows things that Butthead has
*/
void Butthead::get_things()
{
   for(int i = 0; i < things.size(); i++)
      {
         cout << things[i]->get_name() << "\n";
      }
}

/*
* Summary:   search_things() - searches the things Butthead has by name
*            and returns if he has the named thing or not
* Parameter: name of thing
* Returns:   true if Butthead has thing, false if he doesn't
*/
bool Butthead::search_things(string name)
{
   for(int i = 0; i < things.size(); i++)
   {
      if(things[i]->get_name() == name)
      {
         return true;
      }
   }
   return false;
}


/*
* Summary: get_time() - gets current time remaining until the Gwar show
*          starts
* Returns: time remaining
*/
int Butthead::get_time()
{
   return time;
}


/*
* Summary:   decrease_time() - decreases the time remaining until the
*            Gwar show starts
* Parameter: amount to decrease time
* Returns:   updated time
*/
int Butthead::decrease_time(int change)
{
   time -= change;
}


/*
* Summary: getter for the current value of found_Beavis
* Returns: value of found_Beavis (true or false)
*/
bool Butthead::get_found_Beavis()
{
   return found_Beavis;
}


/*
* Summary: set_found_Beavis() - sets value of found_Beavis to true once
*          Butthead finds Beavis
*/
bool Butthead::set_found_Beavis()
{
   found_Beavis = true;
}


/*
* Summary: getter for the current value of found_Stewart
* Returns: value of found_Stewart (true or false)
*/
bool Butthead::get_found_Stewart()
{
   return found_Stewart;
}


/*
* Summary: set_found_Stewart() - sets value of found_Stewart to true once
*          Butthead finds Stewart
*/
bool Butthead::set_found_Stewart()
{
   found_Stewart = true;
}


/*
* Summary: get_show() - getter for the current value of show
* Returns: value of show (true or false) 
*/
bool Butthead::get_show()
{
   return show;
}


/*
* Summary: set_show() - sets set_show to true once Beavis and Butthead
*          succesfully get into the Gwar Show 
*/
bool Butthead::set_show()
{
   show = true;
}

