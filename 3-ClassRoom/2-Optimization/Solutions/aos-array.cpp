#include <iostream>
#include <cassert> // for assert
#include <cstdlib> // for rand
#include <array>
#include <format>

struct XY
 {
  double x, y {0.} ;
  void saxpy( double a )
   { y = a*x + y ; }
 } ;

template< typename Itr >
void randomize_x( Itr begin, Itr end )
 {
  srand(1) ;
  for ( ; begin!=end ; ++begin )
   { begin->x = std::rand()/(RAND_MAX+1.)-0.5 ; }
 }

template< typename Itr >
void saxpy( Itr begin, Itr end, double a )
 {
  for ( ; begin!=end ; ++begin )
   { begin->saxpy(a) ; }
 }

template< typename Itr >
double accumulate_y( Itr begin, Itr end )
 {
  double res {0.} ;
  for ( ; begin!=end ; ++begin )
   { res += begin->y ; }
  return res ;
 }

int main( int argc, char * argv[] )
 {
  assert(argc==3) ;
  std::size_t size {std::strtoull(argv[1],nullptr,10)} ;
  std::size_t repeat {std::strtoull(argv[2],nullptr,10)} ;
  constexpr std::size_t size_max {10000} ;
  assert(size<=size_max) ;

  std::array<XY,size_max> collection ;
  auto begin {std::begin(collection)} ;
  auto end {begin+size} ; // on purpose !

  randomize_x(begin,end) ;
  double volatile a {0.1} ;
  while (repeat--)
    saxpy(begin,end,a) ;
  double res {accumulate_y(begin,end)/size} ;
  std::cout<<res<<std::endl ;
 }
