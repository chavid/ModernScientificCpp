#include <cmath>
#include <iostream>
#include <optional>

template< typename OutputType, typename InputType >
auto raise( OutputType(&f)(InputType) )
 {
  return [f]( std::optional<InputType> input ) -> std::optional<OutputType>
   {
    if (input) { return f(input.value()) ; }
    else { return std::nullopt ; }
   } ;
 }

template< typename OutputType, typename InputType >
auto raise( std::optional<OutputType>(&f)(InputType) )
 {
  return [f]( std::optional<InputType> input ) -> std::optional<OutputType>
   {
    if (input) { return f(input.value()) ; }
    else { return std::nullopt ; }
   } ;
 }

std::optional<double> mysqrt( double d )
 {
  if (d<0) { return std::nullopt ; }
  else { return std::sqrt(d) ; }
 }

double square( double d )
 { return d*d ; }

template< typename A >
std::ostream & operator<<( std::ostream & os, std::optional<A> const & opt )
 {
  if (opt) { return os<<opt.value() ; }
  else { return os<<"nothing" ; }
 }

int main()
 {
  std::cout<<raise(mysqrt)(mysqrt(10))<<std::endl ;
  std::cout<<raise(mysqrt)(mysqrt(-10))<<std::endl ;
 }