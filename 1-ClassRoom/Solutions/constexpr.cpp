#include <iostream>

constexpr int fibonacci( int n )
 {
  if (n>1) return fibonacci(n-1) + fibonacci(n-2) ;
  else return n ;
 }

int main()
 {
  constexpr int res { fibonacci(36) } ;
  std::cout<<res<<std::endl ;
  return 0 ;
 }