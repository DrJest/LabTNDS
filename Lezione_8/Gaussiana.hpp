#ifndef _GAUSSIANA_h_
#define _GAUSSIANA_h_
#include "FunzioneBase.hpp"
#include <cmath>

class Gaussiana : public FunzioneBase{
  public:
    Gaussiana(double m, double s): _s(s), _m(m) {
    }

    double Eval(double x) const {
      return 1/ (_s*sqrt(2*M_PI)) * exp(-pow((x-_m)/(sqrt(2)*_s),2));
    }

    double Max(double i, double f) {
      double max=0;
      for(double c=i;c<f;c+=1E-5) if(Eval(c)>max) max=Eval(c);
      return max;
    }

    double operator()(double x) {
      return Eval(x);
    }

    void M(double m) {_m=m;}
    double M()const{return _m;}
    void S(double s) {_s=s;};
    double S()const {return _s;}
    
  private:
    double _m,_s;
};

#endif
