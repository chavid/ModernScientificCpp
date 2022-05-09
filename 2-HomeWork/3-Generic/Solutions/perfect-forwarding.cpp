#include <iostream>
#include <tuple>

template< typename ... Types >
auto my_make_tuple( Types ... args )
 { return std::tuple( std::forward<Types>(args) ... ) ; }

int main()
 {
  auto data = my_make_tuple(3.1416,42) ;
  std::cout << get<0>(data) << " " << get<1>(data) << std::endl ;
 }
