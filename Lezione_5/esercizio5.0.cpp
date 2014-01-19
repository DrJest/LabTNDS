#include "Particella.hpp"
#include "Elettrone.hpp"
#include "CorpoCeleste.hpp"
int main() 
{
  Particella* a = new Particella(1., 2.);
  Particella* b = new Elettrone();
  Particella* c = new CorpoCeleste("Terra",5.97e24,6.37e6);
  
  a->Print();
  b->Print();
  c->Print();
  
  return 0;
}
