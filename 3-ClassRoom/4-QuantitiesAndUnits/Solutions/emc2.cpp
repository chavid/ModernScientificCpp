#include <iostream>
#include <cmath>
#include "Eigen/Dense"

// main class, which supports any mix of duration,
// length and mass.

template< typename UnderlyingType, int s, int m, int kg >
class SiUnit {
  public :
    explicit SiUnit( UnderlyingType value ) : my_value{value} {}
    explicit operator UnderlyingType() { return my_value ; }
  private :
    UnderlyingType my_value ;
} ;

// operators

template< typename UT, int s, int m, int kg >
std::ostream & operator<<( std::ostream & os, SiUnit<UT,s,m,kg> obj )
 { return (os<<static_cast<UT>(obj)) ; }

template< typename UT, int s, int m, int kg >
auto operator+( SiUnit<UT,s,m,kg> lhs, SiUnit<UT,s,m,kg> rhs )
 { return SiUnit<UT,s,m,kg>(static_cast<UT>(lhs)+static_cast<UT>(rhs)) ; }

template< typename UT, int s1, int m1, int kg1, int s2, int m2, int kg2 >
auto operator*( SiUnit<UT,s1,m1,kg1> lhs, SiUnit<UT,s2,m2,kg2> rhs )
 { return SiUnit<UT,s1+s2,m1+m2,kg1+kg2>(static_cast<UT>(lhs)*static_cast<UT>(rhs)) ; }

template< typename UT, int s, int m, int kg >
auto operator*( UT lhs, SiUnit<UT,s,m,kg> rhs )
 { return SiUnit<UT,s,m,kg>(lhs*static_cast<UT>(rhs)) ; }

template< typename UT, int s1, int m1, int kg1, int s2, int m2, int kg2 >
auto operator/( SiUnit<UT,s1,m1,kg1> lhs, SiUnit<UT,s2,m2,kg2> rhs )
 { return SiUnit<UT,s1-s2,m1-m2,kg1-kg2>(static_cast<UT>(lhs)/static_cast<UT>(rhs)) ; }

// base units and constants

using Time = SiUnit<double,1,0,0> ;
Time S { 1. } ;

using Length = SiUnit<double,0,1,0> ;
Length M { 1. } ;

using Mass = SiUnit<double,0,0,1> ;
Mass KG { 1. } ;

// combined units

using Speed = SiUnit<double,-1,1,0> ;
using Momentum = SiUnit<double,-1,1,1> ;
using Energy = SiUnit<double,-2,2,1> ;

// math functions

template< int pn, int pd, typename UT, int s, int m, int kg >
auto power( SiUnit<UT,s,m,kg> value )
 { return SiUnit<UT,s*pn/pd,m*pn/pd,kg*pn/pd>(pow(static_cast<UT>(value),static_cast<UT>(pn)/pd)) ; }
 
template< typename UT, int s, int m, int kg >
auto square( SiUnit<UT,s,m,kg> value )
 { return power<2,1>(value) ; }
 
template< typename UT, int s, int m, int kg >
auto sqrt( SiUnit<UT,s,m,kg> value )
 { return power<1,2>(value) ; }

// 3d

template< typename UT >
using Eigen3d = Eigen::Matrix<UT,3,1> ;

using Length3d = SiUnit<Eigen3d<double>,0,1,0> ;
using Speed3d = SiUnit<Eigen3d<double>,-1,1,0> ;
using Momentum3d = SiUnit<Eigen3d<double>,-1,1,1> ;

template< typename UT, int s, int m, int kg >
auto operator*( Eigen3d<UT> lhs, SiUnit<UT,s,m,kg> rhs )
 { return SiUnit<Eigen3d<UT>,s,m,kg>(lhs*static_cast<UT>(rhs)) ; }

template< typename UT, int s1, int m1, int kg1, int s2, int m2, int kg2 >
auto operator*( SiUnit<UT,s1,m1,kg1> lhs, SiUnit<Eigen3d<UT>,s2,m2,kg2> rhs )
 { return SiUnit<Eigen3d<UT>,s1+s2,m1+m2,kg1+kg2>(static_cast<UT>(lhs)*static_cast<Eigen3d<UT>>(rhs)) ; }

template< typename UT, int s1, int m1, int kg1, int s2, int m2, int kg2 >
auto operator/( SiUnit<Eigen3d<UT>,s1,m1,kg1> rhs, SiUnit<UT,s2,m2,kg2> lhs )
 { return SiUnit<Eigen3d<UT>,s1-s2,m1-m2,kg1-kg2>(static_cast<Eigen3d<UT>>(rhs)/static_cast<UT>(lhs)) ; }

template< typename UT, int s, int m, int kg >
auto norm( SiUnit<Eigen3d<UT>,s,m,kg> value )
 { return SiUnit<UT,s,m,kg>(static_cast<Eigen3d<UT>>(value).norm()) ; }


// main

int main() {
    
  Mass m { 9.109e-31*KG } ;
  Speed c { 299792458.*M/S } ;
  Speed3d speed { Eigen3d<double> { 0.75*static_cast<double>(c), 0., 0. }*M/S } ; 
  Momentum3d p { m*speed } ;

  Energy e = sqrt(square(m)*power<4,1>(c)+square(norm(p))*square(c)) ;  
  std::cout << e << std::endl ;
  
}