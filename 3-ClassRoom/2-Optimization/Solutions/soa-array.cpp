#include <iostream>
#include <cassert> // for assert
#include <cstdlib> // for rand
#include <array>
#include <format>

struct XY
 { double x, y {0.} ; } ;

constexpr std::size_t size_max {10000} ;

class SoA
 {
  public :
    SoA( std::size_t size ) : m_size{size}, m_xs{}, m_ys{}
     { assert(size<=size_max) ; }
    XY operator()( std::size_t indice ) const
     { return { m_xs[indice], m_ys[indice] } ; }
    auto xs_begin() { return m_xs.begin() ; }
    auto xs_end() { return m_xs.begin()+m_size ; }
    auto ys_begin() { return m_ys.begin() ; }
    auto ys_end() { return m_ys.begin()+m_size ; }
    void saxpy( double a )
     {
      for ( std::size_t i=0 ; i<m_size ; ++i )
        m_ys[i] = a*m_xs[i] + m_ys[i] ;
     }
  private :
    std::size_t m_size ;
    std::array<double,size_max> m_xs ;
    std::array<double,size_max> m_ys ;
 } ;

void randomize_x( SoA & col )
 {
  srand(1) ;
  for ( auto itr = col.xs_begin() ; itr != col.xs_end() ; ++itr )
   { *itr = std::rand()/(RAND_MAX+1.)-0.5 ; }
 }

double accumulate_y( SoA & col )
 {
  double res {0.} ;
  for ( auto itr = col.ys_begin() ; itr != col.ys_end() ; ++itr )
   { res += *itr ; }
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
