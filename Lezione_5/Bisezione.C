#include "Bisezione.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
Bisezione::Bisezione(int ms){ steps=0; maxSteps=ms; m_trovato = false; m_prec = 0; }
Bisezione::~Bisezione(){}

double Bisezione::CercaZeri(double xMin,double xMax, const FunzioneBase* f)
{ 
  m_f = f;
  double c=0;
  while(xMax-xMin>m_prec)
  {
    c = xMin + 0.5 * (xMax-xMin);
    if (  steps == maxSteps ) {
      std::cerr << "Zero trovato nel numero massimo di passi: " << c << std::endl;
      break;
    }
    if ( sign( f->Eval(xMin) ) * sign( f->Eval(c) ) < 0 )
      xMax = c;
    else
      xMin = c;
    std::cout << ++steps << std::endl;
    if( f->Eval(c) == 0 ) {
      m_trovato = true;
      break;
    }
  }
  if(xMin - xMax<m_prec) m_trovato = true;
  return c;
}
void Bisezione::setPrecision(double p) {
  m_prec = p; 
}
int Bisezione::sign(double x){
  if(x<0) return -1;
  else return 1;
}
