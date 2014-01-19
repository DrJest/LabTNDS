#include "FunzioneBase.hpp"
#include <cmath>

class Sin:public FunzioneBase{
  public:
    Sin() {};
    ~Sin() {};
    double Eval(double x) const {return sin(x);};
    double operator()(double x) {return sin(x);};
};
