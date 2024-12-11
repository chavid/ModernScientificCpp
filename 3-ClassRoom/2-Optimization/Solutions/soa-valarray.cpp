#include <iostream>
#include <cassert> // for assert
#include <cstdlib> // for rand
#include <valarray>
#include <format>

struct XY
 { double x, y {0.} ; } ;

class SoA
 {
  public :
    SoA( std::size_t size ) : m_xs(size), m_ys(size) {}
    XY operator()( std::size_t indice ) const
     { return { m_xs[indice], m_ys[indice] } ; }
    auto & xs() { return m_xs ; }
    auto & ys() { return m_ys ; }
    void saxpy( double a )
     { m_ys = a*m_xs + m_ys ; }
  private :
    std::valarray<double> m_xs ;
    std::valarray<double> m_ys ;
 } ;

void randomize_x( SoA & collection )
 {
  srand(1) ;
  for ( auto & element : collection.xs() )
   { element = std::rand()/(RAND_MAX+1.)-0.5 ; }
 }

double accumulate_y( SoA & collection )
 {
  double res {0.} ;
  for ( auto element : collection.ys() )
   { res += element ; }
  return res ;
 }

int main( int argc, char * argv[] )
 {
  assert(argc==3) ;
  std::size_t size {std::strtoull(argv[1],nullptr,10)} ;
  std::size_t repeat {std::strtoull(argv[2],nullptr,10)} ;

  SoA collection(size) ;
  randomize_x(collection) ;
  double volatile a {0.1} ;
  while (repeat--)
    collection.saxpy(a) ;
  double res = accumulate_y(collection)/size ;
  std::cout<<std::format("{}",res)<<std::endl ;
 }
