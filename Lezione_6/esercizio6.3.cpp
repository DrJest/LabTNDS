#include "VettoreDati.hpp"
#include <iostream>
int main(int argc, char** argv) 
{
  VettoreDati V(1000, "data.txt");
  VettoreDati W(1000, "data2.txt");
  
  std::cout << "Media dei valori in V: " << V.Media() << std::endl;
  std::cout << "Media dei valori in W: " << W.Media() << std::endl;
  
  std::cout << "Varianza dei valori in V: " << V.Varianza() << std::endl;
  std::cout << "Varianza dei valori in W: " << W.Varianza() << std::endl;
  
  std::cout << "StdDev dei valori in V: " << V.DevStd() << std::endl;
  std::cout << "StdDev dei valori in W: " << W.DevStd() << std::endl;
  
  V.QuickSort();
  W.QuickSort();
  
  std::cout << "Mediana dei valori in V: " << V.Mediana() << std::endl;
  std::cout << "Mediana dei valori in W: " << W.Mediana() << std::endl;
  
  std::cout << "Correlazione dei valori di V e W: " << V.Correlazione(W) << std::endl;
  std::cout << "Correlazione dei valori di V e W: " << W.Correlazione(V) << std::endl;
  return 0;
}
