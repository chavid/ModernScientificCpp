#include <iostream>
#include <string>
#include <random>

class Particule {
public  :
    explicit Particule( double masse ) : m_masse {masse} {}
    Particule( Particule const & ) = delete ;
    double masse() { return m_masse ; }
    virtual std::string nom() { return "Particule" ; }
    virtual ~Particule() = default ;
private  :
    double m_masse = 0 ;
} ;

class ParticuleNonChargee : public Particule {
public  :
    using Particule::Particule ;
    virtual std::string nom() override
     { return "ParticuleNonChargee" ; }
} ;

class ParticuleChargee : public Particule {
public  :
    ParticuleChargee( double masse, double charge )
     : Particule(masse), m_charge {charge} {}
    double charge() { return m_charge ; }
    virtual std::string nom() override
     { return "ParticuleChargee" ; }
private  :
    double m_charge ;
} ;

void affiche( Particule & p  ) {
    std::cout << p.nom() << std::endl ;          
    std::cout << "masse = " << p.masse() << std::endl ;         
}

int main() {
    std::random_device rd ;
    std::default_random_engine gen {rd()} ;
    std::uniform_int_distribution<unsigned> dis {0,1} ;
    unsigned alea = dis(gen) ;
    
    if (alea==0) {
        ParticuleNonChargee p {2} ;
        affiche(p) ;
    }
    else if (alea==1) {
        ParticuleChargee p {1,1} ;
        affiche(p) ;
        std::cout << "charge = " << p.charge() << std::endl ;         
    }
}