# Program name: makefile
# Author:       Aaron Nesbit
# Date:         11/19/19
# Description:  makefile for CS 162 Lab 8

default:
	g++ -std=c++11 input_validation.cpp algorithms.cpp stream_functions.cpp main.cpp -o SearchSort

clean:
	-rm $(objects) SearchSort

zip:
	zip -D Lab8_Nesbit_Aaron.zip input_validation.hpp input_validation.cpp main.cpp algorithms.hpp algorithms.cpp stream_functions.hpp stream_functions.cpp makefile original.txt early.txt middle.txt end.txt
