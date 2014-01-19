#ifndef _INTEGRATE_h_
#define _INTEGRATE_h_
#include "FunzioneBase.hpp"

class Integrate {
public:
Integrate();
Integrate(double a, double b, const FunzioneBase *f);
double MidPoint(unsigned int nstep);
double Simpson(unsigned int nstep);
double Trapezi();
double Trapezi(double nstep);

private:
double _a, _b, _value, _h;
int _p, _sign;
const FunzioneBase* _f;
};

#endif
