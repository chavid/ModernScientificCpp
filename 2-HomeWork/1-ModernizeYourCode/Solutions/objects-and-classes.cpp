#include <cstdlib> // for std::rand()
#include <iostream>
#include <string>

class Particle
 {
  public  :
    Particle( double mass ) : m_mass {mass} {}
    Particle( Particle const & ) = delete ;
    virtual ~Particle() = default ;
    double mass() { return m_mass ; }
    virtual std::string name() { return "Particle" ; }
  private  :
    double m_mass ;
 } ;

class ChargedParticle : public Particle
 {
  public  :
    ChargedParticle( double mass, double charge )
     : Particle(mass), m_charge {charge} {}
    double charge() { return m_charge ; }
    std::string name() override { return "ChargedParticle" ; }
  private  :
    double m_charge = 0.0 ;
 } ;

void display( Particle & p  )
 {
  std::cout << p.name() << std::endl ;          
  std::cout << "  mass   = " << p.mass() << std::endl ;         
 }

int main()
 {
  for ( int i = 0 ; i < 5 ; ++i )
   {
    if ( std::rand() < (0.5 *  double(RAND_MAX)) )
     {
      Particle p {2} ;
      display(p) ;
     }
    else
     {
      ChargedParticle p {1,1} ;
      display(p) ;
      std::cout << "  charge = " << p.charge() << std::endl ;         
     }
   }
 }