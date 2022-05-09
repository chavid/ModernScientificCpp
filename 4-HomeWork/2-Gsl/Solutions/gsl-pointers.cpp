#include <iostream>
#include <type_traits>
#include <cassert>

class Demo
 {
  public:
    Demo() { std::cout<<"Constructor"<<std::endl ; }
    void display() { std::cout<<"Display"<<std::endl ; }
    ~Demo() { std::cout<<"Destructor"<<std::endl ; }
 } ;

template <typename T, std::enable_if_t<std::is_pointer_v<T>, int> * = nullptr>
using my_owner = T ;

template <typename T, std::enable_if_t<std::is_pointer_v<T>, int> * = nullptr>
class my_not_null
 {
  public :
    my_not_null( T p ) : m_p(p) { assert(p) ; }
    my_not_null & operator=( T p ) { assert(p) ; m_p = p ; return *this ; } 
    T operator->() { return m_p ; } 
  private :
    T m_p ;
 } ;

int main()
 {
  //my_owner<Demo> d1 ;              // COMPILATION ERROR, because Demo is not a pointer
  //my_not_null<Demo*> p1 ;          // COMPILATION ERROR, because p1 doesn't have an intial value
  //my_not_null<Demo*> p2(nullptr) ; // COMPILATION ERROR, because p2 cant' be null
  my_owner<Demo *> d2 = new Demo() ;
  my_not_null<Demo *> p3 = d2 ; 
  //p3 = nullptr ;                   // EXECUTION ERROR, because p3 can't be null
  p3->display() ;
  delete d2 ;
 }
