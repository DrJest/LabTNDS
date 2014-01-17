#include "Retta.hpp"

Retta::Retta() {}

Retta::Retta(double a, double b) {
  _a = a;
  _b = b;
}

double Retta::Eval(double x) const {
  return _a*x + _b;
}

double Retta::operator()(double x) const {
  return this->Eval(x);
}
