//-------------------------------------------------------------------
//
//      rand.cpp
//
//      Program creates random numbers and puts them into the appropriate text
//      files
//
//-------------------------------------------------------------------
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ofstream outfile;
  outfile.open("1000Numbers.txt");  // Writes 1000 integers to 1000 number file

  for (int i = 0; i < 1000; i++) {
    outfile << rand() % 1000001 << endl;
  }

  outfile.close();
  outfile.open("10000Numbers.txt");  // Writes 10000 integers to 10000 number file

  for (int i = 0; i < 10000; i++) {
    outfile << rand() % 1000001 << endl;
  }

  outfile.close();
  outfile.open("100000Numbers.txt");  // Writes 100000 integers to 100000 number file

  for (int i = 0; i < 100000; i++) {
    outfile << rand() % 1000001 << endl;
  }

  return 0;
}
