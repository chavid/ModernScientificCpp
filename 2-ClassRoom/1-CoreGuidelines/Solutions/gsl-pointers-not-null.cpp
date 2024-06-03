#include <iostream>
#include <type_traits>
#include <cassert>

class Demo
 {
  public:
    Demo() { std::cout<<"Constructor"<<std::endl ; }
    void print() { std::cout<<"Printing"<<std::endl ; }
    ~Demo() { std::cout<<"Destructor"<<std::endl ; }
 } ;

template <typename T, typename = std::enable_if_t<std::is_pointer_v<T>>>
class my_not_null
 {
  public :
    my_not_null( T p ) : m_p{p} { assert(p) ; } 
    my_not_null & operator=( T p ) { assert(p) ; m_p = p ; return *this ; } 
    T operator->() { return m_p ; } 
  private :
    T m_p ;
 } ;

int main() {
  //my_not_null<Demo*> p1 ;             // COMPILATION ERROR: p1 is not initialized
  //my_not_null<Demo*> p2 { nullptr } ; // COMPILATION ERROR: p2 cannot be null
  my_not_null<Demo *> p3 = new Demo() ;
  //p3 = nullptr ;                      // COMPILATION ERROR: p3 cannot be null
  p3->print() ;
  delete p3 ;
}