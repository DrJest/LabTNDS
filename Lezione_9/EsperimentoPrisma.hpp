#include <cmath>
#include "Random.hpp"
#include <vector>
#include <iostream>
#include "Stats.hpp"

class EsperimentoPrisma {
public: 
EsperimentoPrisma() : _gen(), _l1(579.1e-9), _l2(404.7e-9), _a(M_PI/3.), _st(0.3e-3), _A_in(2.7), _B_in(60000e-18) 
{
  _n1_in = sqrt(_A_in+_B_in/pow(_l1, 2));
  _n2_in = sqrt(_A_in+_B_in/pow(_l2, 2));

  _t0_in = M_PI/2.;

  double dm = 2. * asin(_n1_in*sin(0.5*_a))-_a;
  _t1_in = _t0_in+dm;

  dm = 2. * asin(_n2_in*sin(0.5*_a))-_a;
  _t2_in = _t0_in+dm;
}

void Esegui() {
  double a, dm;
  a = _gen.Gauss(_a, _st);
  _t0_mc = _gen.Gauss(_t0_in, _st);
  _t1_mc = _gen.Gauss(_t1_in, _st);
  _t2_mc = _gen.Gauss(_t2_in, _st);
  dm = _t1_mc - _t0_mc;
  _n1_mc = sin((dm+a)/2.) / sin(a/2.);
  dm = _t2_mc - _t0_mc;
  _n2_mc = sin((dm+a)/2.) / sin(a/2.);
  return;
}

void Itera(int N) {
  while(N) {
    Esegui();
    n1s.push_back(_n1_mc);
    n2s.push_back(_n2_mc);
    t0s.push_back(_t0_mc);
    t1s.push_back(_t1_mc);
    t2s.push_back(_t2_mc);
    N--;
  }
}

void Analizza() {
  return;
}

void setA(double a) { _A_in = a; }
void setB(double a) { _B_in = a; }
void setL1(double a) { _l1 = a; }
void setL2(double a) { _l2 = a; }
void setAlpha(double a) { _a = a; }

double getA() { return _A_in; }
double getB() { return _B_in; }
double getN1() { return _n1_in; }
double getN2() { return _n2_in; }
double getT0() { return _t0_in; }
double getT1() { return _t1_in; }
double getT2() { return _t2_in; }
double getL1() { return _l1; }
double getL2() { return _l2; }
double getSt() { return _st; }

double getN1MC() { return _n1_mc; }
double getN2MC() { return _n2_mc; }
double getT0MC() { return _t0_mc; }
double getT1MC() { return _t1_mc; }
double getT2MC() { return _t2_mc; }

std::vector <double> n1s;
std::vector <double> n2s;
std::vector <double> t0s;
std::vector <double> t1s;
std::vector <double> t2s;

  private:
    Random _gen;
    double _l1, _l2, _a, _st;
    double _A_in, _A_mc;
    double _B_in, _B_mc;
    double _n1_in, _n1_mc;
    double _n2_in, _n2_mc;
    double _t0_in, _t0_mc;
    double _t1_in, _t1_mc;
    double _t2_in, _t2_mc;
};


