/*********************************************************************
** Program name:  Lab 10 (input_validation.hpp)
** Author:        Aaron Nesbit
** Date:          11/30/19
** Description:   This is the header file for the input validation
**                functions for Lab 10.
*********************************************************************/

#ifndef INPUT_VALIDATION_HPP
#define INPUT_VALIDATION_HPP

using std::string;

// Function prototypes declared
int validate_positive_int();           // validation for integers > 0
bool digit_check(string input);        // digits only validation function

#endif
