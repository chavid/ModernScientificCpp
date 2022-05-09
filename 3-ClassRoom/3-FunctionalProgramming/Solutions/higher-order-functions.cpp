#include <iostream>
#include <array>

template< typename Function1, typename Function2 >
auto compose( Function1 f1, Function2 f2 )
 { return [f1,f2]( auto val ){ return f1(f2(val)) ; } ; }

int square( int i ) { return i*i ; }
int inc( int i ) { return i+1 ; }

int main()
 {     
  std::array<int,5> table { 1, 2, 3, 4, 5 } ;
  auto f = compose(inc,square) ;
  for ( auto element : table )
    std::cout<<f(element)<<std::endl ;
 }
