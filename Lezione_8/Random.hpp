#ifndef _RANDOM_h_
#define _RANDOM_h_
#include <cmath>
#include <ctime>

class Random
{
  public:
  Random():_a(1664525), _c(1013904223), _m(2147483648) {
  std::time_t t = std::time(NULL);
  _seed = t;
  _n = _seed;
  }

  Random(int seed) {
  _seed = seed;
  _n = _seed;
  }

  void setA(unsigned int a) { 
   _a=a;
  }

  void setC(unsigned int c) { 
   _c=c;
  }

  void setM(unsigned int m) { 
   _m=m;
  }


  int getA() { return _a; }  

  int getC() { return _c; }

  int getM() { return _m; }

  int Seed() { return _seed; }

  double Rand() {
    unsigned int n = (_a*_n+_c) % _m;
    _n = n;
    return (double) n / (double) (_m-1.);
  }

  double Gauss(double m, double sigma) {
    return m + sigma*sqrt(-2.*log(this->Rand()))*cos(2.*M_PI*this->Rand());
  }

  double Exp(double c) {
    return -c*log(1-this->Rand());
  }

  private:
    unsigned int _a;
    unsigned int _c;
    unsigned int _m;
    unsigned int _seed;
    unsigned int _n;
};

#endif
