//***************************************************************************
// File name:  Parcel.cpp
// Author:     Jordan Vann
// Date:       4/23/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Implements the functions and the constructor for Parcel
//***************************************************************************

#include "Parcel.h"

const int Parcel::MIN_TRAVEL_TIME = 1;

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

void Parcel::addInsurance(ostream& rcOut) {
	mInsured = true;
	rcOut << "Added Insurance for $";
}

void Parcel::rushItem(ostream& rcOut) {
	mRushed = true;
	rcOut << "Added Rush for $";
}

void Parcel::deliverItem(ostream& rcOut) {
	rcOut << "Delivered!\n";
	rcOut.precision(0);
	rcOut << mTravelTime << " Day, ";
	rcOut.precision(2);
	rcOut << "$" << fixed << mCost << endl;
}

void Parcel::read(istream& rcIn) {
	rcIn >> mTrackingNum >> mTo >> mFrom >> mWeight >> mTravelDistance;
}

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