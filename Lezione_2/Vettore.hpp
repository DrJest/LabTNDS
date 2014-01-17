struct Vettore {
unsigned int N;
double* v;
};

struct Vettore read(unsigned int N, const char* filename);//creo la struct legge n num da un x file
void print (const Vettore);//stampa
void selectionSort(Vettore);//ordina
void scambia(double&, double&);
