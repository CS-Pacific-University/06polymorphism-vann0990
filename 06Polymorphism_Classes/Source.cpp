#include <iostream>
#include <fstream>
#include <iomanip>

#include "Parcel.h"
#include "Letter.h"
#include "Postcard.h"
#include "OvernightPackage.h"

using namespace std;

void readFile(istream&);


const int MAX_PARCELS = 25;
Parcel* apcParcel[MAX_PARCELS];

const char LETTER = 'L';
const char POSTCARD = 'P';
const char OVERNIGHT = 'O';
const char OPTION_1 = '1';
const char OPTION_2 = '2';
const char OPTION_3 = '3';
const char OPTION_4 = '4';
const char OPTION_5 = '5';

int main() {
  ifstream inputFile;
  string menuChoice;

  inputFile.open("parcels.txt");
  readFile(inputFile);
  inputFile.close();

  cout << "Mail Simulator\n";




  return EXIT_SUCCESS;
}

void readFile(istream& rcIn) {
  char parcelType;

  for (int i = 0; i < MAX_PARCELS; i++) {
    if (rcIn.eof()) {
      break;
    }
    if (rcIn.fail()) {
      cout << "File could not be opened";
    }

    rcIn >> parcelType;

    if (parcelType == LETTER) {
      apcParcel[i] = new Letter();
      apcParcel[i]->read(rcIn);
    }
    else if (parcelType == POSTCARD) {
      apcParcel[i] = new Postcard();
      apcParcel[i]->read(rcIn);
    }
    else if (parcelType == OVERNIGHT) {
      apcParcel[i] = new OvernightPackage();
      apcParcel[i]->read(rcIn);
    }
  }

}