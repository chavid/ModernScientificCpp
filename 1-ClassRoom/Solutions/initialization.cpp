#include <vector>
#include <string>
#include <initializer_list>
#include <iostream>

class Sentence
 {
  public :
    Sentence( std::initializer_list<char const *> const & words )
     {
      for ( auto const & word : words )
       { m_words.emplace_back(static_cast<std::string>(word)) ; ; }
     }
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
  Sentence s { "Hello", "world", "!" } ;
  std::cout<<s<<std::endl ;
 }
