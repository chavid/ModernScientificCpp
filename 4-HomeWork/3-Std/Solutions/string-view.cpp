#include <iostream>
#include <string_view>

auto count_characters( std::string_view text )
 { return text.size() ; }

int main( int argc, char * argv[] )
 {
  unsigned long long nb { 0 } ;
  for ( unsigned long long i = 0 ; i< 100000 ; ++i )
   { nb += count_characters("Hello world !") ; }
  std::cout<<nb<<" characters"<<std::endl ;
  return 0 ;
 }