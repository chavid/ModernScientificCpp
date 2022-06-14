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
  std::valarray<double> datas(size) ;
  for ( double & data : datas )
   { data = std::rand()/(RAND_MAX+1.) ; }
  return datas ;
 }

double analyse1( std::valarray<double> const & datas, int power )
 {
  double res = 0 ;
  for ( double data : datas )
   {
    double val = 1 ; 
    for ( int j=0 ; j<power ; ++j )
      val *= data ;
    res += val ;
   }
  return res ;
 }

double analyse2( std::valarray<double> datas, int power )
 {
  std::valarray<double> vals(1.,datas.size()) ;
  for ( int j=0 ; j<power ; ++j )
   { vals *= datas ; }
  double res = 0 ;
  for ( double val : vals )
   { res += val ; }
  return res ;
 }

int main( int argc, char * argv[] )
 {
  assert(argc==3) ;
  int size {atoi(argv[1])} ;
  int power {atoi(argv[2])} ;

  auto datas = time("gen",generate,size) ;
  auto res1 = time("ana1",analyse1,datas,power) ;
  auto res2 = time("ana2",analyse2,datas,power) ;
  std::cout << res1 << " " << res2 << std::endl ;
 }