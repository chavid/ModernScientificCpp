#include <iostream>
#include <cassert> // for assert
#include <cstdlib> // for rand & atoi

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
    explicit DynArray( int size ) : m_size{size}, m_data{new T [size]} {}
    T * begin() { return m_data ; }
    T * end() { return m_data+m_size ; }
    int size() { return m_size ; }
    T & operator[]( int indice ) { return m_data[indice] ; }
    T const & operator[]( int indice ) const { return m_data[indice] ; }
    ~DynArray() { delete [] m_data ; }
  private :
    int m_size ;
    T * m_data ;
 } ;

int main( int argc, char * argv[] )
 {
  assert(argc==3) ;
  int size {atoi(argv[1])} ;
  int repeat {atoi(argv[2])} ;
  std::cout.precision(18) ;

  DynArray<XY> collection(size) ;
  auto begin {std::begin(collection)} ;
  auto end {std::end(collection)} ;

  randomize_x(begin,end) ;
  while (repeat--)
    saxpy(begin,end,0.1) ;
  double res {accumulate_y(begin,end)/size} ;
  std::cout<<res<<std::endl ;
 }
