%%file tmp.precision.cpp

#include <iostream>
#include <cassert> // for assert
#include <cstdlib> // for rand
#include <valarray>
#include <stdfloat>
#include <complex>

// SoA of complex numbers
template< typename R >
class Complexes {
  public :  
    Complexes( std::size_t size ) : m_rs(size), m_is(size) {}
    std::complex<R> operator[]( int indice ) const
     { return { m_rs[indice], m_is[indice] } ; }
    std::valarray<R> & reals() { return m_rs ; }
    std::valarray<R> & imags() { return m_is ; }
    std::size_t size() { return m_rs.size() ; }
  private :
    std::valarray<R> m_rs, m_is ;
 } ;

Complexes<R> operator*( Complexes<R> const & lhs, Complexes<R> const & rhs ) {
  Complexes<R> res {lhs.size()} ;
  res.reals() = lhs.reals()*rhs.reals() - lhs.imags()*rhs.imags() ;
  res.imags() = rhs.reals()*lhs.imags() + lhs.reals()*rhs.imags() ;
  return res ;
}

template< typename R>
Complexes<R> random( std::size_t size )
 {
  srand(1) ;
  Complexes<R> cplxs {size} ;
  for ( std::size_t i = 0 ; i < cplxs.size() ; ++i )
   {
    long double e = 2*M_PI*(static_cast<long double>(std::rand())/RAND_MAX) ;
    cplxs.reals()[i] = static_cast<R>(std::cosl(e)) ;
    cplxs.imags()[i] = static_cast<R>(std::sinl(e)) ;
   }
  return cplxs ;
 }

template< typename R>
Complexes<R> pow( Complexes<R> & cplxs, long long degree )
 {
  Complexes<R> res {cplxs} ;
  for ( long long d = 1 ; d < degree ; ++d ) {
    res = res*cplxs ;
  }
  return res ;
 }

template< typename R>
long double reduce( Complexes<R> const & cplxs )
 {
  std::complex<R> res { static_cast<R>(1.), static_cast<R>(0.) } ;
  for ( std::size_t i = 0 ; i < cplxs.size() ; ++i )
   { res *= cplxs[i] ; }
  return static_cast<long double>(res) ;
 }

template< typename R>
void main_impl( std::size_t size, long long degree )
 { std::cout<<reduce(pow(random(size),degree))<<std::endl ; }

int main( int argc, char * argv[] )
 {
  assert(argc==4) ;
  std::string precision(argv[1]) ;
  std::size_t size = atoi(argv[2]) ;
  long long degree = atoll(argv[3]) ;
  std::cout.precision(18) ;

  if (precision=="half") main_impl<std::float16_t>(size,repeat) ;
  else if (precision=="float") main_impl<float>(size,repeat) ;
  else if (precision=="double") main_impl<double>(size,repeat) ;
  else if (precision=="long") main_impl<long double>(size,repeat) ;
  else if (precision=="quad") main_impl<std::float128_t>(size,repeat) ;
  else throw "unknown precision" ;
 }
 
