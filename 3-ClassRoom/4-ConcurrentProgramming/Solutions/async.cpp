#include <complex>
#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>
#include <thread>
#include <future>

using Real = double ;
using Complex = std::complex<Real> ;
using Complexes = std::vector<Complex> ;

// random unitary complexes
void generate( Complexes & cs )
 {
  srand(1) ;
  for ( auto & c : cs )
   { 
    Real angle {rand()/(Real(RAND_MAX)+1)*2.0*M_PI} ;
    c = Complex{std::cos(angle),std::sin(angle)} ;
   }
 }

// compute a slice of xs^degree and return it
Complexes complexes_pow
 ( std::size_t num_slice, std::size_t nb_slices,
   Complexes const & xs, int degree )
 {
  assert((xs.size()%nb_slices)==0) ;  
  auto slice_size {xs.size()/nb_slices} ;
  auto min {num_slice*slice_size} ;
  Complexes ys(slice_size) ;
  for ( decltype(slice_size) i {0} ; i<slice_size ; ++i )
   {
    ys[i] = Complex{1.,0.} ;
    for ( int d=0 ; d<degree ; ++d )
     { ys[i] *= xs[i+min] ; }
   }
  return ys ;
 }

// display the angle of the global product
void postprocess( Complexes const & cs )
 {
  Complex prod {1.,0.} ;
  for( auto c : cs ) { prod *= c ; }
  double angle {atan2(prod.imag(),prod.real())} ;
  std::cout<<"result = "<<static_cast<int>(angle/2./M_PI*360.)<<"\n" ;
 }

// main program
int main ( int argc, char * argv[] )
 {
  assert(argc==4) ;
  std::size_t nbtasks {std::stoul(argv[1])} ;
  std::size_t dim {std::stoul(argv[2])} ;
  int degree {std::stoi(argv[3])} ;

  // prepare input
  Complexes input(dim) ;
  generate(input) ;
   
  // compute
  std::vector<std::future<Complexes>> results ;
  for ( std::size_t numtask {0} ; numtask<nbtasks ; ++numtask )
   { results.push_back(std::async(complexes_pow,numtask,nbtasks,input,degree)) ; }
  Complexes output ;
  for ( auto & futur_result_slice : results )
   {
    Complexes result_slice = futur_result_slice.get() ;
    output.insert(output.end(),result_slice.begin(),result_slice.end()) ;
   }
  
  // post-process
  postprocess(output) ;
 }