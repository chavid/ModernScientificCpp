#include <cmath>
#include <iostream>
#include <optional>
#include <expected>

template< typename OutputType, typename InputType1, typename InputType2 >
auto raise( std::optional<OutputType>(&f)(InputType1,InputType2) )
 {
  return [f]( std::optional<InputType1> input1, std::optional<InputType2> input2 ) -> std::expected<OutputType,std::string>
   {
    if (!input1) return std::unexpected("empty argument 1") ;
    if (!input2) return std::unexpected("empty argument 2") ;
    auto res = f(input1.value(),input2.value()) ;
    if (!res) return std::unexpected("empty result") ;
    return res.value() ;
   } ;
 }

std::optional<double> mysqrt( double d ) {
 if (d<0) return std::nullopt ;
 else return std::sqrt(d) ;
}

std::optional<double> divide( double d1, double d2 ) {
  if (d2==0) return std::nullopt ;
  else return d1/d2 ;
}

template< typename T, typename E >
std::ostream & operator<<( std::ostream & os, std::expected<T,E> const & exp ) {
  if (exp) { return (os<<exp.value()) ; }
  else { return (os<<"("<<exp.error()<<")") ; }
}

int main() {
  std::cout<<raise(divide)(mysqrt(10),0)<<std::endl ;
  std::cout<<raise(divide)(mysqrt(-10),mysqrt(10))<<std::endl ;
  std::cout<<raise(divide)(mysqrt(10),mysqrt(-10))<<std::endl ;
  std::cout<<raise(divide)(mysqrt(10),mysqrt(10))<<std::endl ;
}