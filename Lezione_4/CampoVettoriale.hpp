#ifndef _CAMPOVETTORIALE_H_

#define _CAMPOVETTORIALE_H_

#include "Posizione.hpp"

class CampoVettoriale
  :public Posizione
  {
    public:
      CampoVettoriale();
      CampoVettoriale(double,double,double);
      CampoVettoriale(double,double,double,double,double,double);
      CampoVettoriale(const Posizione&);
      CampoVettoriale(const Posizione*);
      ~CampoVettoriale() {};
      
      CampoVettoriale& Vector(double,double,double);
      
      double Vector(int) const;
      double Vector(char) const;
      double Fx() const;
      double Fy() const;
      double Fz() const;
      
      double Modulo() const;
      CampoVettoriale& Somma(const CampoVettoriale&);
      
      /**
       *  definisco degli operatori per accedere più velocemente
       *  ai membri della classe, definisco inoltre l'operatore
       *  di uguaglianza == e diseguaglianza != per il confronto 
       *  di 2 oggetti 
       *  TUTTI gli operatori sono dichiarati virtuali, poiché eventuali
       *  classi derivate che abbiano altri membri devono poterli
       *  sovrascrivere
       */
      virtual double operator()(int); 
      virtual double operator[](int);
      virtual CampoVettoriale& operator+(const CampoVettoriale&);
      virtual CampoVettoriale& operator+=(const CampoVettoriale&);
      virtual bool operator==(const CampoVettoriale&);
      virtual bool operator!=(const CampoVettoriale&);
    
    protected:
      double _vector[3];
  };

#endif
