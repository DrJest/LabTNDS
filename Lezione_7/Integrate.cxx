#include "Integrate.hpp"
#include "Sin.hpp"
#include <cmath>

Integrate::Integrate () 
{
  _a = 0.;
  _b = M_PI;
  _sign = 1;
  _f = new Sin();
  _t = 0;
}

Integrate::Integrate (double a, double b, const FunzioneBase *f)
{
  _a = (a < b) ? a : b;
  _b = (a > b) ? a : b;
  _sign = (a > b) ? -1 : 1;
  _f = f;
  _t = 0;
}

double Integrate::MidPoint (unsigned int nstep) 
{
  _h = (_a-_b)*_sign/nstep;
  _p = nstep;
  double sp = 0., x;
  for (int i = 1; i < _p; ++i) 
  {
    x = _a + ((double)i+0.5)*_h;	
    sp += _f->Eval(x);
  }
  return (sp * _sign * _h);
}

double Integrate::Simpson (unsigned int nstep) {
  nstep = (nstep%2) ? nstep+1 : nstep;
  _h = (_a-_b)*_sign/nstep;

  double sp = 1./3. * _f->Eval(_a);
  double x, k;
  for (int i = 1; i<nstep; i++) {
  x = _a + (double) i * _h;
  k = (i%2) ?  4./3. : 2./3.;
  sp += k * _f->Eval(x);
  }

  sp += 1./3. * _f->Eval(_b);

  return sp * _h;
}

double Integrate::Trapezi () {
  return (_f->Eval(_a) + _f->Eval(_b)) / 2. * (_b-_a);
}

double Integrate::Trapezi (double precision) {
  if(_t>0.) return _t;
  double sum0 = (_f->Eval(_a) + _f->Eval(_b)) / 2.;
  double I0 = Trapezi();
  int i = 2;
  double x, l=0;
  
  double  sumn = sum0 + _f->Eval((_b-_a)/2.);
  double  I = sumn/(_b-_a)/2;
          
  while (1) {
    if(fabs(I-l)<=precision) break;
    l = I;
    _h = (_b-_a)/pow(2, i);
    x=_a;
    for(int j = 0; j<pow(2,i); j++) {
    x += _h;
    if (j%2) sumn += _f->Eval(x);
    }
    i++;
    I = sumn * _h;
  }
  this->_t = I;
  return I;
}

