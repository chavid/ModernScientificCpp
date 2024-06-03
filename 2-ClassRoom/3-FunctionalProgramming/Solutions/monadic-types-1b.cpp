#include <cmath>
#include <iostream>
#include <string>
#include <optional>
#include <expected>

std::optional<double> mysqrt( double d ) {
 if (d<0) return std::nullopt ;
 else return std::sqrt(d) ;
}

std::expected<double,std::string> divide( std::optional<double> d1, std::optional<double> d2 ) {
  if (!d1) return std::unexpected("imaginary numerator") ;
  if (!d2) return std::unexpected("imaginary denominator") ;
  if (d2==0) return std::unexpected("zero denominator") ;
  return d1.value()/d2.value() ;
}

template< typename T, typename E >
std::ostream & operator<<( std::ostream & os, std::expected<T,E> const & exp ) {
  if (exp) { return (os<<exp.value()) ; }
  else { return (os<<"("<<exp.error()<<")") ; }
}

int main() {
  std::cout<<divide(mysqrt(-10),mysqrt(10))<<std::endl ;
  std::cout<<divide(mysqrt(10),mysqrt(-10))<<std::endl ;
  std::cout<<divide(mysqrt(10),0)<<std::endl ;
  std::cout<<divide(mysqrt(10),mysqrt(10))<<std::endl ;
}
