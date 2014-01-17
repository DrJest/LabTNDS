#ifndef _SOLUTORE_H_
#define _SOLUTORE_H_

#include "Solutore.hpp"
#include <vector>
class Bisezione:public Solutore{
  public:
    Bisezione(int);
    ~Bisezione();
    double CercaZeri(double,double, const FunzioneBase* _f);
    int sign(double);
    void setPrecision(double);
    bool m_trovato;
  private:
    int maxSteps;
    int steps;
    const FunzioneBase* m_f;
    double m_prec;
};

#endif
