#include <iostream>
#include <string>

class FromTo
 {
  public :
    struct Itr
     {
      int val ;
      bool operator!=( Itr const & itr ) const { return (val!=itr.val) ;  }
      int operator*() const { return val ; }
      Itr & operator++() { ++val ; return *this ; }
     } ;
    constexpr FromTo( int from, int to ) : from_{from}, to_{to} {}
    Itr begin() const { return Itr{from_} ; }
    Itr end() const { return Itr{to_} ; }
  private :
    int const from_, to_ ;
 } ;

template< int from, int to >
void count( std::string const & name  )
 {
  constexpr FromTo range(from,to) ;
  std::cout<<name ;
  for ( auto rank : range )
   { std::cout<<", "<<rank ; }
  std::cout<<std::endl ;
 }

int main()
 {
  count<0,3>("First") ;
  count<0,7>("Second") ;
  return 0 ;
 }