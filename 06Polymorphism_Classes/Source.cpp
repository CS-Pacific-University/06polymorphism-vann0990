#include <iostream>
#include <fstream>
#include <iomanip>

#include "Parcel.h"

using namespace std;

int main() {
  const int MAX_PARCELS = 25;
  Parcel *apcParcel[MAX_PARCELS];
  ifstream inputFile;

  inputFile.open("parcels.txt");


  cout << "Reached the end!\n";
  return EXIT_SUCCESS;
}