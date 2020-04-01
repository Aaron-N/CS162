/*********************************************************************
** Program name:  Lab 5 (input_validation.hpp)
** Author:        Aaron Nesbit
** Date:          10/28/19
** Description:   This is the header file for the input validation
**                functions for Lab 5.
*********************************************************************/

#ifndef INPUT_VALIDATION_HPP
#define INPUT_VALIDATION_HPP

using std::string;

// Function prototypes declared
int int_validate_4_choice();           // validation for 4 choice menu
int validate_any_int();                // validation for +/- integers
int validate_positive_int();           // validation for integers > 0
bool digit_check(string input);        // digits only validation function
bool is_integer(string input);         // digits and leading '-' sign
                                       // validation function

#endif
