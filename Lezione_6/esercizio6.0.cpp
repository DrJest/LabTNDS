#include <iostream>
#include "Vettore.hpp"

int main (){
  Vettore *a= new Vettore(10);
  for (int i=0;i<a->length();i++)
    a->Component(i) = 10.*i;
  std::cout<<"Vettore a iniziale"<<std::endl;
  for (int i=0;i<a->length();i++)
    std::cout<<i<<")"<<a->Component(i)<<"\t";
  std::cout<<std::endl;
  
  if(! a->length()) return 0;

  Vettore b=(*a);
  std::cout<<"Vettore b iniziale:"<<std::endl;
  for (int i=0;i<b.length();i++)
    std::cout<<i<<")"<<b[i]<<"\t";
  std::cout<<std::endl;
    
  for (int i=0;i<b.length();i++)
    b[i] = 9.*i;

  std::cout<<"Vettore b modificato:"<<std::endl;
  for (int i=0;i<b.length();i++)
    std::cout<<i<<")"<<b[i]<<"\t";
  std::cout<<std::endl;

  std::cout<<"Vettore a:"<<std::endl;
  for (int i=0;i<a->length();i++)
    std::cout<<i<<")"<<a->Component(i)<<"\t";
  std::cout<<std::endl;

  std::cout << "b = a, again. Vettore b:" << std::endl;
  b = (*a);
  for (int i=0;i<b.length();i++)
    std::cout<<i<<")"<<b[i]<<"\t";
  std::cout<<std::endl;
  
  delete a;
  std::cout << "A deleted" << std::endl;
  
  return 0;
}
