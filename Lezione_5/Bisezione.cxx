#include "Bisezione.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
Bisezione::Bisezione(int ms)
{
  steps=0; 
  maxSteps=ms; 
  m_trovato = false; 
  m_prec = 1e-6; 
}
Bisezione::Bisezione(int ms, double p) 
: Bisezione(ms)
{
  m_prec = p;
}
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
    if ( Sign( f->Eval(xMin) ) * Sign( f->Eval(c) ) < 0 )
      xMax = c;
    else
      xMin = c;
    ++steps;
    if( f->Eval(c) == 0 ) {
      m_trovato = true;
      break;
    }
  }
  m_d = fabs(xMin-xMax);
  if(m_d<m_prec) m_trovato = true;
  return c;
}

Bisezione& Bisezione::Precision(double p) {
  m_prec = p; 
  return *this;
}

int Bisezione::Sign(double x){
  if(x<0) return -1;
  else return 1;
}
