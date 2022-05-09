#include <cstring>
#include <iostream>

class Text
 {
  public :
    
    Text( char const * str )
     : m_size {std::strlen(str)+1},
       m_data {new char [m_size]}
     { std::copy(str,str+m_size,m_data) ; }
    
    Text( Text const & t )
     : m_size {t.m_size},
       m_data {new char [m_size]}
     {
      std::cout<<"copy constructor"<<std::endl ;
      std::copy(t.m_data,t.m_data+m_size,m_data) ;
     }
    
    Text( Text && t )
     : m_size {t.m_size},
       m_data {t.m_data}
     {
      std::cout<<"move constructor"<<std::endl ;
      t.m_size = 0 ; t.m_data = 0 ;
     }
    
    ~Text()
     { delete [] m_data ; }
    
    unsigned int size()
     { return m_size ; }
    
    char & operator[]( unsigned int i )
     { return m_data[i] ; }
    
    friend std::ostream & operator<<( std::ostream & os, Text const & t )
     { if (t.m_size) return os<<t.m_data ; else return os ; }
    
  private :
    
    std::size_t m_size ;
    char * m_data ;
 } ;
 
Text hello()
 { return "hello" ; }

Text uppercase( Text t )
 {
  for ( unsigned int i=0 ; i<t.size() ; ++i )
   { t[i] = std::toupper(t[i]) ; }
  return t ;
 }

int main()
 {
  std::cout<<uppercase(hello())<<std::endl ;
  return 0 ;
 }