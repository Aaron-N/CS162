/*********************************************************************
** Program name:  Lab 10 (FibonacciR.h)
** Date:          11/30/19
** Description:   This is the Fibonacci Recursive header file for Lab 10.
**                The source code is taken from
**                https://codeproject.com/tips/109443/fibonacci-
**                recursive-and-non-recursive-c
*********************************************************************/

#ifndef FIBONACCIR_H_
#define FIBONACCIR_H_

class FibonacciR
{
   public:
      FibonacciR(const int &n);
      virtual ~FibonacciR();
      void PrintFibonacci();

   private:
      FibonacciR();
      int Fibonacci(const int &n);
      const int *n_;
};

#endif
