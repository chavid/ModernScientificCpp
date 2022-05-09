#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>

// types
using Real = double ;
using Complex = std::complex<Real> ;
using Complexes = std::vector<Complex> ;

// utilities
template< typename Collection, typename Function >
void for_each( Collection & col, Function f )
 { std::for_each(std::begin(col),std::end(col),f) ; }
template< typename Collection, typename Function >
void transform( Collection & input, Collection & output, Function f )
 { std::transform(std::begin(input),std::end(input),std::begin(output),f) ; }

// print product of a collection of complexes
void print_product( Complexes const & cs )
 {
  Complex p(1.,0.) ;
  for ( auto c : cs )
   { p *= c ; }
  std::cout
    <<"*... = "
    <<std::scientific<<std::setprecision(4)
    <<"( "<<p.real()<<" , "<<p.imag()<<" )"
    <<std::endl ;
 }

// main code
int main( int argc, char * argv[] )
 {
  // generate input
  Complexes input(1024) ;
  srand(20201123) ; 
  for_each(input,[]( auto & c )
   { 
    int r = rand() ;
    Real d = ((Real) r)/RAND_MAX ;
    Real e = 2*M_PI*d ;
    c = Complex(cos(e),sin(e)) ;
   }) ;
  print_product(input) ;
   
  // compute output
  Complexes output(1024) ;
  int degree = atoi(argv[1]) ;
  transform(input,output,[degree]( auto c )
   {
    int d ;
    Complex res(1.,0.) ;
    for ( d=0 ; d<degree ; ++d )
     { res *= c ; }
    return res ;
   }) ;
  print_product(output) ;

  return 0 ;
 }
