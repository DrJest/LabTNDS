#include <cmath>
#include "Buca.hpp"

Buca::Buca(int x) {}
Buca::~Buca() {}
double Buca::Eval(double _x)const {
  return sin(_x)-_x*cos(_x);
}
