#include "Posizione.hpp"
#include <iostream>
#include <cstdlib>

int main (int argc,char** argv){

  if (argc!=4) {
    std::cerr<<"usage:"<<argv[0]<<"-x- -y- -z-"<<std::endl;
    return 1;
  }

  double x=atof(argv[1]);
  double y=atof(argv[2]);
  double z=atof(argv[3]);
  
  Posizione P(x,y,z);
  std::cout << "coordinate CARTESIANE  \nx: "
       << P.x() << "\ny: " << P.y() << "\nz: " << P.z() << std::endl;
  std::cout << "coordinate CILINDRICHE: \nrho: "
       << P.rho() << "\nphi: " << P.phi() << "\nz: " << P.z() << std::endl;
  std::cout << "coordinate SFERICHE:\nr: "
       << P.r() <<"\nphi: " << P.phi() << "\ntheta:" << P.theta() << std::endl;
  return 0;

}

