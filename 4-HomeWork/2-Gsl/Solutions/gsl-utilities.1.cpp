#include <iostream>
#include <cassert>

template <typename TypeOut>
struct no_narrow
 {
  TypeOut m_data ;
  template <typename TypeIn>
  no_narrow( TypeIn data ) : m_data(data)
   { assert(static_cast<TypeOut>(data)==data) ; }
  operator TypeOut() { return m_data ; }
 } ;
 
int main()
 {     
  double d1 = 42 ;
  int i1 = no_narrow<int>(d1) ;
  std::cout<<i1<<std::endl ;
  double d2 = 3.14 ;
  int i2 = no_narrow<int>(d2) ;
  std::cout<<i2<<std::endl ;
 }