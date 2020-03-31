/*********************************************************************
** Program name:  Final Project (Game.cpp)
** Author:        Aaron Nesbit
** Date:          12/2/19
** Description:   This is the implementation file for the class Game
*********************************************************************/

#include "Game.hpp"

using std::cout;
using std::endl;

/*
* Summary: Constructor
*/
Game::Game()
{
   butthead = new Butthead();

   buttheads_house = new Buttheads_House();
   current_space = buttheads_house;

   street = new Street();
   burger_world = new Burger_World();
   highland_high = new Highland_High();
   maxi_mart = new Maxi_Mart();
   gwar_show = new Gwar_Show();

   // Set all space pointers to surrounding spaces
  
   // Butthead's House pointers
   buttheads_house->set_up(street);

   // Street pointers
   street->set_up(maxi_mart);
   street->set_down(buttheads_house);
   street->set_left(burger_world);
   street->set_right(highland_high);

   // Burger World pointers
   burger_world->set_right(street);

   // Highland High pointers
   highland_high->set_left(street);

   // Maxi-Mart pointers
   maxi_mart->set_down(street);
   maxi_mart->set_right(gwar_show);

   // Gwar Show pointers
   gwar_show->set_left(maxi_mart);
}


/*
* Summary: Destructor
*/
Game::~Game()
{
   delete butthead;
   delete buttheads_house;
   delete street;
   delete burger_world;
   delete highland_high;
   delete maxi_mart;
   delete gwar_show;
}


