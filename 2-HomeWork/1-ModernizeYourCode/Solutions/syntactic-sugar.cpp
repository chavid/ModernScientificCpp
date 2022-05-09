#include <cassert>
#include <iostream>
#include <list>

template< typename Real >
class Point
 {
  public :
    Point( Real x, Real y )
     : m_x {x}, m_y {y} {}
    friend std::ostream & operator<<( std::ostream & os, Point const & p )
     { return (os<<"("<<p.m_x<<","<<p.m_y<<")") ; }
  private :
    Real m_x, m_y ;
 } ;

enum class BrokenLineKind { Empty, Opened, Closed } ;

template< typename Real >
class BrokenLine
 {
  public :
    void add( Point<Real> p )
     { m_points.push_back(p) ; m_kind = BrokenLineKind::Opened ; }
    void close()
     { assert(m_points.size()>0) ; m_kind = BrokenLineKind::Closed ; }
    friend std::ostream & operator<<( std::ostream & os, BrokenLine const & bl )
     {
      char sep {'('} ;
      for ( auto p : bl.m_points )
       {  os<<sep<<p ; sep = ',' ; }
      if (bl.m_kind==BrokenLineKind::Closed)
       { os<<sep<<bl.m_points.front() ; }
      return (os<<')') ;
     }
  private :
    std::list<Point<Real>> m_points ;
    BrokenLineKind m_kind {BrokenLineKind::Empty} ;
 } ;
 
long double operator ""_km ( long double value )
 { return 1000.*value ; }

long double operator ""_m ( long double value )
 { return 1.*value ; }

long double operator ""_mm ( long double value )
 { return 0.001*value ; }

int main()
 {
  BrokenLine<double> bl ;
  bl.add(Point<double>(1000.0_mm,1.0_m)) ;
  bl.add(Point<double>(0.002_km,3000.0_mm)) ;
  bl.add(Point<double>(4.0_m,0.002_km)) ;
  bl.close() ;
  std::cout<<bl<<std::endl ;
 }