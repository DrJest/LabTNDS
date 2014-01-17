#include <iostream>

void swapByValue(double, double);
void swapByPointer(double*, double*);
void swapByReference(double&, double&);

int main(int argc, char* argv[])
{
  double a, b;
  std::cout << "Insert 2 numbers: " << std::endl;
  
  std::cin >> a >> b;
  
  std::cout << "You typed: " << a << " and " << b << std::endl;
    
  swapByValue(a, b);
  
  std::cout << "After SwapByValue numbers are: " << a << " and " << b << std::endl;
    
  swapByPointer(&a, &b);
  
  std::cout << "After SwapByPointer numbers are: " << a << " and " << b << std::endl;
  
  swapByReference(a, b);
  
  std::cout << "After SwapByReference numbers are: " << a << " and " << b << std::endl;
  
  return 0;  
}

void swapByValue(double a, double b)
{
  double temp;
  temp=a;
  a=b;
  b=temp;
}

void swapByPointer(double *a, double *b)
{
  double temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

void swapByReference(double &a, double &b)
{
  double temp;
  temp=a;
  a=b;
  b=temp;
}
