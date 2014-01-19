#ifndef _CORPOCELESTE_H_

#define _CORPOCELESTE_H_

#include "Posizione.hpp"
#include "Particella.hpp"
#include <string>

class CorpoCeleste
  :public Particella
  {
    public:
      CorpoCeleste(std::string, double, double);
      
      CorpoCeleste& Nome(std::string);
      std::string Nome() const;
      double Massa();
      CorpoCeleste& Massa(double);
      CorpoCeleste& Raggio(double);
      double Raggio() const;
      CorpoCeleste& Position(Posizione&);
      CorpoCeleste& Position(Posizione*);
      CorpoCeleste& Position(double,double,double);
      Posizione& Position() const;
      double Campo(const Posizione&);
      double Campo(const Posizione*);
      double Campo(CorpoCeleste&);
      
      virtual void Print() const;
    protected:
      std::string _nome;
      double _raggio;
      Posizione* _pos;
  };

#endif
