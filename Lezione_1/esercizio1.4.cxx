#include <cmath>

int Modulo(int n)
{
  return n>0 ? n : -n;
}

double Modulo(double n)
{
  return (n>0) ? n : -n;
}

double Modulo(double* a)
{
  double x=a[0], y=a[1];
  return sqrt(x*x + y*y);
}

double Modulo(double* a, int n)
{
  double sum=0;
  
  for(int i=0;i<n;i++)
    sum += pow(a[i],2);

  return sqrt(sum);
}
