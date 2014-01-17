#ifndef _Parabola_h_
#define _Parabola_h_
#include "FunzioneBase.hpp"
class Parabola: public FunzioneBase {
public:
  Parabola();
  Parabola(double a, double b, double c);
  ~Parabola();
  
  FunzioneBase* A(double);
  FunzioneBase* B(double);
  FunzioneBase* C(double);
  
  double Eval(double) const;
  double operator () (double) const;
  
  double A() const{return _a;}//metodo per accedervi
  double B() const {return _b;}
  double C() const {return _c;}
  
private:
  double _a,_b,_c;
};
#endif
