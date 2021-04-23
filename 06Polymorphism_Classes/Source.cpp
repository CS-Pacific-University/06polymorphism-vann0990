#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "Parcel.h"
#include "Letter.h"
#include "Postcard.h"
#include "OvernightPackage.h"

using namespace std;

void readFile(istream&);
void printMenu(string&);
void printAllParcels();
bool checkID(string);
void addInsurance();

const int MAX_PARCELS = 25;
Parcel* apcParcel[MAX_PARCELS];

const char LETTER = 'L';
const char POSTCARD = 'P';
const char OVERNIGHT = 'O';
const string OPTION_1 = "1";
const string OPTION_2 = "2";
const string OPTION_3 = "3";
const string OPTION_4 = "4";
const string OPTION_5 = "5";

int main() {
  ifstream inputFile;
  string menuChoice;

  inputFile.open("parcels.txt");
  readFile(inputFile);
  inputFile.close();

  cout << "Mail Simulator\n";

  do {
    printMenu(menuChoice);

  } while (menuChoice != OPTION_5);




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

void printMenu(string& choice) {
  do {
    cout << "1.\tPrint All\n";
    cout << "2.\tAdd Insurance\n";
    cout << "3.\tAdd Rush\n";
    cout << "4.\tDeliver\n";
    cout << "5.\tAdd Rush\n";

    cin >> choice;

  } while (choice != OPTION_1 && choice != OPTION_2 && choice != OPTION_3
    && choice != OPTION_4 && choice != OPTION_5);
}

void printAllParcels() {
  for (int i = 0; i < MAX_PARCELS; i++) {
    apcParcel[i]->print(cout);
  }
}

bool checkID(string idNum) {
  bool valid = false;
  if (stoi(idNum) >= 0 && stoi(idNum) <= MAX_PARCELS) {
    valid = true;
  }

  return valid;
}

void addInsurance() {
  string idNum;

  do {
    cout << "TID> ";
    cin >> idNum;
  } while (checkID(idNum));


}
