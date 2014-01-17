#include "CampoVettoriale.hpp"
#include "Posizione.hpp" 
#include <iostream>
#include <cmath>

CampoVettoriale::CampoVettoriale()
  :Posizione()
  {
    _vector[0] = _vector[1] = _vector[2] = 0;
  }

CampoVettoriale::CampoVettoriale(double x, double y, double z)
  :Posizione(x,y,z)
  {
    _vector[0] = _vector[1] = _vector[2] = 0;
  }
  
CampoVettoriale::CampoVettoriale(double x, double y, double z, double fx, double fy, double fz)
  :Posizione(x,y,z)
  {
    _vector[0] = fx;
    _vector[1] = fy;
    _vector[2] = fz;
  }

CampoVettoriale::CampoVettoriale(const Posizione& p)
  :Posizione(p.x(), p.y(), p.z())
  {
    _vector[0] = _vector[1] = _vector[2] = 0;
  }

CampoVettoriale::CampoVettoriale(const Posizione* p)
  :Posizione(p->x(), p->y(), p->z())
  {
    _vector[0] = _vector[1] = _vector[2] = 0;
  }
  
CampoVettoriale& CampoVettoriale::Vector(double fx, double fy, double fz)
{
  _vector[0] = fx;
  _vector[1] = fy;
  _vector[2] = fz;
  return *this;
}

double CampoVettoriale::Vector(int index) const
{
  if(index<0 || index>2) { std::cerr<<"Invalid Index"<<std::endl; return 0.; }
  return _vector[index];
}

double CampoVettoriale::Vector(char d) const
{
  switch(d)
  {
   case 'x':
      return _vector[0];
      break;
    case 'y':
      return _vector[1];
      break;
    case 'z':
      return _vector[2];
      break;
    default:
      std::cerr << "Invalid Index" << std::endl;
      return 0.;
      break;    
  }
}

double CampoVettoriale::Fx() const
{
  return _vector[0];
}

double CampoVettoriale::Fy() const
{
  return _vector[1];
}

double CampoVettoriale::Fz() const
{
  return _vector[2];
}

double CampoVettoriale::Modulo() const
{
  return sqrt( Fx()*Fx() + Fy()*Fy() + Fz()*Fz() );
}

CampoVettoriale& CampoVettoriale::Somma(const CampoVettoriale& c)
{
  for(int i=0; i<3; ++i)
    _vector[i] += c.Vector(i);
  return *this;
}

double CampoVettoriale::operator() (int index)
{
  if(index<0 || index>2) { std::cerr<<"Invalid Index"<<std::endl; return 0.; }
  return coords[index];
}

double CampoVettoriale::operator[] (int index)
{
  if(index<0 || index>2) { std::cerr<<"Invalid Index"<<std::endl; return 0.; }
  return _vector[index];
}

CampoVettoriale& CampoVettoriale::operator+ (const CampoVettoriale& c)
{
  CampoVettoriale* sum = new CampoVettoriale(*this);
  for(int i=0; i<3; ++i)
    sum->_vector[i] += c.Vector(i);
  return *sum;
}

CampoVettoriale& CampoVettoriale::operator+= (const CampoVettoriale& c)
{
  return Somma(c);
}

bool CampoVettoriale::operator== (const CampoVettoriale& c)
{
  return( _vector[0] == c.Vector(0) &&
          _vector[1] == c.Vector(1) &&
          _vector[2] == c.Vector(2) &&
          coords[0] == c.x() &&
          coords[1] == c.y() &&
          coords[2] == c.z() );
}

bool CampoVettoriale::operator!= (const CampoVettoriale& c)
{
  return !((*this)==c);
}
