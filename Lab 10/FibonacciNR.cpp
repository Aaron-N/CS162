/*********************************************************************
** Program name:  Lab 10 (FibonacciNR.cpp)
** Author:        Aaron Nesbit
** Date:          11/30/19
** Description:   This is the Fibonacci Non-Recursive source code for
**                Lab 10. The source code is taken from
**                https://codeproject.com/tips/109443/fibonacci-
**                recursive-and-non-recursive-c
*********************************************************************/

#include "FibonacciNR.h"
#include <iostream>

FibonacciNR::FibonacciNR(){}

FibonacciNR::FibonacciNR(const int &n):n_(&n){}

FibonacciNR::~FibonacciNR(){}

int FibonacciNR::Fibonacci(const int &n)
{
   int first = 0;
   int second = 1;
   int counter = 2;
   while(counter < n)
   {
      int temp = second;
      second = first + second;
      first = temp;
      ++counter;
   }
   if(n == 0)
   {
      return 0;
   }
   else
   {
      return first + second;
   }
}

void FibonacciNR::PrintFibonacci()
{
   const int result = Fibonacci(*n_);
   std::cout << *n_ << "th Fibonacci Number: " << result << std::endl;
}
