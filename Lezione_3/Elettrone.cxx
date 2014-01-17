#include "Elettrone.hpp"
#include <iostream>

Elettrone::Elettrone()
  :Particella(9.109e-31, -1.602e-19)
  {
  }

Elettrone::~Elettrone() 
{
}

void Elettrone::Print() const
{
  std::cout << "Elettrone{\nMassa: " << _m << "\nCarica: " << _c << "\n}" << std::endl;
}
