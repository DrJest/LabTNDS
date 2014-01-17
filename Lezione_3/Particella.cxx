#include "Particella.hpp"
#include <iostream>

Particella::Particella()
{
  _m=_c=0.;
}

Particella::Particella(double m, double c)
{
  _m = m;
  _c = c;
}

Particella::~Particella()
{
}

Particella& Particella::Massa(double m)
{
  _m = m;
  return *this;
}

Particella& Particella::Carica(double c)
{
  _c = c;
  return *this;
}

double Particella::Massa() const
{
  return _m;
}

double Particella::Carica() const
{
  return _c;
}

void Particella::Print() const
{
  std::cout << "Particella{\nMassa: " << _m << "\nCarica: " << _c << "\n}" << std::endl;
}
