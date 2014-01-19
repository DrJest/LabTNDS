#ifndef _VettoreDati_h_
#define _VettoreDati_h_
#include "Vettore.hpp"

class VettoreDati:public Vettore{
public:
  VettoreDati();
  VettoreDati(int);
  VettoreDati(unsigned int N, const char* filename);
  
  double Media();
  double DevStd();
  double Varianza();
  double Covarianza(VettoreDati&);
  double Correlazione(VettoreDati&);
  double Mediana();
  
  void print_f(const char*);
  void print_f();
  void QuickSort(unsigned int first, unsigned int last);
  void QuickSort();
  void SelectionSort();
  VettoreDati& Slice(int,int);
};
#endif
