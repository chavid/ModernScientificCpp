#include <iostream>

auto add( auto a, auto b )
 { return (a+b) ; }
 
int main()
 {
  std::cout<<add(10,32)<<std::endl ; 
  std::cout<<add(1,2.14)<<std::endl ; 
  std::cout<<add(1.0,2.14)<<std::endl ; 
 }
