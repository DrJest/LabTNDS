#include "Vettore.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

Vettore read(unsigned int N, const char*filename)
{
  struct Vettore vec;
  vec.N=N;
  vec.v=new double[N];
  std::ifstream inputFile(filename);
  if (!inputFile)
  {
  std::cerr<<"Cannot open file"<<filename<< std::endl;
  }else{
    for (int i=0;i<N;i++)
    {
      inputFile>>vec.v[i];
      if(inputFile.eof())
      {
        std::cerr<<"stop reading after"<<i<<"entries!"<< std::endl;
        break;
      }
    }
  }
  input.close();
  return vec;
}

void print (const Vettore vec)
{
  int width=int(log10(vec.N)+1);
  for(unsigned int i=0;i<vec.N;i++)
    std::cout << std::setw(width) << i << vec.v[i] << std::endl;
}

void selectionSort(Vettore vec) {
  double* v = vec.v;
  int dim = vec.N;
  int min;
  for(int i=0;i<dim ;i++) {
    min = i;
    for(int j=i+1;j<dim;j++) {
      if(v[j] < v[min])
        min = j;
    }
    scambia(v[i], v[min]);
  }
}

void scambia(double &a, double &b) {
    double c=a;
    a=b;
    b=c;
}
