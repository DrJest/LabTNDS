#ifndef _ELETTRONE_H_

#define _ELETTRONE_H_

#include "Particella.hpp"

class Elettrone
  : public Particella
  {
    public:
      Elettrone();
      ~Elettrone();
      
      void Print() const;
  };

#endif
