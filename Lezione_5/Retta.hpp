#include "FunzioneBase.hpp"

class Retta : public FunzioneBase {
  public:
    Retta();
    Retta(double, double);
    
    double Eval(double) const;
    double operator()(double) const;
  protected:
    double _a, _b;
};
