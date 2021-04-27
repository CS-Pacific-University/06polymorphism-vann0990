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
int getTID();
bool checkForMail();

const int MAX_PARCELS = 25;
Parcel* apcParcel[MAX_PARCELS] = { nullptr };
int gNumParcels = 0;

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
  int TID;

  inputFile.open("parcels.txt");
  readFile(inputFile);
  inputFile.close();

  cout << "Mail Simulator\n\n";

  do {
    printMenu(menuChoice);

    if (!checkForMail()) {
      break;
    }
    else if (menuChoice == OPTION_1) {
      printAllParcels();
    }
    else if (menuChoice == OPTION_2) {
      apcParcel[getTID()]->addInsurance(cout);
      cout << endl;
    }
    else if (menuChoice == OPTION_3) {
      apcParcel[getTID()]->rushItem(cout);
      cout << endl;
    }
    else if (menuChoice == OPTION_4) {
      TID = getTID();
      apcParcel[TID]->deliverItem(cout);
      cout << endl;

      delete apcParcel[TID];
    }
    cout << endl;

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
      gNumParcels++;
    }
    else if (parcelType == POSTCARD) {
      apcParcel[i] = new Postcard();
      apcParcel[i]->read(rcIn);
      gNumParcels++;
    }
    else if (parcelType == OVERNIGHT) {
      apcParcel[i] = new OvernightPackage();
      apcParcel[i]->read(rcIn);
      gNumParcels++;
    }
  }

}

void printMenu(string& choice) {
  do {
    cout << "1. Print All\n";
    cout << "2. Add Insurance\n";
    cout << "3. Add Rush\n";
    cout << "4. Deliver\n";
    cout << "5. Add Rush\n\n";

    cout << "Choice> ";
    cin >> choice;
    cout << endl;

  } while (choice != OPTION_1 && choice != OPTION_2 && choice != OPTION_3
    && choice != OPTION_4 && choice != OPTION_5);
}

void printAllParcels() {
  for (int i = 0; i < gNumParcels; i++) {
    apcParcel[i]->print(cout);
    cout << endl;
  }
}

bool checkID(string idNum) {
  bool valid = false;
  if (stoi(idNum) >= 0 && stoi(idNum) <= gNumParcels) {
    if (apcParcel[stoi(idNum)] != nullptr) {
      valid = true;
    }
  }

  return valid;
}

int getTID() {
  string idNum;

  do {
    cout << "TID> ";
    cin >> idNum;
  } while (!checkID(idNum));

  return (stoi(idNum) - 1);
}

bool checkForMail() {
  bool mail = false;

  for (int i = 0; i < gNumParcels; i++) {
    if (apcParcel[i] != nullptr) {
      mail = true;
    }
  }
  return mail;
}