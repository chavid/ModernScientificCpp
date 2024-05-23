#include <complex>
#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>
#include <thread>

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

// compute a slice of xs^degree and store it into ys
// xs.size() must be a multiple of nb_slices
void complexes_pow
 ( std::size_t num_slice, std::size_t nb_slices,
   Complexes const & xs, int degree, Complexes & ys )
 {
  assert((xs.size()%nb_slices)==0) ;  
  auto slice_size {xs.size()/nb_slices} ;
  auto min {num_slice*slice_size} ;
  auto max {(num_slice+1)*slice_size} ;
     
  for ( auto i {min} ; i<max ; ++i )
   {
    ys[i] = Complex{1.,0.} ;
    for ( int d=0 ; d<degree ; ++d )
     { ys[i] *= xs[i] ; }
   }
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
  Complexes output(dim) ;
  std::size_t numtask ;
  std::vector<std::thread> workers ;
  for ( numtask = 0 ; numtask<nbtasks ; ++numtask )
   { workers.emplace_back(complexes_pow,numtask,nbtasks,std::ref(input),degree,std::ref(output)) ; }
  for ( auto & worker : workers )
   { worker.join() ; }
  
  // post-process
  postprocess(output) ;
 }
