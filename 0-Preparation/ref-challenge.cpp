//
// To be compiled in C++98
// Modify the class Ref, and only this class, so that
// the call to f(Ref<int>(j)) modify the value of j,
// although f(i) does not modify i. 
// The final display should be : 0 42
//

#include <iostream>

template < typename T >
void f( T a_value ) {
  a_value = 42 ;
}

template < typename T >
class Ref {
  public :
    Ref( T a_value ) { m_value = a_value ; }
    void operator=( T a_value ) { m_value = a_value ; }
  private :
    T m_value ;
} ;

int main() {
  int i = 0, j = 0 ;
  f(i) ;
  f(Ref<int>(j)) ;
  std::cout<<i<<" "<<j<<std::endl ;
  return 0 ;
}
