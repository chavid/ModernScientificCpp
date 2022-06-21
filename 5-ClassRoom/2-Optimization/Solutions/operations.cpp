#include <cstdlib>
#include <array>

int const SIZE = 1024 ;
int const REPEAT = 100000 ;

using Array = std::array<double,SIZE> ;

void randomize( Array & x ) {
  srand(1) ;
  for ( int i=0 ; i<SIZE ; ++i )
    x[i] = (std::rand()/(RAND_MAX+1.)-0.5)/10. ;
}

void multiply( Array const & x, Array & y ) {
  for ( int r=0 ; r<REPEAT ; ++r )
    for ( int i=0 ; i<SIZE ; ++i )
      y[i] += x[i] ;
}
      
void reduce( Array const & y ) {
  double res {0.} ;
  for ( int i=0 ; i<SIZE ; ++i ) {
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