/*
* Summary: menu() - this function creates the main menu of the game,
*                   displays round stats, and ends the game if Beavis
*                   and Butthead run out of time before the Gwar Show
*                   begins (that's a bummer, dude)
*/
void Game::menu()
{
   int turn_count = 1;
   bool show = false;

   cout << endl;
   cout << "*****************************************************" << endl;
   cout << "***********         WELCOME TO...          **********" << endl;
   cout << "***********     BEAVIS AND BUTTHEAD in     **********" << endl;
   cout << "                                                     " << endl;
   cout << "      ________  __      __    _____   __________     " << endl;
   cout << "     /  _____/ /  *    /  *  /  _  *  *______   *    " << endl;
   cout << "    /   *  ___ *   +/+/   / /  /_*  *  *    |  _/    " << endl;
   cout << "    *    *_*  * *        / /    |    * |    |   *    " << endl;
   cout << "     *______  /  *__**  /  *____|__  / |____|_  /    " << endl;
   cout << "            +/        +/           +/         +/     " << endl;
   cout << "                                                     " << endl;
   cout << " _________  ____ ___  ____     ___________  ________ " << endl;
   cout << " *_____   *|    |   *|    |    *_   _____/ /   ____/ " << endl;
   cout << "  |      _/|    |   /|    |     |    __)_  *____  *  " << endl;
   cout << "  |   |   *|    |  / |    |___  |        * /       * " << endl;
   cout << "  |___|_  /|______/  |______  )/_______  //______  / " << endl;
   cout << "        +/                  +/         +/        +/  " << endl;
   cout << "                                                     " << endl;
   cout << "***********       (GWAR RULES!!!!!)       ***********" << endl;
   cout << "*****************************************************" << endl;
   cout << "*****************************************************" << endl;
   cout << "**         Uhh...do you wanna, like, play?        ***" << endl;
   cout << "** HELLYEAH (Enter 1)            NO WAY!(Enter 2) ***" << endl;
   cout << "*****************************************************" << endl;
   cout << "                Your choice: ";

   int choice = int_validate_multi_choice(2);
 
   while(choice == 1)
   {
      // Proceed with game if user chooses to play
      cout << endl << endl;
      cout << "You just got home from school and you're sitting\n";
      cout << "on the living room couch watching MTV.\n";
      cout << "You wonder what people did in the olden times when\n";
      cout << "they didn't have any televisions. LAME. Suddenly, a\n";
      cout << "commercial with Rabid Ron, that poser DJ from KT&A\n";
      cout << "comes on. He's giving away a pair of backstage passes\n";
      cout << "outside the sold out Gwar Show tonight! WHOAH!\n";
      cout << "GWAR RULES!!!!!\n";
      cout << "Beavis is at work at Burger World, but you have the\n";
      cout << "day off. You have to go get him so you guys can\n";
      cout << "go win those backstage passes to the show!!!!!\n";

      // Begin main game loop in Butthead's House
      while(butthead->get_time() > 0 && butthead->get_show() == false)
      {
         cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
         cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
         cout << " Turn #" << turn_count << endl;
         cout << "---------------------------------------------" << endl;
         cout << "The Gwar Show starts in " << butthead->get_time()
              << " minutes" << endl;

         // When show time is getting close, display warning
         if(butthead->get_time() < 60)
         {
            cout << "Whoah! The show is starting soon. HURRY UP!"
                 << endl << endl;
         }
   
         cout << "Stuff you have:\n";
         butthead->get_things();
         cout << "---------------------------------------------" << endl;

         // Display the map and Buttthead's current location
         map(current_space);

         // Display the current place and the options in it
         current_space->description();
      
         // Set current_space to pointer
         current_space = current_space->place_options(butthead);

         turn_count++;                    // Turn count increases by 1
         butthead->decrease_time(15);     // 15 minutes of time passes
      }
 
      if(butthead->get_time() == 0 && butthead->get_show() == false)
      {
         // Beavis and Butthead run out of time
         cout << endl;
         cout << "Dammit, you're out of time! The show just started!\n";
         cout << "This sucks more than anything has sucked before!\n";
         cout << "You go get some nachos instead because NACHOS RULE!\n";
         cout << "(but not as much as the GWAR SHOW WOULD HAVE...)\n";
         cout << endl;
         cout << "            !$&@!$&@!$&@!$&@!$&@!$&@" << endl;
         cout << "            !$&@                !$&@" << endl;
         cout << "            !$&@   GAME  OVER   !$&@" << endl;
         cout << "            !$&@                !$&@" << endl;
         cout << "            !$&@!$&@!$&@!$&@!$&@!$&@" << endl;
         cout << endl;
      
         choice = 3;
      }

      if(butthead->get_show() == true)
      {
         cout << "GGGGWWWWAAAARRRR RRRRUUUULLLLEEESSSS!!!!!" <<endl;
         cout << endl << endl;
         cout << "      !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;   
         cout << "      !!!!                          !!!!" << endl;
         cout << "      !!!!    !!!!!!!!!!!!!!!!!!    !!!!" << endl;
         cout << "      !!!!    !!!! YOU  WIN !!!!    !!!!" << endl;
         cout << "      !!!!    !!!!!!!!!!!!!!!!!!    !!!!" << endl;
         cout << "      !!!!                          !!!!" << endl;
         cout << "      !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
         cout << endl;

         choice = 3;
      }       
   }

   if(choice == 2)
   {
      cout << endl;
      cout << "SETTLE DOWN. OK, later." << endl;
      cout << endl;
   }
}


