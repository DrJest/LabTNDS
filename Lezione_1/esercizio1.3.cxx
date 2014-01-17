#include <cmath>
#include <iostream>

long double ave (double* a){
  long double sum=0;
  int n = sizeof(a);
  for(int i = 0; i<n; ++i)
    sum += a[i];
  return sum/n;
}

long double ave (long double *a){
  long double sum=0;
  int n = sizeof(a);
  for (int i=0;i<n;++i)
    sum += a[i];
  return sum/n;
}

long double var(double* a){
  long double sum=0,med,med2,v,s;
  int n = sizeof(a);
  long double p[n];
  for (int i=0;i<n;i++)
    p[i]=pow(a[i],2);
  med = ave(a);
  med2 = ave(p);
  s=pow(med,2);
  double c=(double(n)/double(n-1));
  v=c*(med2-s);
  return v;
}

long double var(long double *a){
  long double sum=0,med,med2,v,s;
  int n = sizeof(a);
  long double p[n];
  for (int i=0;i<n;i++)
    p[i]=pow(a[i],2);
  med = ave(a);
  med2 = ave(p);
  s=pow(med,2);
  double c=(double(n)/double(n-1));
  v=c*(med2-s);
  return v;
}
