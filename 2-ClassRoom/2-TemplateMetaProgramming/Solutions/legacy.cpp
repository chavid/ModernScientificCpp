#include <iostream>
#include <vector>
#include <list>

template< typename IterT, typename DistT >
void jump( IterT & iter, DistT d )
 {
  using IterCat = typename std::iterator_traits<IterT>::iterator_category ;
  if constexpr (std::is_same_v<IterCat,std::random_access_iterator_tag>)
   {
    iter += d ;
    std::cout<<"(direct jump)"<<std::endl ;
   }
  else
   {
    if (d >= 0) { while (d--) ++iter ; }
    else { while (d++) --iter ; }
    std::cout<<"(incremental jump)"<<std::endl ;
   }
 }

int main()
 {
  std::list<int> l { 0, 1, 2, 3, 4 } ;
  auto litr {l.begin()} ;
  jump(litr,2) ;
  std::cout<<(*litr)<<std::endl ;
    
  std::vector<int> v { 0, 1, 2, 3, 4 } ;
  auto vitr {v.begin()} ;
  jump(vitr,3) ;  
  std::cout<<(*vitr)<<std::endl ;
 }
 