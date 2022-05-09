#include <iostream>
#include <type_traits>

template < typename T >
T times_power_of_two( T number, int exponent )
 {
  static_assert(std::is_integral_v<T>,"the type must be an integer !") ;
  if (exponent<0) { return (number>>-exponent) ; }
  else { return (number<<exponent) ; }
 }

int main()
{
  std::cout<<times_power_of_two(42,1)<<std::endl ;
  std::cout<<times_power_of_two(42,-1)<<std::endl ;
  std::cout<<times_power_of_two(3.14,1)<<std::endl ;
  std::cout<<times_power_of_two(3.14,-1)<<std::endl ;
  return 0 ;
}