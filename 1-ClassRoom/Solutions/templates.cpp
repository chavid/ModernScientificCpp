#include <memory>
#include <iostream>

class MyData
 {
  public :
    MyData( int i, double d ) : m_i(i), m_d(d)
     { std::cout<<"MyData::MyData()"<<std::endl ; }
    int i() { return m_i ; }
    double d() { return m_d ; }
    ~MyData() { std::cout<<"MyData::~MyData()"<<std::endl ; }
  private :
    int m_i ;
    double m_d ;
 } ;

void display( std::shared_ptr<MyData> data_ptr )
 { std::cout<<data_ptr->i()<<" "<<data_ptr->d()<<std::endl ; }  

template <typename T, typename... Args>
std::shared_ptr<T> make_ptr( Args... args )
 { return std::make_shared<T>(args...) ; }  

int main()
 {
  auto data_ptr {make_ptr<MyData>(42,3.14)} ;
  display(data_ptr) ;
  return 0 ;
 }
