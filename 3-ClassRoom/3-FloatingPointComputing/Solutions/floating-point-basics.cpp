#include <iostream>
#include <cassert> // for assert
#include <limits>
#include <string_view>

template< typename real >
void display_limits( std::string_view title )
 {
  std::cout<<"# "<<title<<std::endl ;
  std::cout<<"size    : "<<sizeof(real)<<" bytes"<<std::endl ;
  std::cout<<"max     : "<<std::numeric_limits<real>::max()<<std::endl ;
  std::cout<<"min     : "<<std::numeric_limits<real>::min()<<std::endl ;
  std::cout<<"epsilon : "<<std::numeric_limits<real>::epsilon()<<std::endl ;
 }

int main( int argc, char * argv[] )
 {
  assert(argc==1) ;
  std::cout.precision(18) ;
  display_limits<float>("float") ;
  display_limits<double>("double") ;
  display_limits<long double>("long double") ;
  display_limits<__float80>("__float80") ;
  //display_limits<__float128>("__float128") ;
 }
