//***************************************************************************
// File name:  Parcel.cpp
// Author:     Jordan Vann
// Date:       4/23/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Implements the functions and the constructor for Parcel
//***************************************************************************

#include "Parcel.h"


//***************************************************************************
// Constructor: Parcel
//
// Description: Initializes the member variables to theit default values
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Parcel::Parcel() {
	mTrackingNum = 0;
	mTo = "";
	mFrom = "";
	mWeight = 0;
	mTravelDistance = 0;
	mCost = 0;
	mTravelTime = MIN_TRAVEL_TIME;
	bool mInsured = false;
	bool mRushed = false;
}


//***************************************************************************
// Function:    addInsurance
//
// Description: Sets mInsured to true and outputs a message
//
// Parameters:  rcOut - ostream used to output message
//
// Returned:    None
//***************************************************************************
void Parcel::addInsurance(ostream& rcOut) {
	mInsured = true;
	rcOut << "Added Insurance for $";
}

//***************************************************************************
// Function:    rushItem
//
// Description: Sets mrushed to true and outputs a message
//
// Parameters:  rcOut - ostream used to output message
//
// Returned:    None
//***************************************************************************
void Parcel::rushItem(ostream& rcOut) {
	mRushed = true;
	rcOut << "Added Rush for $";
}


//***************************************************************************
// Function:    deliverItem
//
// Description: Outputs a message saying that the parcel has been delivered
//              and the travel time and cost of the parcel
//
// Parameters:  rcOut - ostream used to output message
//
// Returned:    None
//***************************************************************************
void Parcel::deliverItem(ostream& rcOut) {
	rcOut << "Delivered!\n";
	rcOut.precision(0);
	rcOut << mTravelTime << " Day, ";
	rcOut.precision(2);
	rcOut << "$" << fixed << mCost << endl;
}

//***************************************************************************
// Function:    read
//
// Description: reads in information and sets member variable equal to that 
//              information
//
// Parameters:  rcIn - istream used to read in information
//
// Returned:    None
//***************************************************************************
void Parcel::read(istream& rcIn) {
	rcIn >> mTrackingNum >> mTo >> mFrom >> mWeight >> mTravelDistance;
}

//***************************************************************************
// Function:    print
//
// Description: prints out information about the Parcel using the member 
//              variables
//
// Parameters:  rcOut - ostream used to print out information
//
// Returned:    None
//***************************************************************************
void Parcel::print(ostream& rcOut) {
	rcOut << "TID: " << mTrackingNum << "\t";
	rcOut << "From: " << mFrom << "\t";
	rcOut << "To: " << mTo << "\t";

	if (mInsured == true || mRushed == true) {
		cout << " ";
	}

	if (mInsured == true) {
		rcOut << "INSURED" << "\t";
	}

	if (mRushed == true) {
		rcOut << "RUSH" << "\t";
	}
}