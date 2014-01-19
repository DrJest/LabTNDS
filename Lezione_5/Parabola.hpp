#ifndef _Parabola_h_
#define _Parabola_h_
#include "FunzioneBase.hpp"
class Parabola: public FunzioneBase {
public:
  Parabola();
  Parabola(double a, double b, double c);
  ~Parabola();
  
  Parabola& A(double);
  Parabola& B(double);
  Parabola& C(double);
  
  double A() const {return _a;}
  double B() const {return _b;}
  double C() const {return _c;}
  
  double Eval(double) const;
  double operator() (double) const;
  
private:
  double _a,_b,_c;
};
#endif
