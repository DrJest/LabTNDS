#include"Parabola.hpp"
#include <cmath>
Parabola::Parabola(){}

Parabola::Parabola(double a, double b, double c){
  _a=a;
  _b=b;
  _c=c;
}
Parabola::~Parabola(){}

FunzioneBase* Parabola::A(double a)
{
  _a=a;
  return this;
}
  

FunzioneBase* Parabola::B(double b)
{
  _b=b;
  return this;
}
  

FunzioneBase* Parabola::C(double c)
{
  _c=c;
  return this;
}
  
double Parabola::Eval(double x)const {
  return _a*pow(x,2)+_b*x+_c;
}

double Parabola::operator() (double x)const {
  return this->Eval(x);
}
