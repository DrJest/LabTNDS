#ifndef _Vettore_h_
#define _Vettore_h_
class Vettore {
  public:
    Vettore();
    Vettore(unsigned int);
    Vettore(unsigned int N, double v[]);
    Vettore(const Vettore&);
    ~Vettore();
    Vettore& operator=(const Vettore&);
    unsigned int length() const {return m_N;}
    double& Component(unsigned int);
    double& operator[](unsigned int);
    Vettore& Reverse();
    Vettore& Splice(int,int);
    Vettore& Splice(int,int, double[]);
    Vettore& Slice(int);
    Vettore& Slice(int,int);
    Vettore& Push(const double&);
    double& Pop();
    double& Shift();
    int IndexOf(double);
    int LastIndexOf(double);
  protected:
    unsigned int m_N;
    double* m_v;
};
#endif

