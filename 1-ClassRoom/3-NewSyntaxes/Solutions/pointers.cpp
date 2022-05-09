#include <memory>
#include <iostream>

class MyData
 {
  public :
    MyData( int data ) : m_data {data}
     { std::cout<<"MyData::MyData("<<m_data<<")"<<std::endl ; }
    int data() const { return m_data ; }
    ~MyData() { std::cout<<"MyData::~MyData("<<m_data<<")"<<std::endl ; }
  private :
    int m_data ;
 } ;

void display( std::unique_ptr<MyData> const & data_ptr )
 { std::cout<<data_ptr->data()<<std::endl ; }  

int main()
 {
  auto data_ptr = std::make_unique<MyData>(42) ;
  display(data_ptr) ;
  return 0 ;
 }
