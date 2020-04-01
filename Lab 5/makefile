# Program name: makefile
# Author:       Aaron Nesbit
# Date:         10/29/19
# Description:  makefile for CS 162 Lab 5

default:
	g++ -std=c++11 main.cpp menus.cpp input_validation.cpp recursive_functions.cpp -o Recursion

clean:
	-rm $(objects) Recursion

zip:
	zip -D Lab5_Nesbit_Aaron.zip input_validation.cpp input_validation.hpp main.cpp makefile menus.cpp menus.hpp recursive_functions.cpp recursive_functions.hpp
