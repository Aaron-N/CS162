/*********************************************************************
** Program name:  Lab 8 (input_validation.hpp)
** Author:        Aaron Nesbit
** Date:          11/19/19
** Description:   This is the header file for the input validation
**                functions for Lab 8.
*********************************************************************/

#ifndef INPUT_VALIDATION_HPP
#define INPUT_VALIDATION_HPP

using std::string;

// Function prototypes declared
int validate_any_int();                // validation for +/- integers
bool is_integer(string input);         // digits and leading '-' sign
                                       // validation function

#endif
