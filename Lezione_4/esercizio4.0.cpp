#include "PuntoMateriale.hpp"
#include <iostream>

int main()
{
  /** a è creato a partire da una nuova Posizione,
   *  il vettore associato viene inizializzato come vuoto
   *  e si deve quindi provvedere a riempirlo con il metodo Vector
   */

  PuntoMateriale Elettrone(9.109e-31,-1.602e-19,0,-5e-10,0);
  PuntoMateriale Protone(1.67e-27,1.602e-19,0,5e-10,0);
  
  double x,y,z;
  
  while(!std::cin.eof())
  {
    std::cout << "Inserisci le coordinate del punto: ";
    std::cin >> x >> y >> z;
    Posizione r(x,y,z);
    CampoVettoriale CampoElettrico = Protone.CampoElettrico(r) + Elettrone.CampoElettrico(r);
    CampoVettoriale CampoGravitazionale = Elettrone.CampoGravitazionale(r) + Elettrone.CampoGravitazionale(r);
    std::cout << "Campo Elettrico: " << CampoElettrico.Fx() << std:: endl;
    std::cout << "Campo Gravitazionale: " << CampoGravitazionale.Fx() << std:: endl;
  }
    
}
