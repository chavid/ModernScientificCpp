#include <iostream>
#include <array>

template< typename Function1, typename Function2 >
auto compose( Function1 f1, Function2 f2 )
 { return [f1,f2]( auto val ){ return f1(f2(val)) ; } ; }

int square( int i ) { return i*i ; }
void display( int i ) { std::cout<<i<<std::endl ; }

int main()
 {     
  std::array<int,5> table { 1, 2, 3, 4, 5 } ;
  std::for_each(table.begin(),table.end(),compose(display,square)) ;
 }
