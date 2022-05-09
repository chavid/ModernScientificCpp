#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cmath>

int main()
 {
  int const DIM {10} ;
  int const DEGREE {5} ;
  
  // generate random input
  std::vector<double> input(DIM) ;
  std::for_each(input.begin(),input.end(),[]( double & value )
   { value = ((2.*std::rand())/RAND_MAX-1.) ; }) ;

  // compute output
  std::vector<double> output(DIM) ;
  std::transform(input.begin(),input.end(),output.begin(),[DEGREE]( double x )
   { return std::pow(x,DEGREE) ; }) ;
  
  // print sum
  std::cout<<std::accumulate(output.begin(),output.end(),0.)<<std::endl ;
}