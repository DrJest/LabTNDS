#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include "Bisezione.hpp"
#include "Buca.hpp"

int main(int argc,char** argv){
double prec = 1e-6;
Buca bu(0);
FunzioneBase* t = &(bu);
Bisezione bis(3000);
bis.setPrecision(prec);
double a, b, zero;
for (int i=0;i<21;++i){
	a=i*M_PI;
	b=i*M_PI+M_PI/2;
	zero = bis.CercaZeri(a,b,&bu);
	std::cout << std::fixed << "Zero trovato: " << std::setprecision(-log10(prec)) << zero << " nell'intervallo ["<<a<<","<<b<<"]"<<std::endl;
}

return 0;
}
