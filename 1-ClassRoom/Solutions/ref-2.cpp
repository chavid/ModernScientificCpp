
#include <iostream>

template < typename T >
class Ref {
  public :
    Ref( T & data ) : m_data(data) {}
    void operator=( T data ) { m_data = data ; }
  private :
    T & m_data ;
} ;

template < typename T >
Ref<T> make_ref( T & data ) {
  return Ref<T>(data) ;
}

template < typename T >
void f( T data ) {
  data = 42 ;
}

int main() {
  int i = 0, j = 0 ;
  f(i) ;
  f(make_ref(j)) ;
  std::cout<<i<<" "<<j<<std::endl ;
  return 0 ;
}

