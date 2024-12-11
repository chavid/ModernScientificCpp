#include <iostream>
#include <cassert> // for assert
#include <cstdlib> // for rand
#include <format>

struct XY
 { double x, y {0.} ; } ;

class SoA
 {
  public :
    SoA( std::size_t size ) : m_size{size}, m_xs{new double[size]}, m_ys{new double[size]} {}
    ~SoA() { delete [] m_xs ; delete [] m_ys ; }
    std::size_t size() { return m_size ; }
    XY operator()( std::size_t indice ) const
     { return { m_xs[indice], m_ys[indice] } ; }
    auto & xs() { return m_xs ; }
    auto & ys() { return m_ys ; }
    void saxpy( double a )
     {
      for ( std::size_t i=0 ; i<m_size ; ++i )
        m_ys[i] = a*m_xs[i] + m_ys[i] ;
     }
  private :
    std::size_t m_size ;
    double * __restrict__ m_xs ;
    double * __restrict__ m_ys ;
 } ;

void randomize_x( SoA & collection )
 {
  srand(1) ;
  for ( std::size_t i=0 ; i<collection.size() ; ++i )
   { collection.xs()[i] = std::rand()/(RAND_MAX+1.)-0.5 ; }
 }

double accumulate_y( SoA & collection )
 {
  double res {0.} ;
  for ( std::size_t i=0 ; i<collection.size() ; ++i )
   { res += collection.ys()[i] ; }
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
