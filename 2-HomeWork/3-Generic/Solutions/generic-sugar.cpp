#include <type_traits>

template< typename T >
using my_remove_const_t = typename std::remove_const<T>::type ;
     
template< typename T >
void increment_and_display( T & value1 )
 {
  my_remove_const_t<T> value2 { value1 } ;
  ++value2 ;
  std::cout<<value2<<std::endl ;
 }

int main()
 {
  const int size = 10 ;
  increment_and_display(size) ;
 }