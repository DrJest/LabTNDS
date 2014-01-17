#include <iostream>
#include <cmath>
#include <iomanip>
#include "esercizio1.3.hpp"

int main ()
{ 
  double a=0,x,f;

  long double f_better,x_better,v,m,mh,vh;

  //first point
  a=0.3-0.2-0.1;
  std::cout << "0.3-0.2-0.1: " << std::scientific << a << std::endl;
  a=0.3-(0.2+0.1);
  std::cout << "0.3-(0.2+0.1): " << a << std::endl;
  a=0.4-0.3-0.1;
  std::cout << "0.4-0.3-0.1: " << a << std::endl;
  a=0.4-(0.3+0.1);
  std::cout << "0.4-(0.3+0.1): " << a << std::endl;
  a=(1E15+ 1) - 1E15;
  std::cout << "(1E15+ 1) - 1E15" << a << std::endl;
  a=(1E16 + 1) - 1E16;
  std::cout << "(1E16 + 1) - 1E16" << a << std::endl;

  //second point
  std::cout<<std::setfill('|') << std::setprecision(5);
  for(int i=0;i<=18;i++){
    x=pow(10,i);
    x_better=pow(10,i);
    f=sqrt(x+1)-sqrt(x); 
    f_better=sqrt(x_better+1)+(-1)*sqrt(x_better);
    std::cout << std::setw(12) << x << std::setw(12) << f << std::setw(12) << f_better << std::endl;
  }

  //third point
  int N=4;
  double data[4] ={4,7,13,16};



  m=ave(data);

  std::cout<<"average of data: "<<std::setprecision(2)<<m<<std::endl;//average

  v=var(data);

  std::cout<<"variance of data: "<<std::setprecision(2)<<v<<std::endl;
  long double data_hugenumber[N];
  for (int j=0;j<4;j++)
    data_hugenumber[j]=(data[j]+1E9);//increase of the array
  mh=ave(data_hugenumber);
  vh=var(data_hugenumber);
  std::cout<<"media of data_hugenumber: "<<std::setprecision(2)<<mh<<std::endl;//average
  std::cout<<"variance of data_hugenumber: "<<std::setprecision(2)<<vh<<std::endl;     

  return 0;
}
