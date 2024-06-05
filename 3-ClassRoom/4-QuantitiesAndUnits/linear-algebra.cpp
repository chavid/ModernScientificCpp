#include <iostream>

#include "phys/units/io.hpp"
#include "phys/units/quantity.hpp"
#include "Eigen/Dense"

using namespace phys::units ;
using namespace phys::units::io;
using namespace phys::units::literals ;

using real = double ;

using momentum_d = dimensions< 1, 1, -1 > ;
 
using Speed = quantity<speed_d,real> ;
using Momentum = quantity<momentum_d,real> ;

using Speed3d = quantity<speed_d,Eigen::Matrix<real,3,1>> ;
using Momentum3d = quantity<momentum_d,Eigen::Matrix<real,3,1>> ;

int main()
 {
  constexpr quantity<mass_d,real> m = 0.0009109_yg ;
  constexpr quantity<speed_d,real> c = 299792458_m/second ;
    
  real r = 0.75/sqrt(3.) ;
  Speed3d speed(Eigen::Matrix<real,3,1>(r,r,r)*c) ;

  Momentum3d momentum = m*speed ;
  Momentum p = momentum.magnitude().norm()*kilogram*meter/second ;
  auto e = sqrt(square(m)*nth_power<4>(c)+square(p)*square(c)) ;  
  std::cout << speed << std::endl ;
 }

