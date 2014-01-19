#include "EsperimentoPrisma.hpp"
#include <iostream>
#include "TH1F.h"
#include "TH2F.h"
#include "TApplication.hpp"
#include "TCanvas.h"

int main(int argc, char* argv[]) {
TApplication App("App", &argc, argv);

EsperimentoPrisma esp;

esp.Itera(1e4);

double sigma =  esp.getSt();

//t0
double mean = esp.getT0();
double min = mean-5.*sigma;
double max = mean+5.*sigma;

TH1F t0("t0", "T0", 100, min, max);
TCanvas *c1 = new TCanvas("c1","c1");

for(int i = 0; i<esp.t0s.size(); ++i) {
t0.Fill(esp.t0s[i]);
}

std::cout << "MEDIA T0" << avg(esp.t0s) << std::endl;
std::cout << "DEVST T0" << std_dev(esp.t0s) << std::endl;

c1->cd();
t0.Draw();

//t1
mean = esp.getT1();
min = mean-5.*sigma;
max = mean+5.*sigma;

TH1F t1("t1", "T1", 100, min, max);
TCanvas *c2 = new TCanvas("c2","c2");

for(int i = 0; i<esp.t1s.size(); ++i) {
t1.Fill(esp.t1s[i]);
}

std::cout << "MEDIA T1" << avg(esp.t1s) << std::endl;
std::cout << "DEVST T1" << std_dev(esp.t1s) << std::endl;

c2->cd();
t1.Draw();

//t2
mean = esp.getT2();
min = mean-5.*sigma;
max = mean+5.*sigma;

TH1F t2("t2", "T2", 100, min, max);
TCanvas *c3 = new TCanvas("c3","c3");

for(int i = 0; i<esp.t2s.size(); ++i) {
t2.Fill(esp.t2s[i]);
}

std::cout << "MEDIA T0" << avg(esp.t2s) << std::endl;
std::cout << "DEVST T0" << std_dev(esp.t2s) << std::endl;

c3->cd();
t2.Draw();

//PARTE 2

//DM1
TH1F dm1("dm1", "DM1", 100, -0.003, .003);
TCanvas *c4 = new TCanvas("c4","c4");

for(int i = 0; i<esp.t1s.size(); ++i) {
dm1.Fill((esp.t1s[i]-esp.t0s[i])-(esp.getT1()-esp.getT0()));
}

c4->cd();
dm1.Draw();


//DM2
TH1F dm2("dm2", "DM2", 100, -0.003, .003);
TCanvas *c5 = new TCanvas("c5","c5");

for(int i = 0; i<esp.t2s.size(); ++i) {
dm2.Fill((esp.t2s[i]-esp.t0s[i])-(esp.getT2()-esp.getT0()));
}

c5->cd();
dm2.Draw();

//bidimensionale 
TH2F dd("dd","DD", 100, -0.003, 0.003, 100, -0.003, 0.003);
TCanvas *c6 = new TCanvas("c6","c6");

for(int i = 0; i<esp.t0s.size(); ++i) {
dd.Fill((esp.t1s[i]-esp.t0s[i])-(esp.getT1()-esp.getT0()) , (esp.t2s[i]-esp.t0s[i])-(esp.getT2()-esp.getT0()));
}

c6->cd();
dd.Draw();


App.Run();

return 0;
}
