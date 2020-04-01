# Program name:  Lab 10 (makefile)
# Author:        Aaron Nesbit
# Date:          11/30/19
# Description:   This is the makefile for Lab 10

default:
	g++ -std=c++11 FibonacciNR.cpp FibonacciR.cpp input_validation.cpp main.cpp -o FibTime

clean:
	-rm $(objects) FibTime

zip:
	zip -D Lab10_Nesbit_Aaron.zip FibonacciNR.cpp FibonacciNR.h FibonacciR.cpp FibonacciR.h input_validation.cpp input_validation.hpp main.cpp makefile Lab_10_Report_Nesbit_Aaron.pdf
