#include <iostream>
#include <cassert>   // for assert
#include <array>     // for std::array
#include <numeric>   // for accumulate
#include <random>

int main( int argc, char * argv[] )
 {
  assert(argc==2) ;
  std::string mode(argv[1]) ;
    
  std::default_random_engine engine ;
  if (mode=="non-deterministic")
    engine.seed(std::random_device{}()) ;
  else if (mode!="deterministic")
    throw "unknown mode" ;

  std::uniform_real_distribution<double> distrib(-0.5,0.5) ;
  constexpr unsigned SIZE = 1024 ;
  std::array<double,SIZE> coll ;
  for ( double & elem : coll )
   { elem = distrib(engine) ; }
    
  double mean = std::accumulate(coll.begin(),coll.end(),0.)/SIZE ;
  std::cout<<mean<<std::endl ;
 }
