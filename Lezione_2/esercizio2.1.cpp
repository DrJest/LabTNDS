#include <iostream>

int GlobalSwaps = 0;
int const numeroscambi()
{
  return GlobalSwaps;
}

void swapByValue(double a, double b)
{
  static int Swaps=0;
  Swaps++;
  GlobalSwaps++;
  double temp;
  temp=a;
  a=b;
  b=temp;
  std::cout << "Swaps in swapByValue(): " << Swaps << std::endl;
}

void swapByPointer(double *a, double *b)
{
  static int Swaps=0;
  Swaps++;
  GlobalSwaps++;
  double temp;
  temp=*a;
  *a=*b;
  *b=temp;
  std::cout << "Swaps in swapByPointer(): " << Swaps << std::endl;
}

void swapByReference(double &a, double &b)
{
  static int Swaps=0;
  Swaps++;
  GlobalSwaps++;
  double temp;
  temp=a;
  a=b;
  b=temp;
  std::cout << "Swaps in swapByReference(): " << Swaps << std::endl;
}

int main (){
  double a,b,n;
  std::cout<<"Type 2 numbers:";
  std::cin>>a>>b;
  std::cout<<"Type numbers of iterations: ";
  std::cin>>n;
  for(int i=0;i<n;i++){
  swapByValue(a,b);
  std::cout<<"con lo scambioBYvalue ottengo "<<a<<" "<<b<<std::endl;
  swapByReference(a,b);
  std::cout<<"con lo scambioBYreference ottengo "<<a<<" "<<b<<std::endl;
  swapByPointer(&a,&b);
  std::cout<<"con lo scambioBYpointer ottengo "<<a<<" "<<b<<std::endl;
  std::cout<<"il numero scambi totali è "<<numeroscambi()<<std::endl;
  }
  return 0;

}


