#include <valarray>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string_view>
#include <chrono>

template< typename Fonction, typename... ArgTypes >
auto time( std::string_view title, Fonction f, ArgTypes... args )
 {
  using namespace std::chrono ;
  auto t1 {steady_clock::now()} ;

  auto res {f(args...)} ;
   
  auto t2 {steady_clock::now()} ;
  auto dt {duration_cast<microseconds>(t2-t1).count()} ;
     
  std::cout<<"("<<title<<" time: "<<dt<<" us)"<<std::endl ;
  return res ;
 }

std::valarray<double> generate( int size )
 {
  std::valarray<double> data(size) ;
  for ( double & value : data ) {
    value = std::rand()/(RAND_MAX+1.) ;
  }
  return data ;
 }

double analyse1( std::valarray<double> const & data, int power )
 {
  double res = 0 ;
  for ( double value : data ) {
    double prod = 1 ; 
    for ( int j=0 ; j<power ; ++j ) {
      prod *= value ;
    }
    res += prod ;
   }
  return res ;
 }

double analyse2( std::valarray<double> const & data, int power )
 {
  std::valarray<double> values(1.,data.size()) ;
  for ( int j=0 ; j<power ; ++j ) {
    values *= data ;
  }
  double res = 0 ;
  for ( double value : values ) {
    res += value ;
  }
  return res ;
 }

int main( int argc, char * argv[] ) {
  assert(argc==3) ;
  std::size_t size {atoull(argv[1])} ;
  int power {atoi(argv[2])} ;

  auto datas = time("gen",generate,size) ;
  auto res1 = time("ana1",analyse1,datas,power) ;
  auto res2 = time("ana2",analyse2,datas,power) ;
  std::cout << res1 << " " << res2 << std::endl ;
 }