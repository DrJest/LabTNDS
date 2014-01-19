#ifndef _Solutore_h_
#define _Solutore_h_

#include "FunzioneBase.hpp"
#include <vector>

class Solutore {
  public:
    virtual double CercaZeri(double,double, const FunzioneBase*)=0;
    virtual double Incertezza() const=0;
    virtual bool Trovato() const=0;
  protected:
    double _a, _b;
    double _prec;
    const FunzioneBase *_f;
};

#endif

