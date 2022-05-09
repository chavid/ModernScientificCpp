#include <iostream>
#include <array>

template <typename T>
class my_span
 {
  public :
    template <typename Col>
    my_span( Col & c ) : m_p0(&c[0]), m_size(c.size()) {}
    T & operator[]( std::size_t indice ) { return *(m_p0+indice) ; } 
    std::size_t size() { return m_size ; } 
  private :
    T * const m_p0 ;
    const std::size_t m_size ;
 } ;

template <typename T>
void display( my_span<T> data )
 {
   for( std::size_t i = 0 ; i < data.size() ; ++i )
     std::cout << data[i] << ' ' ;
   std::cout << std::endl ;
 }
 
int main()
 {
  std::array<int,5> arr = { 1, 2, 3, 4, 5 } ;
  my_span<int> s { arr } ;
  display(s) ;  
  return 0 ;
}
