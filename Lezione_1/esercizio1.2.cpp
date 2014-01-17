#include <iostream>
#include <fstream>
#include "esercizio1.1.hpp"

int main ()
{
  int N;
  double elem1;
  std::ifstream inputFile;
  std::ofstream outputFile;
  inputFile.open("dati.dat");
  outputFile.open("output.txt");

  if (!inputFile){
    outputFile<<"error: File not found"<<std::endl;
    return -1;
  }
  
  inputFile>>N;
  double* v = new double[N];
  
  for (int i=0;i<N;i++){
    inputFile>>elem1; 
    v[i]=elem1;
  }

  for (int z=0;z<N;z=z+2)
    swapByReference(v[z],v[z+1]);

  /**
  * http://www.cplusplus.com/reference/array/array/operator[]/
  * op[] <-> &(v+z*dimensione)
  * l'operatore [] restituisce già di per sé una reference all'element
  * ennesimo del vettore.
  */
  for (int m=0;m<N;m++)
    outputFile<<v[m]<<std::endl;
  
  delete []v;
  inputFile.close();
  outputFile.close();
  return 0;
}
