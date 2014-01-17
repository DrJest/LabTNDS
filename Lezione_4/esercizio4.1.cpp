#include "PuntoMateriale.hpp"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <cmath>
#define E 1.602e-19
#define R0 1e-10

int main(int argc, char** argv)
{
  if(argc!=2 && argc!=4)
  {
    std::cerr << "Usage: " << argv[0] << " <numero di punti> [, <distanza min>][, <distanza max>]" << std::endl;
    return 1;
  }
  int num = atoi(argv[1]);
  if(num%2) ++num;
  double min, max;
  if(argc==4) 
  {
    min = atof(argv[2]);
    max = atof(argv[3]);
  }
  else
  {
    min = R0*10;
    max = R0*100000;
  }
  PuntoMateriale** pts = new PuntoMateriale*[num];
  double carica, x, y;
  for (int i=0; i<num; ++i)
  {
    /** La massa non ci interessa */
    carica = pow(-1,i)*E;
    x = R0 * cos(2*M_PI*i/num);
    y = R0 * sin(2*M_PI*i/num);
    PuntoMateriale* tmp = new PuntoMateriale(0,carica,x,y,0);
    pts[i] = tmp;
    /**
    PuntoMateriale tmp(0, carica,x,y,0);
    pts[i] = &tmp; // type_of(&tmp) == PuntoMateriale*
    */
  }
  int j = 0;
  double alpha = 0, laste, lastr;
  std::cout << "Alpha Teorico: " << -2-num/2 << std::endl;
  for(double r=min; r<max; r+=(max-min)/100)
  {
    CampoVettoriale* tmp = new CampoVettoriale(r,0,0);
    Posizione* R = new Posizione(r, 0, 0);
    for(int i = 0; i<num; ++i)
      *tmp += pts[i]->CampoElettrico(*R);
    
    if(j>0) alpha = log(tmp->Modulo()/laste)/log(r/lastr);
    laste=tmp->Modulo(); lastr = r;
    
    std::cout <<"|"<< std::setw(3) << ++j << "|" << std::setw(12) << tmp->Modulo() 
              << std::setw(12) << "| Alpha: " << std::setw(12) << alpha << "|" << std::endl;
  }
}
