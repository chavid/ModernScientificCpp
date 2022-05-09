#include <vector>
#include <string>
#include <iostream>

class Sentence
 {
  public :
    void add( char const * word )
     { m_words.push_back(word) ; }
    auto begin() const { return m_words.begin() ; }
    auto end() const { return m_words.end() ; }
  private :
    std::vector<std::string> m_words ;
 } ;

std::ostream & operator<<( std::ostream & os, Sentence const & s )
 {
  for ( auto const & word : s )
   { os<<word<<" " ; }
  return os ;
 }
 
int main()
 {
  Sentence s ;
  s.add("Hello") ;
  s.add("world") ;
  s.add("!") ;
  std::cout<<s<<std::endl ;
 }
