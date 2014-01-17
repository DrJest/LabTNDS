#ifndef _PARTICELLA_H_

#define _PARTICELLA_H_

class Particella 
{
  public:
    Particella();
    Particella(double, double);
    ~Particella();
    
    double Carica() const;
    double Massa() const;
    
    Particella& Massa(double);
    Particella& Carica(double);
    
    virtual void Print() const;
    
  protected:
    double _c, _m;
};

#endif
