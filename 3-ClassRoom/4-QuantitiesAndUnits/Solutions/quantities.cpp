#include <iostream>

template< typename UnderlyingType, typename TagType >
class StrongTypedef
 {
  public  :
    using UT = UnderlyingType ;
    constexpr explicit StrongTypedef( UnderlyingType value ) : my_value{value} {}
    constexpr explicit operator UnderlyingType() const { return my_value ; }
    constexpr UnderlyingType operator*( UnderlyingType value ) const { return my_value*value ; }
    constexpr UnderlyingType operator/( UnderlyingType value ) const { return my_value/value ; }
  private : 
    UnderlyingType my_value ;
 } ;
 
template< typename UT, typename TT >
constexpr auto operator*( UT lhs, StrongTypedef<UT,TT> rhs )
 { return StrongTypedef<UT,TT>{lhs*static_cast<UT>(rhs)} ; }
 
template< typename UT, typename TT1, typename TT2 >
constexpr auto operator/( const StrongTypedef<UT,TT1> & lhs, const StrongTypedef<UT,TT2> & rhs )
 { return (static_cast<UT>(lhs)/static_cast<UT>(rhs)) ; }

template< typename UT, typename TT >
auto & operator<<( std::ostream & os, StrongTypedef<UT,TT> data )
 { return (os<<static_cast<UT>(data)) ; }

using Liter = StrongTypedef<double,struct LiterTag> ;

constexpr Liter operator ""_L ( long double value )
 { return Liter{static_cast<Liter::UT>(1.l*value)} ; }
constexpr Liter operator ""_HL ( long double value )
 { return Liter{static_cast<Liter::UT>(100.l*value)} ; }
constexpr Liter operator ""_CL ( long double value )
 { return Liter{static_cast<Liter::UT>(0.01l*value)} ; }

using Meter = StrongTypedef<double,struct MeterTag> ;

constexpr Meter operator ""_M ( long double value )
 { return Meter{static_cast<Meter::UT>(.00001l*value)} ; }
constexpr Meter operator ""_KM ( long double value )
 { return Meter{static_cast<Meter::UT>(.01l*value)} ; }
constexpr Meter operator ""_MM ( long double value )
 { return Meter{static_cast<Meter::UT>(0.00000001l*value)} ; }

int main()
 {
  constexpr auto fuel { 2.38_L } ;
  constexpr auto distance { 28.3_KM } ;
  constexpr auto consumption = fuel/(distance/100._KM) ;
  std::cout<<consumption<<" l/100km"<<std::endl;
 }