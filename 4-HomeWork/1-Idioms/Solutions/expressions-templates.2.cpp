#include <iostream>

// Vector

struct Vector
 {
  double data[3] ;
  
  template <typename ItrNode>
  void operator=( ItrNode && node )
   {
    data[0] = *node ; ++node ;
    data[1] = *node ; ++node ;
    data[2] = *node ;
   }
 } ;

std::ostream & operator<<( std::ostream & os, Vector const & v )
 { return (os<<v.data[0]<<"|"<<v.data[1]<<"|"<<v.data[2]) ; }

// Nodes

template <typename Itr1, typename Itr2>
struct ItrNodeBase
 {
  Itr1 itr1 ; Itr2 itr2 ;
  ItrNodeBase( Itr1 i1, Itr2 i2 ) : itr1(i1), itr2(i2) {}
  void operator ++() { ++itr1 ; ++itr2 ; }
 } ;
  
template <typename Itr1, typename Itr2>
struct ItrNodeAdd : public ItrNodeBase<Itr1, Itr2>
 {
  using ItrNodeBase<Itr1, Itr2>::ItrNodeBase ;
  double operator *() const
   { return (*(this->itr1))+(*(this->itr2)) ; }
 } ;

template <typename Itr1, typename Itr2>
struct ItrNodeSub : public ItrNodeBase<Itr1, Itr2>
 {
  using ItrNodeBase<Itr1, Itr2>::ItrNodeBase ;
  double operator *() const
   { return (*(this->itr1))-(*(this->itr2)) ; }
 } ;

// Operators

template <typename ItrNode1, typename ItrNode2>
auto operator +( const ItrNode1 & n1, const ItrNode2 & n2 )
 { return ItrNodeAdd<ItrNode1,ItrNode2>{n1,n2} ; }

template <typename ItrNode>
auto operator +( Vector const & v, ItrNode const & n )
 { return ItrNodeAdd<double const *,ItrNode>{v.data,n} ; }

template <typename ItrNode>
auto operator +( ItrNode const & n, Vector const & v )
 { return ItrNodeAdd<ItrNode,double const *>{n,v.data} ; } 

auto operator +( Vector const & v1, Vector const & v2 )
 { return ItrNodeAdd<double const *,double const *>{v1.data,v2.data} ; }

template <typename ItrNode1, typename ItrNode2>
auto operator -( const ItrNode1 & n1, const ItrNode2 & n2 )
 { return ItrNodeSub<ItrNode1,ItrNode2>{n1,n2} ; }

template <typename ItrNode>
auto operator -( Vector const & v, ItrNode const & n )
 { return ItrNodeSub<double const *,ItrNode>{v.data,n} ; }

template <typename ItrNode>
auto operator -( ItrNode const & n, Vector const & v )
 { return ItrNodeSub<ItrNode,double const *>{n,v.data} ; } 

auto operator -( Vector const & v1, Vector const & v2 )
 { return ItrNodeSub<double const *,double const *>{v1.data,v2.data} ; }

// Main

int main()
 {
  Vector v1{1,2,3}, v2{0.1,0.2,0.3}, v3{0.01,0.02,0.03}, v4{0,0,0} ;
  v4 = v1+(v2-v3) ;
  std::cout<<v4<<std::endl ;
  return 0 ;
 }