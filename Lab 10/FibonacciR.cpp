/*********************************************************************
** Program name:  Lab 10 (FibonacciR.cpp)
** Author:        Aaron Nesbit
** Date:          11/30/19
** Description:   This is the Fibonacci Recursive source file for 
**                Lab 10. The source code is taken from
**                https://codeproject.com/tips/109443/fibonacci-
**                recursive-and-non-recursive-c
*********************************************************************/

#include "FibonacciR.h"
#include <iostream>

FibonacciR::FibonacciR(){}

FibonacciR::FibonacciR(const int &n):n_(&n){}

FibonacciR::~FibonacciR(){}

int FibonacciR::Fibonacci(const int &n)
{
   if(n == 0)
   {
      return 0;
   }
   else if(n == 1)
   {
      return 1;
   }
   return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void FibonacciR::PrintFibonacci()
{
   int FibonaciNum = Fibonacci(*n_);
   std::cout << *n_ << "th Fibonacci Number: " << FibonaciNum << std::endl; 
}
