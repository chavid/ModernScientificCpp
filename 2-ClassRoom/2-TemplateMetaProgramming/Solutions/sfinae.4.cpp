#include <iostream>
#include <type_traits>

template < typename I, std::enable_if_t<std::is_integral_v<I>> * = nullptr >
I times_power_of_two( I number, int exponent )
 {
  if (exponent<0) { return (number>>-exponent) ; }
  else { return (number<<exponent) ; }
 }

template < typename F, std::enable_if_t<std::is_floating_point_v<F>> * = nullptr >
F times_power_of_two( F number, int exponent )
 {
  while (exponent<0) { number /= 2 ; exponent++ ; }
  while (exponent>0) { number *= 2 ; exponent-- ; }
  return number ;
 }

int main()
{
  std::cout<<times_power_of_two(42,1)<<std::endl ;
  std::cout<<times_power_of_two(42,-1)<<std::endl ;
  std::cout<<times_power_of_two(3.14,1)<<std::endl ;
  std::cout<<times_power_of_two(3.14,-1)<<std::endl ;
  return 0 ;
}