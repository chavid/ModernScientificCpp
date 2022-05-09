#include <iostream>
#include <list>

template< unsigned MAX >
class Mot {
public :
    static_assert(MAX>1,"Nombre max de caractères par mot TROP BAS.") ;
    Mot( char const * texte ) {
        for ( unsigned i = 0 ; i<MAX ; ++i ) {
            m_donnees[i] = texte[i] ;
            if (!m_donnees[i]) break ;
        }
        m_donnees[MAX-1] = 0 ;
    }
private :
    char m_donnees[MAX] ;
    friend std::ostream & operator<<( std::ostream & os, Mot const & m ) {
        return (os<<m.m_donnees) ;
    }
} ;

template< unsigned MAX >
class Phrase {
public :
    void ajoute( char const * texte ) {
        m_donnees.push_back(texte) ;
    }
private :
    std::list<Mot<MAX> > m_donnees ;
    friend std::ostream & operator<<( std::ostream & os, Phrase const & phr ) {
        for ( auto const & mot : phr.m_donnees ) {
            os<<mot<<" " ;
        }
        return os ;
    }
} ;

int main() {
    Phrase<10> phrase ;
    phrase.ajoute("Bonjour") ;
    phrase.ajoute("le") ;
    phrase.ajoute("monde") ;
    phrase.ajoute("!") ;
    std::cout<<phrase<<std::endl ;
}
