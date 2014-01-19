#include "VettoreDati.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <ctime>
#include <stdio.h>

int main (int argc,char**argv){
   if( remove( "quick.txt" ) != 0 )
    std::cerr << "Error deleting file" << std::endl;
  else
    std::cerr << "File successfully deleted" << std::endl;
    
  std::ofstream table;
  table.open("quick.txt", std::ios::app);
  std::chrono::time_point<std::chrono::system_clock> start, end;
  unsigned int N=100000;
  VettoreDati v(N,"data.txt");
  int n;
  std::chrono::duration<double> s_s, q_s;
  VettoreDati s, w;
  for(int i = 1; i<=100; ++i) 
  {
    n = i*1000;
    w = v.Slice(0, n);
    s = v.Slice(0, n);
    start = std::chrono::system_clock::now();
    w.SelectionSort();
    end = std::chrono::system_clock::now();
    s_s = end-start;
    start = std::chrono::system_clock::now();
    s.QuickSort();
    end = std::chrono::system_clock::now();
    q_s = end-start;
    table << std::fixed << std::setw(8) << n << "|" << s_s.count() << "|" << q_s.count() << std::endl;
  }
  table.close();
  return 0;
}
