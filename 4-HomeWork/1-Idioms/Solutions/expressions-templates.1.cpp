#include <iostream>
#include <vector>

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

int main()
 {
  const int size = 5 ;
  std::vector<int> array1 = { 1, 2, 3, 4, 5 } ;
  std::vector<double> array2 = { .1, .2, .3, .4, .5 } ;
  std::vector<double> array3 = { .01, .02, .03, .04, .05 } ;
  
  using int_itr = typename std::vector<int>::iterator ;
  using double_itr = typename std::vector<double>::iterator ;

  ItrNodeAdd<int_itr, double_itr> node1{std::begin(array1),std::begin(array2)} ;
  ItrNodeSub<decltype(node1), double_itr> node2{node1,std::begin(array3)} ;

  for ( int i = 0 ; i<size ; ++i )
   { std::cout<<(*node2)<<std::endl ; ++node2 ; }
  
 }