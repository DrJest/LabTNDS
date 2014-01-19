#include "TH1F.h"
#include <iostream>
#include "Random.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "Gaussiana.hpp"

int main (int argc, char** argv) {
  TApplication App("App", &argc, argv);
  //PRIMA PARTE 
  Random rand;
  rand.A(1664525);
  rand.C(1013904223);
  rand.M(pow(2,31));
  TH1F h1("h1", "Numeri Pseudocasuali", 100, 0, 1);
  TCanvas *c1 = new TCanvas("c1","c1");
  for (int i=0; i<100000; ++i) {
    double n = rand.Rand();
    h1.Fill(n);
  }
  c1->cd();
  h1.Draw();
  Random rand1;
  rand1.A(4);
  rand1.C(1);
  rand1.M(9);
  for (int i=0; i<10; ++i) {
    for (int j=0; j<10; ++j)
      std::cout << rand1.Rand() << " ";
    std::cout << std:: endl;
  }


  //SECONDA PARTE

  Random rand2;
  rand2.A(1664525);
  rand2.C(1013904223);
  rand2.M(pow(2,31));

  Gaussiana gauss1(1.,1.);
  Gaussiana gauss2(0.,2.);

  double x, y;
  double max = gauss1.Max(0.,1.)*5./4.;
  std::cout << max << std::endl;
  TH1F h2("h2", "Numeri Pseudocasuali Gauss(1,1)", 100, 0, 1);
  TCanvas *c2 = new TCanvas("c2","c2");

  for (int i=0; i<100000; ++i) {
    x = rand2.Rand();
    y = max*rand2.Rand();
    if(y<gauss1[x]) 
      h2.Fill(x);
  }

  c2->cd();
  h2.Draw();

  //2.5

  TH1F h3("h3", "Numeri Pseudocasuali Gauss(0,2)", 100, 0, 1);
  TCanvas *c3 = new TCanvas("c3","c3");

  for (int i=0; i<100000; ++i)
  {
    x = rand2.Rand();
    y = max*rand2.Rand();
    if(y<gauss2[x])
      h3.Fill(x);
  }

  c3->cd();
  h3.Draw();

  //TERZA PARTE
  TH1F h4("h4", "Numeri Pseudocasuali Gauss", 100, 0, 1);
  TCanvas *c4 = new TCanvas("c4","c4");

  for (int i=0; i<100000; ++i) {
  double n = rand.Gauss(0.5,0.5);
  h4.Fill(n);
  }

  c4->cd();
  h4.Draw();

  //3.5
  TH1F h5("h5", "Numeri Pseudocasuali Exp", 100, 0, 1);
  TCanvas *c5 = new TCanvas("c5","c5");

  for (int i=0; i<100000; ++i) {
  double n = rand.Exp(0.5);
  h5.Fill(n);
  }

  c5->cd();
  h5.Draw();


  App.Run();

  return 0;
}
