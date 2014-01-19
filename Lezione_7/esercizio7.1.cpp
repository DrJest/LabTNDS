#include "Integrate.hpp"
#include "Sin.hpp"
#include <cmath>
#include <stdlib.h>
#include <iostream>

int main(int argc, char** argv) 
{
  if(argc!=2) return -1;
  int nstep = atoi(argv[1]);
  FunzioneBase* Seno = new Sin();
  Integrate I(0., M_PI, Seno);
  
  std::cout << nstep << std::endl;
  double intg;
  
  intg = I.MidPoint(nstep);
  std::cout << "Integral of sinus between 0 and PI (MidPoint): " << intg << std::endl;

  intg = I.Simpson(nstep);
  std::cout << "Integral of sinus between 0 and PI (Simpson): " << intg << std::endl;
}