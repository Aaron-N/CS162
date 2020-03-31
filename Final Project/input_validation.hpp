/*********************************************************************
** Program name:  Final Project (input_validation.hpp)
** Author:        Aaron Nesbit
** Date:          12/1/19
** Description:   This is the header file for the input validation
**                functions for my Final Project
*********************************************************************/

#ifndef INPUT_VALIDATION_HPP
#define INPUT_VALIDATION_HPP

using std::string;

// Function prototypes declared
int int_validate_multi_choice(const int); // validation for integer ranges
bool digit_check(string input);        // digits only validation function

#endif
