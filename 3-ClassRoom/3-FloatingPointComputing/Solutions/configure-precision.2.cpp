#include <iostream>
#include <cassert> // for assert
#include <cstdlib> // for rand
#include <vector>

template< typename real >
struct XY
 {
  real x, y = 0. ;
  void saxpy( real a )
   { y = a*x + y ; }
 } ;

template< typename real >
void randomize_x( std::vector<XY<real>> & collection )
 {
  srand(1) ;
  for ( XY<real> & elem : collection )
   { elem.x = std::rand()/(RAND_MAX+1.)-0.5 ; }
 }

template< typename real >
void saxpy( std::vector<XY<real>> & collection, real a )
 {
  for ( XY<real> & elem : collection )
   { elem.saxpy(a) ; }
 }

template< typename real >
real accumulate_y( std::vector<XY<real>> const & collection )
 {
  real res = 0. ;
  for ( XY<real> elem : collection )
   { res += elem.y ; }
  return res ;
 }

template< typename real >
void main_impl( unsigned long long size, unsigned long long repeat )
 {
  std::vector<XY<real>> collection(size) ;
  randomize_x(collection) ;
  while (repeat--)
    saxpy(collection,real(0.1)) ;
  real res = accumulate_y(collection)/size ;
  std::cout<<sizeof(res)<<" octets : " <<res<<std::endl ;
 }

int main( int argc, char * argv[] )
 {
  assert(argc==4) ;
  std::string precision(argv[1]) ;
  unsigned long long size = atoi(argv[2]) ;
  unsigned long long repeat = atoi(argv[3]) ;
  std::cout.precision(18) ;

  if (precision=="float") main_impl<float>(size,repeat) ;
  else if (precision=="double") main_impl<double>(size,repeat) ;
  else if (precision=="long") main_impl<long double>(size,repeat) ;
  else throw "unknown precision" ;
 }
