#ifndef _SOLUTORE_H_
#define _SOLUTORE_H_

#include "Solutore.hpp"
#include <vector>
class Bisezione:public Solutore{
  public:
    Bisezione(int);
    Bisezione(int, double);
    ~Bisezione();
    double CercaZeri(double,double, const FunzioneBase*);
    Bisezione& Precision(double);
    double Incertezza() const {return m_d;}
    bool Trovato() const {return m_trovato;}
    int Steps() const {return steps;}
  private:
    int Sign(double);
    int maxSteps;
    int steps;
    const FunzioneBase* m_f;
    double m_prec;
    bool m_trovato;
    double m_d;
};

#endif
