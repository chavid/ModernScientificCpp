#include <iostream>
#include <list>

template< typename Real >
class Point
 {
  public :
    Point( Real x, Real y )
     : m_x {x}, m_y {y} {}
    friend std::ostream & operator<<( std::ostream & os, Point const & p )
     { return (os<<"{"<<p.m_x<<","<<p.m_y<<"}") ; }
  private :
    Real m_x, m_y ;
 } ;

enum class BrokenLineKind { Empty, Opened, Closed } ;

template< typename Real >
class BrokenLine
 {
  public :
    BrokenLine( const std::initializer_list<Point<Real>> points, bool closed )
     : m_points {points.begin(),points.end()}
     {
      if (!points.size()) return ;
      if (closed)
       { m_kind = BrokenLineKind::Closed ; }
      else
       { m_kind = BrokenLineKind::Opened ; }
     }
    friend std::ostream & operator<<( std::ostream & os, BrokenLine const & bl )
     {
      char sep { '{' } ;
      for ( auto p : bl.m_points )
       {  os<<sep<<p ; sep = ',' ; }
      if (bl.m_kind==BrokenLineKind::Closed)
       { os<<sep<<bl.m_points.front() ; }
      return (os<<'}') ;
     }
  private :
    std::list<Point<Real>> m_points ;
    BrokenLineKind m_kind = BrokenLineKind::Empty ;
 } ;
 
int main()
 {
  BrokenLine<double> bl { { {1,1}, {2,3}, {4,2} }, true } ;
  std::cout<<bl<<std::endl ;
 }