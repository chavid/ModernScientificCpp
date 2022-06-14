#include <iostream>
#include <cassert> // for assert
#include <cstdlib> // for rand
#include <vector>

using real = float ;

struct XY
 {
  real x, y = 0. ;
  void saxpy( real a )
   { y = a*x + y ; }
 } ;

void randomize_x( std::vector<XY> & collection )
 {
  srand(1) ;
  for ( XY & elem : collection )
   { elem.x = std::rand()/(RAND_MAX+1.)-0.5 ; }
 }

void saxpy( std::vector<XY> & collection, real a )
 {
  for ( XY & elem : collection )
   { elem.saxpy(a) ; }
 }

real accumulate_y( std::vector<XY> const & collection )
 {
  real res = 0. ;
  for ( XY elem : collection )
   { res += elem.y ; }
  return res ;
 }

int main( int argc, char * argv[] )
 {
  assert(argc==3) ;
  int size {atoi(argv[1])} ;
  int repeat {atoi(argv[2])} ;
  std::cout.precision(18) ;

  std::vector<XY> collection(size) ;
  randomize_x(collection) ;
  while (repeat--)
    saxpy(collection,0.1) ;
  real res = accumulate_y(collection)/size ;
  std::cout<<sizeof(res)<<" octets : " <<res<<std::endl ;
 }
