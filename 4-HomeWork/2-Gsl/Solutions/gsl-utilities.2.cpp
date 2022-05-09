#include <iostream>

template <typename Function>
struct FinalAction
 {
  Function m_f ;
  FinalAction( Function f ) : m_f(f) {}
  ~FinalAction() { m_f() ; }
 } ;
 
template <typename Function>
auto my_finally( Function f )
 { return FinalAction<Function>(f) ; }

int main()
 {     
  std::cout<<"Step 1"<<std::endl ;
  auto _ = my_finally([](){ std::cout<<"Step 3"<<std::endl ; }) ;
  std::cout<<"Step 2"<<std::endl ;
 }
