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

class SoA
 {
  public :
    SoA( int size ) : m_xs(size), m_ys(size) {}
    XY operator()( int indice ) const
     { return { m_xs[indice], m_ys[indice] } ; }
    auto & xs() { return m_xs ; }
    auto & ys() { return m_ys ; }
    void saxpy( double a )
     {
      for ( unsigned i=0 ; i<m_xs.size() ; ++i )
        m_ys[i] = a*m_xs[i] + m_ys[i] ;
     }
  private :
    std::vector<double> m_xs ;
    std::vector<double> m_ys ;
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
