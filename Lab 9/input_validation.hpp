/*********************************************************************
** Program name:  Lab 9 (input_validation.hpp)
** Author:        Aaron Nesbit
** Date:          11/29/19
** Description:   This is the header file for the input validation
**                functions for Lab 9.
*********************************************************************/

#ifndef INPUT_VALIDATION_HPP
#define INPUT_VALIDATION_HPP

using std::string;

// Function prototypes declared
int int_validate_3_choice();           // validation for 3 choice menu
int int_validate_0_to_100();           // validation for 1 to 100 range
int validate_positive_int();           // validation for integers > 0
bool digit_check(string input);        // digits only validation function

#endif