/*
* Summary: map() - this function shows Butthead's current location on
*          the map of Highland
* Parameter: a pointer to the place number of the space Butthead is in
*/
void Game::map(Space *place)
{
   cout << "Uhh...like, X marks where you currently are" << endl;
   cout << endl << endl;

   switch(place->get_place_number())
   {
      case 1:      // Butthead's House
      {
         cout << "                 ___________   ___________    " << endl;
         cout << "                | Maxi-Mart | | Gwar Show |   " << endl;
         cout << "                |           |-|           |   " << endl;
         cout << "                |___________| |___________|   " << endl;
         cout << "   ___________   _____|_____   ___________    " << endl;
         cout << "  |   Burger  | |  Street   | | Highland  |   " << endl;
         cout << "  |   World   |-|           |-|   High    |   " << endl;
         cout << "  |___________| |___________| |___________|   " << endl;
         cout << "                 _____|_____                  " << endl;
         cout << "                | Butthead's|                 " << endl;
         cout << "                |   House   |                 " << endl;
         cout << "                |_____X_____|                 " << endl;
         break;
      }
      case 2:      // Street
      {
         cout << "                 ___________   ___________    " << endl;
         cout << "                | Maxi-Mart | | Gwar Show |   " << endl;
         cout << "                |           |-|           |   " << endl;
         cout << "                |___________| |___________|   " << endl;
         cout << "   ___________   _____|_____   ___________    " << endl;
         cout << "  |   Burger  | |  Street   | | Highland  |   " << endl;
         cout << "  |   World   |-|           |-|   High    |   " << endl;
         cout << "  |___________| |_____X_____| |___________|   " << endl;
         cout << "                 _____|_____                  " << endl;
         cout << "                | Butthead's|                 " << endl;
         cout << "                |   House   |                 " << endl;
         cout << "                |___________|                 " << endl;
         break;
      }
      case 3:      // Burger World
      {
         cout << "                 ___________   ___________    " << endl;
         cout << "                | Maxi-Mart | | Gwar Show |   " << endl;
         cout << "                |           |-|           |   " << endl;
         cout << "                |___________| |___________|   " << endl;
         cout << "   ___________   _____|_____   ___________    " << endl;
         cout << "  |   Burger  | |  Street   | | Highland  |   " << endl;
         cout << "  |   World   |-|           |-|   High    |   " << endl;
         cout << "  |_____X_____| |___________| |___________|   " << endl;
         cout << "                 _____|_____                  " << endl;
         cout << "                | Butthead's|                 " << endl;
         cout << "                |   House   |                 " << endl;
         cout << "                |___________|                 " << endl;
         break;
      }
      case 4:      // Highland High
      {
         cout << "                 ___________   ___________    " << endl;
         cout << "                | Maxi-Mart | | Gwar Show |   " << endl;
         cout << "                |           |-|           |   " << endl;
         cout << "                |___________| |___________|   " << endl;
         cout << "   ___________   _____|_____   ___________    " << endl;
         cout << "  |   Burger  | |  Street   | | Highland  |   " << endl;
         cout << "  |   World   |-|           |-|   High    |   " << endl;
         cout << "  |___________| |___________| |_____X_____|   " << endl;
         cout << "                 _____|_____                  " << endl;
         cout << "                | Butthead's|                 " << endl;
         cout << "                |   House   |                 " << endl;
         cout << "                |___________|                 " << endl;
         break;
      }
      case 5:      // Maxi-Mart
      {
         cout << "                 ___________   ___________    " << endl;
         cout << "                | Maxi-Mart | | Gwar Show |   " << endl;
         cout << "                |           |-|           |   " << endl;
         cout << "                |_____X_____| |___________|   " << endl;
         cout << "   ___________   _____|_____   ___________    " << endl;
         cout << "  |   Burger  | |  Street   | | Highland  |   " << endl;
         cout << "  |   World   |-|           |-|   High    |   " << endl;
         cout << "  |___________| |___________| |___________|   " << endl;
         cout << "                 _____|_____                  " << endl;
         cout << "                | Butthead's|                 " << endl;
         cout << "                |   House   |                 " << endl;
         cout << "                |___________|                 " << endl;
         break;
      }
      case 6:      // Gwar Show!
      {
         cout << "                 ___________   ___________    " << endl;
         cout << "                | Maxi-Mart | | Gwar Show |   " << endl;
         cout << "                |           |-|           |   " << endl;
         cout << "                |___________| |_____X_____|   " << endl;
         cout << "   ___________   _____|_____   ___________    " << endl;
         cout << "  |   Burger  | |  Street   | | Highland  |   " << endl;
         cout << "  |   World   |-|           |-|   High    |   " << endl;
         cout << "  |___________| |___________| |___________|   " << endl;
         cout << "                 _____|_____                  " << endl;
         cout << "                | Butthead's|                 " << endl;
         cout << "                |   House   |                 " << endl;
         cout << "                |___________|                 " << endl;
         break;
      }
   }
   cout << "---------------------------------------------" << endl;
   cout << endl;
}
