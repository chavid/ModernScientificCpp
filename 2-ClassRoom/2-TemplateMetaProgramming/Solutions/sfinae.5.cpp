#include <iostream>
#include <type_traits>

template < typename T >
T times_power_of_two( T number, int exponent )
 {
  if constexpr (std::is_integral_v<T>)
   {
    if (exponent<0) { return (number>>-exponent) ; }
    else { return (number<<exponent) ; }
   }
  else
   {
    while (exponent<0) { number /= 2 ; exponent++ ; }
    while (exponent>0) { number *= 2 ; exponent-- ; }
    return number ;
   }
 }

int main()
{
  std::cout<<times_power_of_two(42,1)<<std::endl ;
  std::cout<<times_power_of_two(42,-1)<<std::endl ;
  std::cout<<times_power_of_two(3.14,1)<<std::endl ;
  std::cout<<times_power_of_two(3.14,-1)<<std::endl ;
  return 0 ;
}