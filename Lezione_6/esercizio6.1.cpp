#include "VettoreDati.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <ctime>

int main (int argc,char**argv){
  if( remove( "table.txt" ) != 0 )
    std::cerr << "Error deleting file" << std::endl;
  else
    std::cerr << "File successfully deleted" << std::endl;
    
  std::ofstream table;
  table.open("table.txt", std::ios::app);
  std::chrono::time_point<std::chrono::system_clock> start, end;
  unsigned int N=10000;
  VettoreDati v(N,"data.txt");
  int n;
  std::chrono::duration<double> elapsed_seconds;
  for(int i = 0; i<10; ++i) 
  {
    n = i*1000;
    VettoreDati w = v.Slice(0, n);
    start = std::chrono::system_clock::now();
    w.SelectionSort();
    end = std::chrono::system_clock::now();

    elapsed_seconds = end-start;
    table << std::fixed << std::setw(8) << n << "|" << elapsed_seconds.count() << std::endl;
  }
  table.close();
  return 0;
}
