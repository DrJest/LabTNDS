#ifndef _PUNTOMATERIALE_H_

#define _PUNTOMATERIALE_H_

#include "Particella.hpp"
#include "Posizione.hpp"
#include "CampoVettoriale.hpp"

class PuntoMateriale 
  :public Particella, public Posizione 
  {
    public:
      PuntoMateriale();
      PuntoMateriale(const Particella&, const Posizione&);
      PuntoMateriale(double,double,double,double,double);
      ~PuntoMateriale();
      
      CampoVettoriale CampoElettrico(const Posizione&) const;
      CampoVettoriale CampoGravitazionale(const Posizione&) const;
  };


#endif
