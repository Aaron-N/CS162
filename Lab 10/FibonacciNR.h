/*********************************************************************
** Program name:  Lab 10 (FibonacciNR.h)
** Author:        Aaron Nesbit
** Date:          11/30/19
** Description:   This is the Fibonacci Non-Recursive header file for
**                Lab 10. The source code is taken from
**                https://codeproject.com/tips/109443/fibonacci-
**                recursive-and-non-recursive-c
*********************************************************************/

#ifndef FIBONACCINR_H_
#define FIBONACCINR_H_

class FibonacciNR
{
   public:
      FibonacciNR(const int &n);
      virtual ~FibonacciNR();
      void PrintFibonacci();

   private:
      FibonacciNR();
      int Fibonacci(const int &n);
      const int* n_;
};

#endif
