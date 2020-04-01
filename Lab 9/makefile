# Program name:  Lab 9
# Author:        Aaron Nesbit
# Date:          11/29/19
# Description:   This is the makefile for Lab 9

default:
	g++ -std=c++11 main.cpp Menu.cpp input_validation.cpp BufferSim.cpp Palindrome.cpp -o Containers

clean:
	-rm $(objects) Containers

zip:
	zip -D Lab9_Nesbit_Aaron.zip BufferSim.cpp BufferSim.hpp input_validation.cpp input_validation.hpp main.cpp makefile Menu.cpp Menu.hpp Palindrome.cpp Palindrome.hpp
