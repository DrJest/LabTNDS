#ifndef _POSIZIONE_H_

#define _POSIZIONE_H_

class Posizione
{
  public:
    Posizione();
    Posizione(double, double, double);
    
    double x() const;
    double y() const;
    double z() const;
    double r() const;
    double rho() const;
    double phi() const;
    double theta() const;

    double distanza(const Posizione&) const;
    
  protected:
    double coords[3];
};

#endif
