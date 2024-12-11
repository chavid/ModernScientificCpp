#include <cstdlib>
#include <array>

std::size_t const SIZE = 1024 ;
std::size_t const REPEAT = 100000 ;

using Array = std::array<double,SIZE> ;

void randomize( Array & x ) {
  srand(1) ;
  for ( std::size_t i=0 ; i<SIZE ; ++i )
    x[i] = (std::rand()/(RAND_MAX+1.)-0.5)/10. ;
}

void multiply( Array const & x, Array & y ) {
  for ( std::size_t r=0 ; r<REPEAT ; ++r )
    for ( std::size_t i=0 ; i<SIZE ; ++i )
      y[i] += x[i] ;
}
      
void reduce( Array const & y ) {
  double res {0.} ;
  for ( std::size_t i=0 ; i<SIZE ; ++i ) {
    res += y[i] ;
  }
  std::cout<<(res/SIZE)<<std::endl ;
}

int main()
 {
  Array x, y ;
  randomize(x) ;
  y.fill(0.) ;
  multiply(x,y) ;
  reduce(y) ;
 }