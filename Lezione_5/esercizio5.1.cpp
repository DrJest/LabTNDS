#include "Parabola.hpp"
#include <iostream>

int main() 
{
  Parabola f(1,-1,0);
  
  double v =  -f.B() / 2 / f.A();
  std::cout << f( v ) << std::endl;
  return 0;
}
