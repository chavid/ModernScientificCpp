#include <iostream>
#include <vector>
#include <variant>

struct Electron
 { void affiche(){ std::cout<<"E"<<std::endl ; } } ;

struct Proton
 { void affiche(){ std::cout<<"P"<<std::endl ; } } ;

struct Neutron
 { void affiche(){ std::cout<<"N"<<std::endl ; } } ;

using Particule = std::variant<Electron,Proton,Neutron> ;

int main()
 {
  std::vector<Particule> ps =
   { Electron(), Proton(), Neutron() } ;

  for ( auto par : ps )
    std::visit( []( auto p )
     {  p.affiche() ; } , par ) ; 
 }