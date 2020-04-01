/*********************************************************************
** Program name:  Lab 3 (Player.cpp)
** Author:        Aaron Nesbit
** Date:          10/17/19
** Description:   This is the implementation file for class Player
*********************************************************************/

#include <string>
#include "Player.hpp"

using std::string;

/*
* Summary:    Constructor
* Parameters: Pointer to a die object
*/
Player::Player(Die *die)
{
   selected_die = die;
   wins = 0;
   losses = 0;
   draws = 0;
}


/*
* Summary:  Destructor
*/
Player::~Player(){}


/*
* Summary: get_die_sides() -  goes to die object and gets number of sides
* Returns: number of die sides
*/
int Player::get_die_sides()
{
   return selected_die->get_die_sides();
}


/*
* Summary: get_die_type() -  goes to die object and gets type of die
* Returns: type of die
*/
string Player::get_die_type()
{
   return selected_die->get_die_type();
}


/*
* Summary: roll() -  goes to die object and gets roll
* Returns: die roll value
*/
int Player::roll()
{
   return selected_die->roll();
}


/*
* Summary: win() - increases player win count by 1
*/
void Player::win()
{
   wins++;
}


/*
* Summary: lose() -  increases player loss count by 1
*/
void Player::lose()
{
   losses++;
}


/*
* Summary: draw() -  increases player draw count by 1
*/
void Player::draw()
{
   draws++;
}


/*
* Summary: get_wins() - gets number of wins player has
* Returns: number of wins
*/
int Player::get_wins()
{
   return wins;
}


/*
* Summary: get_losses() - gets number of losses player has
* Returns: number of losses
*/
int Player::get_losses()
{
   return losses;
}


/*
* Summary: get_draws() -  gets number of draws player has
* Returns: number of draws
*/
int Player::get_draws()
{
   return draws;
}
