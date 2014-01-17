#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include "Parabola.hpp"
#include "Retta.hpp"
#include "Bisezione.hpp"
using namespace std;
int main(int argc,char** argv){
//controlla gli argomenti!!!
if (argc!=4) {std::cerr<<"usage:"<<argv[0]<<"-estremo a- -estremo b- -precisione-"<<endl;
return -1;
}
double a=atof(argv[1]);
double b=atof(argv[2]);
double prec=atof(argv[3]);
if(a>b){
 double c=a;
 a=b;
 b=c;
}
Parabola p(3,5,-2);
Retta r(1, 1);

Bisezione bis(3000);
bis.setPrecision(prec);
double zero=bis.CercaZeri(a,b,&p);

std::cout << "Zero in: " << zero << std::endl;
return 0;

}//incolla funzione scambia eventualmente

