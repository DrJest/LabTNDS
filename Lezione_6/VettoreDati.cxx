#include "VettoreDati.hpp"
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <iostream>
using namespace std;


void Scambia(double &first,double &second){
  double temp;
  temp=first;
  first=second;
  second=temp;
  return;
}

VettoreDati::VettoreDati()
:Vettore()
{
}

VettoreDati::VettoreDati(int n)
:Vettore(n)
{
}


VettoreDati::VettoreDati(unsigned int N, const char* filename){
  std::ifstream inputFile(filename);
  m_N = N;
  m_v = new double[N];
  if (!inputFile){
    std::cerr<<"Cannot open file: "<< filename << std::endl;
  }else{
    std::cerr<<"I'm reading.."<<std::endl;
    for (unsigned int i=0;i<m_N;i++){
      inputFile>>m_v[i];
      if(inputFile.eof()){
      std::cerr<<"Stop reading after"<<i<<"entries"<< std::endl;
      break;
                }
            }
        }
  inputFile.close();
}

void VettoreDati::print_f(const char* filename){
  std::ofstream outputFile(filename);
  for (unsigned int i=0;i<m_N;i++)
    outputFile<<m_v[i]<<std::endl;
  outputFile.close();
}

void VettoreDati::print_f(){
  int width=int(log10(m_N)+1);
  for (unsigned int i=0;i<m_N;i++){
      std::cout<<setw(width)<<i+1<<")"<<m_v[i]<<std::endl;
  }
}

void VettoreDati::SelectionSort(){
  int  min;
  for (int i=0; i<m_N-1; i++) {
    min = i;
    for (int j=i+1; j<m_N; j++){
      if (m_v[min]>m_v[j]){
        min = j;
      }
    }
    Scambia(m_v[i], m_v[min]);  
  } 
 return;
}

void VettoreDati::QuickSort() {
  QuickSort(0, length()-1);
}

void VettoreDati::QuickSort(unsigned int first, unsigned int last){
  if (first>last ||first>=length()) return;
  if (last-first<= 1) {
    if (m_v[first]>m_v[last]) 
      Scambia(m_v[first],m_v[last]);
    return;
  }
  double pivot = Component((first+last)/2);
  unsigned int down=first, up=last;
  while (down<up){
    while (Component(down)<pivot) down++;
    while (Component(up)<pivot) up--;
    if (down<up){
      Scambia(m_v[down],m_v[up]);
      down++;
    }
  }
  QuickSort(first,down-1);
  QuickSort(down, last);  
}

double VettoreDati::Media(){
  double s=0;
  for (int i=0;i<m_N;i++)  s+=m_v[i];
  return s/(m_N+1);
}

double VettoreDati::Varianza(){
  double s=0, m = Media();
  for (int i=0;i<m_N;++i)
     s+=pow(m_v[i]-m,2);
  return s/(m_N);
}

double VettoreDati::DevStd(){
  return sqrt(Varianza());
}

double VettoreDati::Covarianza(VettoreDati& V){
  int s=0;
  double media = Media();
  for (int i=0;i<m_N;i++) 
    s+=(m_v[i]-media)*(V.Component(i)-V.Media());
  return s/m_N;
}

double VettoreDati::Correlazione(VettoreDati& V){
  return Covarianza(V)/(Varianza()*V.Varianza());
}

double VettoreDati::Mediana(){
  QuickSort();
  return m_v[(int)floor(m_N/2)];
}

VettoreDati& VettoreDati::Slice(int s, int e)
{
  if(s<0) s += length();
  if(!length() || s>length() || s<0) 
    return *(new VettoreDati);
  if(e==0) e=length();
  int L = e-s;
  VettoreDati* V = new VettoreDati(L);
  for(int i=s, j=0; j<L; j++, i++)
    V->m_v[j] = m_v[i];
  
  return *V;
}
