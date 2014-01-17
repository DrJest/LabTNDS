#include "Posizione.hpp"
#include "Particella.hpp"
#include "CorpoCeleste.hpp"
#include "Elettrone.hpp"
#include <iostream>

int main()
{
  Particella* P = new Particella(1,1);
  Elettrone* E = new Elettrone();
  CorpoCeleste* T = new CorpoCeleste("Terra", 5.97e24, 6.37e6); 
  
  std::cout << P->Massa() << " , " << P->Carica() << std::endl;
  P->Print();
  
  std::cout << E->Massa() << " , " << E->Carica() << std::endl;
  E->Print();
  
  std::cout << T->Massa() << " , " << T->Carica() << std::endl;
  T->Print();
  
  return 0;
}
