//***************************************************************************
// File name:    main.cpp
// Author:       Jordan Vann
// Date:         4/23/21
// Class:        CS250
// Assignment:   Polymorphism
// Purpose:      To implement the classes in a mail simulator
// Hours worked: 5
//***************************************************************************

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
bool checkID(int);
int getTID();
bool checkForMail();
void deleteAllParcels();

const int MAX_PARCELS = 25;
Parcel* apcParcel[MAX_PARCELS] = { nullptr };

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
      apcParcel[TID] = nullptr;
    }
    cout << endl;

  } while (menuChoice != OPTION_5);

  deleteAllParcels();
 
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
    cout << "1. Print All\n";
    cout << "2. Add Insurance\n";
    cout << "3. Add Rush\n";
    cout << "4. Deliver\n";
    cout << "5. Quit\n\n";

    cout << "Choice> ";
    cin >> choice;
    cout << endl;

  } while (choice != OPTION_1 && choice != OPTION_2 && choice != OPTION_3
    && choice != OPTION_4 && choice != OPTION_5);
}

void printAllParcels() {
  for (int i = 0; i < MAX_PARCELS; i++) {
    if (apcParcel[i] != nullptr) {
      apcParcel[i]->print(cout);
      cout << endl;
    }
  }
}

bool checkID(int idNum) {
  bool valid = false;
  if (idNum >= 0 && idNum <= MAX_PARCELS) {
    if (apcParcel[idNum] != nullptr) {
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
  } while (!checkID(stoi(idNum) - 1));

  return (stoi(idNum) - 1);
}

bool checkForMail() {
  bool mail = false;

  for (int i = 0; i < MAX_PARCELS; i++) {
    if (apcParcel[i] != nullptr) {
      mail = true;
    }
  }
  return mail;
}

void deleteAllParcels() {
  for (int i = 0; i < MAX_PARCELS; i++) {
    if (apcParcel[i] != nullptr) {
      delete apcParcel[i];
    }
  }
}