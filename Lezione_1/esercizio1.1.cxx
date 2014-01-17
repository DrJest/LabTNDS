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
