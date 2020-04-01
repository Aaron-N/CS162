/*********************************************************************
** Program name:  Lab 10 (main.cpp)
** Author:        Aaron Nesbit
** Date:          11/30/19
** Description:   This is the main() file for Lab 10.
*********************************************************************/

#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <iomanip>
#include "input_validation.hpp"
#include "FibonacciNR.h"
#include "FibonacciR.h"

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main()
{
   cout << "=======================================" << endl;
   cout << "========== Welcome to Lab 10 ==========" << endl;
   cout << "=======================================" << endl;
   cout << "In this lab we will measure and compare" << endl;
   cout << "  the running times of iterative and   " << endl;
   cout << "   recursive implementations of        " << endl;
   cout << "   Fibonacci Numbers Calculation       " << endl;
   cout << "=======================================" << endl;
   cout << endl;

   cout << "What value of N would you like to test?" << endl;

   int N = validate_positive_int();

   cout << endl;

   // Create a clock object and start the clock
   clock_t t1;
   t1 = clock();
   float f1;

   cout << "Running iterative implementation..." << endl;
   FibonacciNR iterative(N);
   iterative.PrintFibonacci();

   // Clock stops and runtime is displayed
   t1 = clock() - t1;
   f1 = ((float)(t1) / CLOCKS_PER_SEC);

   cout << "=======================================" << endl;
   cout << "Runtime: " << t1 << " clicks (";
   cout << fixed;
   cout << setprecision(2);
   cout << f1 << " seconds)" << endl;   
   cout << "=======================================" << endl;
   cout << endl;

   // Create a clock object and start the clock
   clock_t t2;
   t2 = clock();
   float f2;

   cout << "Running recursive implementation..." << endl;
   FibonacciR recursive(N);
   recursive.PrintFibonacci();

   // Clock stops and runtime is displayed
   t2 = clock() - t2;
   f2 = ((float)(t2) / CLOCKS_PER_SEC);

   cout << "=======================================" << endl;
   cout << "Runtime: " << t2 << " clicks (";
   cout << fixed;
   cout << setprecision(2);
   cout << f2 << " seconds)" << endl;   
   cout << "=======================================" << endl;
   cout << endl;

   return 0;
}
