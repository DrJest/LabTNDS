"Bisezione.hpp"

#include <iostream>

Bisezione::Bisezione(int ms) {MaxSteps = ms; steps = 0;}

Bisezione::~Bisezione() {}

double Bisezione::CercaZeri(double xMin, double xMax, const FunzioneBase* f) 
{
  this->_f = f;
  if(! _prec) { std::cerr<<"Precisione non specificata"<<std::endl; return 0; }
  if(steps == MaxSteps) { std::cerr<<"Nessuno zero trovato nei passi specificati" << std::endl; return 0; }
  double c = xMin + (xMax-xMin)/2;

  if(xMax - xMin<_prec || f(c)==0) {
    return c;
  }
  
  if( sign(f(xMin)) * sign(f(xMax)) < 0 ) this->CercaZeri(xMin, c, f);
  this->CercaZeri(c, xMax, f);
  
  steps++;
}

int Bisezione::sign(double x) 
{
  return x>0 ? 1 : -1;
}
