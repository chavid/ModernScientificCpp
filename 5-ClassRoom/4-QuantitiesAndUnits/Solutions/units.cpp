
#include <iostream>

template< typename UnderlyingType, typename TagType >
class StrongTypedef
 {
  public :
    explicit StrongTypedef( UnderlyingType value ) : my_value{value} {}
    explicit operator UnderlyingType() { return my_value ; }
  private :
    UnderlyingType my_value ;
 } ;

using Km = StrongTypedef<double,struct KmTag> ;
using Liter = StrongTypedef<double,struct LiterTag> ;

class Journey
 {
  public :
    Journey( Km distance, Liter fuel )
     : my_distance{distance}, my_fuel{fuel} {}
    double consumption() { return static_cast<double>(my_fuel)/static_cast<double>(my_distance)*100. ; }
  private :
    Km my_distance ;
    Liter my_carburant ;
 } ;

int main()
 {
  Km distance { 28 } ;
  Liter fuel { 2.38 } ;
  Journey t { distance, fuel } ;
  std::cout<<t.consumption()<<" l/100km"<<std::endl;
 }
