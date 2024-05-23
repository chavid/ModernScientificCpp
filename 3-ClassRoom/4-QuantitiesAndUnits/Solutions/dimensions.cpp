#include <iostream>
#include <cmath>

template< typename UnderlyingType, int s, int m >
class SiUnit
 {
  public :
    explicit constexpr SiUnit( UnderlyingType value ) : my_value{value} {}
    explicit constexpr operator UnderlyingType() const { return my_value ; }
  private :
    UnderlyingType my_value ;
 } ;

template< typename UT, int s, int m >
std::ostream & operator<<( std::ostream & os, const SiUnit<UT,s,m> & obj )
 { return (os<<static_cast<UT>(obj)) ; }

template< typename UT, int s1, int m1, int s2, int m2 >
constexpr auto operator*( SiUnit<UT,s1,m1> lhs, SiUnit<UT,s2,m2> rhs )
 { return SiUnit<UT,s1+s2,m1+m2>(static_cast<UT>(lhs)*static_cast<UT>(rhs)) ; }

template< typename UT, int s1, int m1, int s2, int m2 >
constexpr auto operator/( SiUnit<UT,s1,m1> lhs, SiUnit<UT,s2,m2> rhs )
 { return SiUnit<UT,s1-s2,m1-m2>(static_cast<UT>(lhs)/static_cast<UT>(rhs)) ; }

using Time = SiUnit<double,1,0> ;

constexpr Time operator ""_Se ( long double value )
 { return Time{static_cast<double>(value)} ; }
constexpr Time operator ""_Mi ( long double value )
 { return Time{static_cast<double>(value*60)} ; }
constexpr Time operator ""_H ( long double value )
 { return Time{static_cast<double>(value*60*60)} ; }

constexpr Time operator ""_Se ( unsigned long long value )
 { return Time{static_cast<double>(value)} ; }
constexpr Time operator ""_Mi ( unsigned long long value )
 { return Time{static_cast<double>(value*60)} ; }
constexpr Time operator ""_H ( unsigned long long value )
 { return Time{static_cast<double>(value*60*60)} ; }

constexpr Time Se { 1._Se } ;
constexpr Time Mi { 1._Mi } ;
constexpr Time H { 1._H } ;

using Length = SiUnit<double,0,1> ;

constexpr Length operator ""_M ( long double value )
 { return Length{static_cast<double>(value)} ; }
constexpr Length operator ""_KM ( long double value )
 { return Length{static_cast<double>(value*1000l)} ; }

constexpr Length operator ""_M ( unsigned long long value )
 { return Length{static_cast<double>(value)} ; }
constexpr Length operator ""_KM ( unsigned long long value )
 { return Length{static_cast<double>(value*1000ll)} ; }

constexpr Length M { 1._M } ;
constexpr Length KM { 1._KM } ;

using Speed = SiUnit<double,-1,1> ;

std::ostream & operator<<( std::ostream & os, Speed v )
 {
  constexpr Speed ratio = KM/H ;
  return (os<<std::round(static_cast<double>(v/ratio))<<" km/h") ;
 }

int main()
 {
  Length l { 28.0_KM } ;
  Time d { 39.0_Mi } ;
  Speed vmax = 50_KM/H ;
  Speed v = l/d ;
  std::cout<<"Max  speed : "<<vmax<<std::endl ;
  std::cout<<"Mean speed : "<<v<<std::endl ;
 }
