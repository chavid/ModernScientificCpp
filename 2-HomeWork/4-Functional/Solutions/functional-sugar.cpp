#include <iostream>
#include <vector>
#include <tuple>

struct IndexedVector : public std::vector<double>
 {
  struct Iterator
   {
    size_type index ;
    IndexedVector const & data ;
    void operator++() { ++index ; }
    bool operator!=( Iterator const & itr )
     { return index!=itr.index ; }
    std::tuple<size_type,double> operator*()
     { return std::make_tuple(index,data[index]) ; }
   } ;
  using std::vector<double>::vector ;
  Iterator begin() { return Iterator{0,*this} ; }
  Iterator end() { return Iterator{size(),*this} ; }
 } ;

int main()
 {
  IndexedVector values = { 1.1, 2.2, 3.3, 4.4, 5.5 } ;
  for ( auto [ index, value ] : values  )
   { std::cout<<index<<" "<<value<<std::endl ; }
  return 0 ;
 }
