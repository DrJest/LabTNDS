#include "Posizione.hpp"
#include "Particella.hpp"
#include "CorpoCeleste.hpp"
#include "Elettrone.hpp"
#include <iostream>

int main()
{
  CorpoCeleste Luna("Luna", 7.3e22, 3476./2);
  CorpoCeleste Terra("Terra", 5.97e24, 6.37e6); 
  CorpoCeleste* Sole = new CorpoCeleste("Sole", 2e30, 7e8);
  
  /** new Posizione(); genera un puntatore a oggetto posizione vuoto, 
   *  mettiamo la luna al centro dell'universo in barba a Copernico
   *  in modo da poter agevolmente ricavare i potenziali esercitati
   *  dalla luna su altri astri
   */
  Luna.Position(new Posizione()); 
  
  /** qui instanzio direttamente un oggetto di tipo posizione,
   *  e lo passo a CorpoCeleste::Position() che può accettare 
   *  anche questo (qui Sole è un puntatore, quindi uso -> e non .)
   */
  Posizione PosizioneSole(1496e5, 0, 0);
  Sole->Position(PosizioneSole);
  
  /** CorpoCeleste::Position() accetta come argomento anche una terna
   * di double 
   */
  Terra.Position(3844e2, 0, 0);
  
  Luna.Print();
  Sole->Print();
  Terra.Print();
  
  double PS = Luna.Campo(Sole->Position());
  double PT = Luna.Campo(Terra.Position());
  std::cout << std::scientific;
  std::cout << "Potenziale della Luna sul Sole: \n" << PS << std::endl;
  std::cout << "Potenziale della Luna sulla terra: \n" << PT << std::endl;
  
  return 0;
}

