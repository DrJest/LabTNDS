#ifndef _Solutore_h_
#define _Solutore_h_

#include "FunzioneBase.hpp"
#include <vector>

class Solutore {
  public:
    virtual double CercaZeri(double Xmin,double Xmax, const FunzioneBase* f)=0;
    void SetPrecisione(double epsilon) { _prec=epsilon; }
    double GetPrecisione() {return _prec;} 
  protected:
    double _a, _b;
    double _prec;
    const FunzioneBase *_f;
};

#endif

