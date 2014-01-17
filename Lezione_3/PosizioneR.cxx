#include "Posizione.hpp"
#include <cmath>

Posizione::Posizione() 
{
  coords[0] = coords[1] = coords[2] = 0;
};

Posizione::Posizione(double x, double y, double z)
{
  coords[0]=sqrt(pow(x,2)+pow(y,2)+pow(z,2)); //R
  coords[1]=acos(z/coords[0]);                //phi
  coords[2]=atan2(y,x);                       //theta
}

double Posizione::x() const
{
  return (coords[0]*cos(coords[2])*sin(coords[1]));
}

double Posizione::y() const
{
  return (coords[0]*sin(coords[2])*sin(coords[1]));;
}

double Posizione::z() const
{
  return (coords[0]*cos(coords[1]));
}

double Posizione::r() const
{
  return coords[0];
}

double Posizione::phi() const
{
  return coords[1];
}

double Posizione::theta() const
{
  return coords[2];
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

