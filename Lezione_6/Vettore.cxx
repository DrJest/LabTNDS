#include "Vettore.hpp"
#include <iostream>
#include <cmath>

using namespace std;
Vettore::Vettore()
{
  m_N=0;
  m_v=0;
}

Vettore::Vettore(unsigned int N){
  m_N=N;
  m_v=new double[N];
  for (int i=0;i<N;i++)
  m_v[i]=0.;
}

Vettore::Vettore(unsigned int N, double v[]){
  m_N=N;
  m_v=new double[N];
  for (int i=0;i<N;i++)
  m_v[i]=v[i];
}

Vettore::~Vettore()
{
  delete[] m_v;
}

Vettore::Vettore(const Vettore& V)
: Vettore(V.length())
{
  for(int i=0;i<m_N;i++) 
    m_v[i]=V.m_v[i];
}

Vettore& Vettore::operator=(const Vettore & V) 
{
  m_N=V.m_N;
  if (m_v) delete[] m_v;
  m_v=new double [m_N];
  for (int i=0;i<m_N;i++) m_v[i]=V.m_v[i];
  return *this;
}

double& Vettore::Component(unsigned int i)
{  
  return m_v[i];
}

double& Vettore::operator[] (unsigned int i)
{
  return m_v[i];
}

Vettore& Vettore::Reverse()
{
  int l = length()-1, 
      c = floor(l/2);
  double t;
  for (int i=0;i<=c;++i)
  {
    t = m_v[i];
    m_v[i] = m_v[l-i];
    m_v[l-i] = t;
  }
  return *this;
}

Vettore& Vettore::Splice(int s, int c)
{
  if(s<0) s += length();
  if(!length() || s>length() || !c || s<0) 
    return *(new Vettore);
  if(s+c>length()) c = length()-s;
  int L = length()-c;
  double* v = new double[L];
  double* w = new double[c];
  for(int i=0; i<s; ++i)
    v[i] = m_v[i];
  for(int i=0; i<c; ++i)
    w[i] = m_v[s+i];
  for(int i=s+c; i<length(); ++i)
    v[i-c] = m_v[i];
  Vettore* V = new Vettore(c, w);
  delete[] m_v;
  m_v = v;
  m_N = L;
  return *V;
}

Vettore& Vettore::Splice(int s, int c, double a[])
{
  if(s<0) s += length();
  if(!length() || s>length() || !c || s<0) 
    return *this;
  int L = length()+c;
  double* v = new double[L];
  for(int i=0; i<s; ++i)
    v[i] = m_v[i];
  for(int i=s, j=0; i<s+c; ++i)
    v[i] = a[j++];
  for(int i=s+c, j=s; i<L; ++i)
    v[i] = m_v[j++];
  m_N = L;
  delete[] m_v;
  m_v = v;
  return *(new Vettore(c,a));
}

Vettore& Vettore::Slice(int s)
{
  return Slice(s, 0);
}

Vettore& Vettore::Slice(int s, int e)
{
  if(s<0) s += length();
  if(!length() || s>length() || s<0) 
    return *(new Vettore);
  if(e==0) e=length();
  int L = e-s;
  Vettore* V = new Vettore(L);
  for(int i=s, j=0; j<L; j++, i++)
    V->m_v[j] = m_v[i];
  
  return *V;
}

Vettore& Vettore::Push(const double& n)
{
  m_N++;
  double* v = new double[m_N];
  for(int i = 0; i < m_N -1; ++i)
    v[i] = m_v[i];
  v[m_N-1] = n;
  delete[] m_v;
  m_v = v;
  return *this;
}

double& Vettore::Pop()
{
  if(!length()) return *(new double(0));
  m_N--;
  double t = m_v[m_N];
  double* v = new double[m_N];
  for(int i=0; i<m_N; ++i)
    v[i] = m_v[i];
  delete[] m_v;
  m_v = v;
  return *(new double(t));
}

double& Vettore::Shift()
{
  if(!length()) return *(new double(0));
  m_N--;
  double t = m_v[0];
  double* v = new double[m_N];
  for(int i=1; i<=m_N; ++i)
    v[i-1] = m_v[i];
  delete[] m_v;
  m_v = v;
  return *(new double(t));
}

int Vettore::IndexOf(double n)
{
  for(int i = 0; i<length(); ++i)
    if(m_v[i]==n) return i;
  return -1;
}

int Vettore::LastIndexOf(double n)
{
  for(int i = length()-1; i>-1; --i)
    if(m_v[i]==n) return i;
  return -1;
}
