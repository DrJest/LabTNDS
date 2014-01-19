#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include "Parabola.hpp"
#include "Retta.hpp"
#include "Bisezione.hpp"

int main(int argc,char** argv){
  if (argc!=4)
  {
    std::cerr << "Usage: " << argv[0] << " -estremo a- -estremo b- -precisione-"<<std::endl;
    return -1;
  }
  int npassi = 300;
  double a=atof(argv[1]);
  double b=atof(argv[2]);
  double prec=atof(argv[3]);
  if(a>b){
   double c=a;
   a=b;
   b=c;
  }
  Parabola p(3,5,-2);
  Retta r(1, 1);

  Bisezione bis(npassi);
  double zero=bis.Precision(prec).CercaZeri(a,b,&p);
  if(bis.Trovato()) 
  {
    std::cout << "Zero trovato in: " << std::fixed << std::setprecision(-log10(prec)) << zero << std::endl;
    std::cout << "in " << bis.Steps() << " passi, con un'incertezza di ±" << bis.Incertezza() << std::endl;
    std::cout << "la precisione richiesta era " << prec  << std::endl;
  } else 
    std::cerr << "Non è stato possibile trovare uno zero con la precisione richiesta" << std::endl;
    
  return 0;
}
