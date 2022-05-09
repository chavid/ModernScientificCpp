#include <iostream>

constexpr int fibonacci( int n )
 {
  if (n>1) return fibonacci(n-1) + fibonacci(n-2) ;
  else return n ;
 }

int main()
 {
  constexpr int fibo10 {fibonacci(10)} ;
  std::cout<<fibo10<<std::endl ;
  return 0 ;
 }