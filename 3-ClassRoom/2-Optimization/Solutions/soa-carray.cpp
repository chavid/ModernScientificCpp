#include <iostream>
#include <cassert> // for assert
#include <cstdlib> // for rand

struct XY
 {
  double x, y {0.} ;
//  void saxpy( double a )
//   { y = a*x + y ; }
 } ;

class SoA
 {
  public :
    SoA( int size ) : m_size{size}, m_xs{new double[size]}, m_ys{new double[size]} {}
    ~SoA() { delete [] m_xs ; delete [] m_ys ; }
    int size() { return m_size ; }
    XY operator()( int indice ) const
     { return { m_xs[indice], m_ys[indice] } ; }
    auto & xs() { return m_xs ; }
    auto & ys() { return m_ys ; }
    void saxpy( double a )
     {
      for ( int i=0 ; i<m_size ; ++i )
        m_ys[i] = a*m_xs[i] + m_ys[i] ;
     }
  private :
    int m_size ;
    double * __restrict__ m_xs ;
    double * __restrict__ m_ys ;
 } ;

void randomize_x( SoA & collection )
 {
  srand(1) ;
  for ( int i=0 ; i<collection.size() ; ++i )
   { collection.xs()[i] = std::rand()/(RAND_MAX+1.)-0.5 ; }
 }

double accumulate_y( SoA & collection )
 {
  double res {0.} ;
  for ( int i=0 ; i<collection.size() ; ++i )
   { res += collection.ys()[i] ; }
  return res ;
 }

int main( int argc, char * argv[] )
 {
  assert(argc==3) ;
  int size {atoi(argv[1])} ;
  int repeat {atoi(argv[2])} ;
  std::cout.precision(18) ;

  SoA collection(size) ;
  randomize_x(collection) ;
  while (repeat--)
    collection.saxpy(0.1) ;
  double res = accumulate_y(collection)/size ;
  std::cout<<res<<std::endl ;
 }
