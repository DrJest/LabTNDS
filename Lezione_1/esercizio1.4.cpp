#include <iostream>
#include <fstream>

#include "esercizio1.4.hpp"

int main() 
{
  double n, vet[2];

  std::cout<<"insert a number: ";
  std::cin>>n;
  std::cout << "Modulo value of " << n << " is " << Modulo(n) << std::endl;
  std::cout<<"insert the two components of an array: ";
  std::cin>>vet[0]>>vet[1];
  std::cout<<"Modulo value of the array is " << Modulo(vet) << std::endl;
  
  int N;
  double elem1;
  std::ifstream inputFile;
  inputFile.open("dati.dat");

  if (!inputFile){
    std::cout<<"error: file not found"<<std::endl;
    return 1;
  }
  
  inputFile>>N;
  double *v=new double[N];
  for (int i=0;i<N;i++){
    inputFile>>v[i];
  }
  
  std::cout<<"Modulo of array in dati.dat is  "<<Modulo(v,N)<<std::endl;

  inputFile.close();

  return 0;
}
