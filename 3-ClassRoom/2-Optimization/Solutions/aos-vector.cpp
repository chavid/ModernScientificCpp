#include <iostream>
#include <cassert> // for assert
#include <cstdlib> // for rand
#include <vector>

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
  int size {atoi(argv[1])} ;
  int repeat {atoi(argv[2])} ;
  std::cout.precision(18) ;

  std::vector<XY> collection(size) ;
  auto begin {std::begin(collection)} ;
  auto end {std::end(collection)} ;

  randomize_x(begin,end) ;
  while (repeat--)
    saxpy(begin,end,0.1) ;
  double res {accumulate_y(begin,end)/size} ;
  std::cout<<res<<std::endl ;
 }
