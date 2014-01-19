#include "Posizione.hpp"
#include <cmath>

Posizione::Posizione() 
{
  coords[0] = coords[1] = coords[2] = 0;
};

Posizione::Posizione(double x, double y, double z)
{
  coords[0]=x;
  coords[1]=y;
  coords[2]=z;
}

double Posizione::x() const
{
  return coords[0];
}

double Posizione::y() const
{
  return coords[1];
}

double Posizione::z() const
{
  return coords[2];
}

double Posizione::r() const
{
  return sqrt(coords[0]*coords[0]+coords[1]*coords[1]+coords[2]*coords[2]);
}


double Posizione::phi() const
{
  return atan2(coords[1], coords[0]);
}

double Posizione::theta() const
{
  return acos(coords[2]/r());
}

double Posizione::rho() const
{
  return sqrt(x()*x()+y()*y());
}

double Posizione::distanza(const Posizione& b) const
{
  return sqrt( pow(x()-b.x(), 2 )
              +pow(y()-b.y(), 2 )
              +pow(z()-b.z(), 2 ) );
}
