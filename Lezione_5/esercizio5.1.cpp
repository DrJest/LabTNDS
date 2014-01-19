#include "Parabola.hpp"
#include <iostream>
#include <cstdlib>
int main(int argc, char** argv) 
{
  if(argc != 4) {
    std::cerr << "Usage: " << argv[0] << " -a- -b- -c-" << "\n"
              << "\tdove la parabola ha equazione y = ax^2 + bx + c" << std::endl;
    return -1;
  }
  
  Parabola f(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));
  
  double v =  -f.B() / 2 / f.A();
  std::cout << "Il vertice ha coordinate: (" << v << "," << f( v ) << ")" << std::endl;
  return 0;
}
