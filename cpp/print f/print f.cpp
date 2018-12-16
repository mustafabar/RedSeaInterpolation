#include "../include_t/scalarfield.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
  double X[2225];
  double Y[2225];
  double Z[125];
  string line;
  int state = 0;
  int counter = 0;
  ifstream myfile ("charADAN2.txt");
  if (myfile.is_open()) {
    while (getline (myfile, line) ) 
    {
      if (line.at(0) == 'Y') {
        state = 1;
        counter = 0;
      }
      if (line.at(0) == 'Z') {
        state = 2;
        counter = 0;
      }
      if (state == 0) {
        istringstream ticker(line);
        istream_iterator<double> begin(ticker);
        istream_iterator<double> end;
        for ( ; begin != end;) {
          X[counter] = *begin++;
          counter++;
        }
      }
      if (state == 1) {
        istringstream ticker(line);
        istream_iterator<double> begin(ticker);
        istream_iterator<double> end;
        for ( ; begin != end;) {
          Y[counter] = *begin++;
          counter++;
        }
      }
      if (state == 2) {
        istringstream ticker(line);
        istream_iterator<double> begin(ticker);
        istream_iterator<double> end;
        for ( ; begin != end;) {
          Z[counter] = *begin++;
          counter++;
        }
      }
    }
    myfile.close();
    cout << "****************************************************************";
    cout << X[0] << "   " << X[2224];
    cout << "****************************************************************";
    cout << Y[0] << "   " << Y[2224];
    cout << "****************************************************************";
    cout << Z[0] << "   " << Z[124];

  }
  else cout << "Unable to open file";
  
  ofstream newfile ("charADAN.txt");
  if (newfile.is_open()) {
    for (int i = 0; i < 125; i++) {
      for (int j = 0; j < 2225; j++) {
        for (int k = 0; k < 2225; k++) {
          Point p(X[k], Y[j], Z[i]);
          myfile << sfcharac(p);
        }
      }
    }
  }
  return 0;
}
