/*********************************************************************
** Program name:  Lab 7 (input_validation.hpp)
** Author:        Aaron Nesbit
** Date:          11/13/19
** Description:   This is the header file for the input validation
**                functions for Lab 7.
*********************************************************************/

#ifndef INPUT_VALIDATION_HPP
#define INPUT_VALIDATION_HPP

using std::string;

// Function prototypes declared
int int_validate_5_choice();           // validation for 5 choice menu
int validate_any_int();                // validation for +/- integers
bool digit_check(string input);        // digits only validation function
bool is_integer(string input);         // digits and leading '-' sign
                                       // validation function

#endif
