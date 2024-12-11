#include <iostream>
#include <cassert> // for assert
#include <cstdlib> // for rand & atoi
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

template< typename T >
class DynArray
 {
  public :
    explicit DynArray( std::size_t size ) : m_size{size}, m_data{new T [size]} {}
    T * begin() { return m_data ; }
    T * end() { return m_data+m_size ; }
    std::size_t size() { return m_size ; }
    T & operator[]( std::size_t indice ) { return m_data[indice] ; }
    T const & operator[]( std::size_t indice ) const { return m_data[indice] ; }
    ~DynArray() { delete [] m_data ; }
  private :
    std::size_t m_size ;
    T * m_data ;
 } ;

int main( int argc, char * argv[] )
 {
  assert(argc==3) ;
  std::size_t size {std::strtoull(argv[1],nullptr,10)} ;
  std::size_t repeat {std::strtoull(argv[2],nullptr,10)} ;

  DynArray<XY> collection(size) ;
  auto begin {std::begin(collection)} ;
  auto end {std::end(collection)} ;

  randomize_x(begin,end) ;
  double volatile a {0.1} ;
  while (repeat--)
    saxpy(begin,end,a) ;
  double res {accumulate_y(begin,end)/size} ;
  std::cout<<std::format("{}",res)<<std::endl ;
 }
