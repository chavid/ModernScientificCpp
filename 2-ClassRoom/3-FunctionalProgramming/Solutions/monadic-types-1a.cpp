#include <cmath>
#include <iostream>
#include <string>
#include <optional>
#include <expected>

std::optional<double> mysqrt( double d ) {
 if (d<0) return std::nullopt ;
 else return std::sqrt(d) ;
}

std::optional<double> divide( std::optional<double> d1, std::optional<double> d2 ) {
  if ((!d1)||(!d2)||(d2==0)) return std::nullopt ;
  return d1.value()/d2.value() ;
}

template< typename T >
std::ostream & operator<<( std::ostream & os, std::optional<T> const & opt ) {
  if (opt) { return (os<<opt.value()) ; }
  else { return (os<<"(nothing)") ; }
}

int main() {
  std::cout<<divide(mysqrt(-10),mysqrt(10))<<std::endl ;
  std::cout<<divide(mysqrt(10),mysqrt(-10))<<std::endl ;
  std::cout<<divide(mysqrt(10),0)<<std::endl ;
  std::cout<<divide(mysqrt(10),mysqrt(10))<<std::endl ;
}