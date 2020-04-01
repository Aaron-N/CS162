# Program name: makefile
# Author:       Aaron Nesbit
# Date:         11/6/19
# Description:  makefile for CS 162 Lab 6

default:
	g++ -std=c++11 Doubly_Linked_List.cpp input_validation.cpp main.cpp Node.cpp -o List

clean:
	-rm $(objects) List

zip:
	zip -D Lab6_Nesbit_Aaron.zip Doubly_Linked_List.hpp Doubly_Linked_List.cpp input_validation.hpp input_validation.cpp list.txt main.cpp makefile Node.cpp Node.hpp

