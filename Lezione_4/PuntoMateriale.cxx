#include "PuntoMateriale.hpp"
#include "Particella.hpp"
#include "Posizione.hpp"
#include "CampoVettoriale.hpp"

#include <cmath>
#include <iostream>

#define K (1/(4*M_PI*8.85e-12))
#define G 6.67384e-11
PuntoMateriale::PuntoMateriale()
  :Particella(), Posizione()
  {
  }
  
  /** il COPY CONSTRUCTOR DI Particella e Posizione fa tutto il lavoro */
PuntoMateriale::PuntoMateriale(const Particella& m, const Posizione& p)
  :Particella(m), Posizione(p)
  {
  }

PuntoMateriale::PuntoMateriale(double m, double c, double x, double y, double z)
  :Particella(m,c), Posizione(x,y,z)
  {
  }

PuntoMateriale::~PuntoMateriale() {}
  
CampoVettoriale PuntoMateriale::CampoElettrico(const Posizione& r) const
{
  CampoVettoriale* v = new CampoVettoriale(r); 
  
  double fx,fy,fz;
  double d = pow(this->distanza(r), 3);
  fx = K*_c/d*(x()-r.x());
  fy = K*_c/d*(y()-r.y());
  fz = K*_c/d*(z()-r.z());
  v->Vector(fx,fy,fz);
  return *v;
}

CampoVettoriale PuntoMateriale::CampoGravitazionale(const Posizione& r) const
{
  CampoVettoriale* v = new CampoVettoriale(r); 
  double fx,fy,fz, d = pow(this->distanza(r), 3);
  fx = G*_m/d*(x()-r.x());
  fy = G*_m/d*(y()-r.y());
  fz = G*_m/d*(z()-r.z());
  v->Vector(fx,fy,fz);
  return *v;
}
