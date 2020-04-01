# Program name: Lab 7 (makefile)
# Author:       Aaron Nesbit
# Date:         11/14/19
# Description:  makefile for CS 162 Lab 7

default:
	g++ -std=c++11 Queue.cpp input_validation.cpp main.cpp -o Circular

clean:
	-rm $(objects) Circular

zip:
	zip -D Lab7_Nesbit_Aaron.zip Queue.hpp Queue.cpp input_validation.hpp input_validation.cpp main.cpp makefile
