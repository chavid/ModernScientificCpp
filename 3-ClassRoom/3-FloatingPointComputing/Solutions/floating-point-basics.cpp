#include <iostream>
#include <limits>
#include <string_view>
#include <stdfloat>
#include <format>

template< typename real >
void display_limits( std::string_view title )
 {
  std::cout<<"# "<<title<<std::endl ;
  std::cout<<"size    : "<<sizeof(real)<<" bytes"<<std::endl ;
  std::cout<<"max     : "<<std::format("{}""",std::numeric_limits<real>::max())<<std::endl ;
  std::cout<<"max+1     : "<<std::format("{}""",(std::numeric_limits<real>::max()+1))<<std::endl ;
  std::cout<<"min     : "<<std::numeric_limits<real>::min()<<std::endl ;
  std::cout<<"epsilon : "<<std::numeric_limits<real>::epsilon()<<std::endl ;
 }
 
#if __STDCPP_FLOAT128_T__ == 1
template<>
void display_limits<std::float128_t>( std::string_view title )
 {
  std::cout<<"# "<<title<<std::endl ;
  std::cout<<"size    : "<<sizeof(std::float128_t)<<" bytes"<<std::endl ;
 }
#endif
 
int main()
 {
  std::cout.precision(18) ;
    
  std::cout<<std::endl ;

  display_limits<float>("float") ;
  display_limits<double>("double") ;
  display_limits<long double>("long double") ;
  display_limits<__float80>("__float80") ;
  //display_limits<__float128>("__float128") ;
  
  std::cout<<std::endl ;
  
  #if __STDCPP_FLOAT16_T__ == 1
  display_limits<std::float16_t>("float16") ;
  #endif
  
  #if __STDCPP_BFLOAT16_T__ == 1
  display_limits<std::bfloat16_t>("bfloat16") ;
  #endif
  
  #if __STDCPP_FLOAT32_T__ == 1
  display_limits<std::float32_t>("float32") ;
  #endif
  
  #if __STDCPP_FLOAT64_T__ == 1
  display_limits<std::float64_t>("float64") ;
  #endif
  
  #if __STDCPP_FLOAT128_T__ == 1
  display_limits<std::float128_t>("float128") ;
  #endif
  
  std::cout<<std::endl ;

 }
