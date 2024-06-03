#include <iostream>
#include <type_traits>
#include <cassert>

class Demo {
  public:
    Demo() { std::cout<<"Constructor"<<std::endl ; }
    void print() { std::cout<<"Printing"<<std::endl ; }
    ~Demo() { std::cout<<"Destructor"<<std::endl ; }
} ;

template <typename T, typename = std::enable_if_t<std::is_pointer_v<T>>>
using my_owner = T ;

int main() {
  //my_owner<Demo> p1 ;              // COMPILATION ERROR: Demo is not a pointer
  my_owner<Demo *> p2 {new Demo()} ;
  p2->print() ;
  delete p2 ;
}
