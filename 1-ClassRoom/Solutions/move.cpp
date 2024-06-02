#include <cstring>
#include <iostream>

class Text
 {
  public :
    
    Text()
     : m_size(0),
       m_data(0)
     {}
    
    Text( char const * str )
     : m_size(std::strlen(str)),
       m_data(m_size?(new char [m_size+1]):0)
     { if (m_size) std::copy(str,str+m_size+1,m_data) ; }
    
    Text( Text const & t )
     : m_size(t.m_size),
       m_data(m_size?(new char [m_size+1]):0)
     {
      std::cout<<"copy constructor"<<std::endl ;
      if (m_size) std::copy(t.m_data,t.m_data+m_size+1,m_data) ;
     }
    
    Text( Text && t )
     : m_size(t.m_size),
       m_data(t.m_data)
     {
      std::cout<<"move constructor"<<std::endl ;
      t.m_size = 0 ;
      t.m_data = 0 ;
     }
    
    Text & operator=( Text const & t )
     {
      std::cout<<"copy assignment"<<std::endl ;
      if (this == &t) return *this ;
      delete [] m_data ;
      m_size = t.m_size ;
      m_data = m_size?(new char [m_size+1]):0 ;
      if (m_size) std::copy(t.m_data,t.m_data+m_size+1,m_data) ;
      return *this ;
     }
    
    Text & operator=( Text && t )
     {
      std::cout<<"move assignment"<<std::endl ;
      if (this == &t) return *this ;
      delete [] m_data ;
      m_size = t.m_size ;
      m_data = t.m_data ;
      t.m_size = 0 ;
      t.m_data = 0 ;
      return *this ;
     }
    
    ~Text()
     { delete [] m_data ; }
    
    unsigned int taille()
     { return m_size ; }
    
    char & operator[]( unsigned int i )
     { return m_data[i] ; }
    
    friend std::ostream & operator<<( std::ostream & os, Text const & t )
     { if (t.m_size) return os<<t.m_data ; else return os ; }
    
  private :
    
    unsigned int m_size ;
    char * m_data ;
 } ;
 
Text hello()
 { return "hello" ; }

Text uppercase( Text t )
 {
  for ( unsigned int i=0 ; i<t.taille() ; ++i )
   { t[i] = std::toupper(t[i]) ; }
  return t ;
 }

int main()
 {
  std::cout<<uppercase(hello())<<std::endl ;
  return 0 ;
 }
