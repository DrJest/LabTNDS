#include "Vettore.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <ctime>

int main (int argc,char**argv){
  int t0 = clock();
  if (argc<3) 
  {
    std::cerr<<"usage:"<<argv[0]<<"<N_points> <filename>"<<std::endl;
    return -1;
  }
  
  unsigned int N=atoi(argv[1]);
  
  Vettore vet = read (N,argv[2]);
  
  std::ofstream outputFile;
  outputFile.open("before.dat");
  std::cout<<"before sorting.."<<std::endl;
  print(vet);
  for(int i=0; i<N; ++i)
    outputFile << vet.v[i] << std::endl;
  outputFile.close();
  
  outputFile.open("after.dat");
  selectionSort(vet);
  std::cout<<"after sorting.."<<std::endl;
  print(vet);
  for(int i=0; i<N; ++i)
    outputFile << vet.v[i] << std::endl;
  outputFile.close();

  outputFile.open("data_time.dat", std::ios::app);
  
  double d = (double)(clock()-t0)/CLOCKS_PER_SEC;
  time << std::setw(5) << N << "|" << d << std::endl;
  std::cout<<"Tempo di esecuzione: "<<d<<std::endl;
  time.close();
  return 0;
}
