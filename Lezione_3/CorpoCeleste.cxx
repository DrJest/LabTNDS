#include "CorpoCeleste.hpp"
#include <string>
#include <iostream>

CorpoCeleste::CorpoCeleste(std::string name, double massa, double raggio)
  :Particella(massa,0)
  {
    _nome = name;
    _raggio = raggio;
  }

CorpoCeleste& CorpoCeleste::Nome(std::string Name)
{
  _nome = Name;
  return *this;
}

CorpoCeleste& CorpoCeleste::Raggio(double raggio)
{
  _raggio = raggio;
  return *this;
}

double CorpoCeleste::Massa()
{
  return Particella::Massa();
}

CorpoCeleste& CorpoCeleste::Massa(double mass)
{
  _m = mass;
  return *this;
}

CorpoCeleste& CorpoCeleste::Position(Posizione& p)
{
  _pos = &p;
  return *this;
}

CorpoCeleste& CorpoCeleste::Position(Posizione* p)
{
  _pos = p;
  return *this;
}

CorpoCeleste& CorpoCeleste::Position(double x, double y, double z)
{
  _pos = new Posizione(x,y,z);
  return *this;
}

std::string CorpoCeleste::Nome() const
{
  return _nome;
}

double CorpoCeleste::Raggio() const
{
  return _raggio;
}

Posizione& CorpoCeleste::Position() const
{
  return *_pos;
}

double CorpoCeleste::Campo(const Posizione& r)
{
  double R = _pos->distanza(r);
  double G = 6.67384e-11;
  return G*this->Massa()/(R*R);
}

double CorpoCeleste::Campo(const Posizione* r)
{
  double R = _pos->distanza(*r);
  double G = 6.67384e-11;
  return G*this->Massa()/(R*R);
}

void CorpoCeleste::Print() const
{
  std::cout << "Corpo Celeste " << _nome << ": {\n\tMassa: " << _m << "\n\tRaggio: " << _raggio;
  if(_pos)
    std::cout << "\n\tPosizione:\n\t{\n\t\tx:" << _pos->x() << "\nY: " << _pos->y() << "\nZ: " << _pos->z();
   std::cout << "\n}" << std::endl; 
}
