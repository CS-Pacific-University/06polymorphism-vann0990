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

//***************************************************************************
// Function:    main
//
// Description: calls on functions for the mail simulator
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
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
    else if (menuChoice == OPTION_5) {

    }
    else {
      TID = getTID();
      if (checkID(TID) == true) {
        if (menuChoice == OPTION_2) {
          apcParcel[TID]->addInsurance(cout);
        }
        else if (menuChoice == OPTION_3) {
          apcParcel[TID]->rushItem(cout);
        }
        else if (menuChoice == OPTION_4) {
          apcParcel[TID]->deliverItem(cout);
          apcParcel[TID] = nullptr;

        }
        cout << endl;
      }
    }

    cout << endl;
  } while (menuChoice != OPTION_5);

  deleteAllParcels();
 
  return EXIT_SUCCESS;
}

//***************************************************************************
// Function:    readFile
//
// Description: reads the file and sets the values of the array apcParcel
//
// Parameters:  rcIn - istream used to read the file
//
// Returned:    None
//***************************************************************************
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

//***************************************************************************
// Function:    printMenu
//
// Description: prints out the menu until the user imputs a correct choice
//
// Parameters:  choice - the variable that stores the users choice
//
// Returned:    None
//***************************************************************************
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

//***************************************************************************
// Function:    printAllParcels
//
// Description: prints out information for all valid parcels
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void printAllParcels() {
  for (int i = 0; i < MAX_PARCELS; i++) {
    if (apcParcel[i] != nullptr) {
      apcParcel[i]->print(cout);
      cout << endl;
    }
  }
}

//***************************************************************************
// Function:    checkID
//
// Description: checks to see if the passed in idNum is valid
//
// Parameters:  idNum - the number that is being checked
//
// Returned:    true if the idNum is valid, false otherwise
//***************************************************************************
bool checkID(int idNum) {
  bool valid = false;
  if (idNum >= 0 && idNum <= MAX_PARCELS) {
    if (apcParcel[idNum] != nullptr) {
      valid = true;
    }
  }

  return valid;
}

//***************************************************************************
// Function:    getTID
//
// Description: asks for the users TID choice until it gets a valid response
//
// Parameters:  None
//
// Returned:    the valid TID number
//***************************************************************************
int getTID() {
  string idNum;
    cout << "TID> ";
    cin >> idNum;

  return (stoi(idNum) - 1);
}


//***************************************************************************
// Function:    checkForMail
//
// Description: checks to see if their is any mail for the mail simulator
//
// Parameters:  None
//
// Returned:    true if there is mail, false otherwise
//***************************************************************************
bool checkForMail() {
  bool mail = false;

  for (int i = 0; i < MAX_PARCELS; i++) {
    if (apcParcel[i] != nullptr) {
      mail = true;
    }
  }
  return mail;
}

//***************************************************************************
// Function:    deleteAllParcels
//
// Description: deletes all of the pointers in the array apcParcel that 
//              haven't already been deleted
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void deleteAllParcels() {
  for (int i = 0; i < MAX_PARCELS; i++) {
    if (apcParcel[i] != nullptr) {
      delete apcParcel[i];
    }
  }
}