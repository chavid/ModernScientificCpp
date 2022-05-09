#include <vector>
#include <string>
#include <initializer_list>
#include <iostream>

class Sentence
 {
  public :
    Sentence( std::initializer_list<std::string> const & words )
     {
      for ( std::string const & word : words )
       { m_words.push_back(word) ; }
     }
    auto begin() const { return m_words.begin() ; }
    auto end() const { return m_words.end() ; }
  private :
    std::vector<std::string> m_words ;
 } ;

std::ostream & operator<<( std::ostream & os, Sentence const & s )
 {
  for ( auto const & mot : s )
   { os<<mot<<" " ; }
  return os ;
 }
 
int main()
 {
  Sentence s { "Hello", "world", "!" } ;
  std::cout<<s<<std::endl ;
 }
