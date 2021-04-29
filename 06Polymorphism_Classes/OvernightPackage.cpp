//***************************************************************************
// File name:  OvernightPackage.cpp
// Author:     Jordan Vann
// Date:       4/23/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Implements the functions and the constructor for 
//             OvernightPackage
//***************************************************************************

#include "OvernightPackage.h"

const double OvernightPackage::SMALL_PACKAGE_COST = 12;
const double OvernightPackage::LARGE_PACKAGE_COST = 20;
const int OvernightPackage::LONG_DISTANCE_TIME = 2;
const int OvernightPackage::SHORT_DISTANCE_TIME = 1;
const int OvernightPackage::PACKAGE_SIZE_DIVIDE = 100;
const int OvernightPackage::TRAVEL_TIME_DIVIDE = 1000;
const double OvernightPackage::INSURANCE_COST = 0.25;
const double OvernightPackage::RUSH_COST = 0.75;


//***************************************************************************
// Constructor: OvernightPackage
//
// Description: Initializes the member variables to theit default values
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
OvernightPackage::OvernightPackage() : Parcel(){
	mVolume = 0;
}

void OvernightPackage::addInsurance(ostream& rcOut) {
	Parcel::addInsurance(rcOut);
	rcOut.precision(2);

	rcOut << fixed << (mCost * INSURANCE_COST) << endl;
	mCost += (mCost * INSURANCE_COST);
	print(rcOut);
}

void OvernightPackage::rushItem(ostream& rcOut) {
	Parcel::rushItem(rcOut);
	if (mTravelTime > MIN_TRAVEL_TIME) {
		mTravelTime = MIN_TRAVEL_TIME;
	}

	rcOut.precision(2);

	rcOut << fixed << (mCost * RUSH_COST) << endl;
	mCost += (mCost * RUSH_COST);
	print(rcOut);
}

void OvernightPackage::deliverItem(ostream& rcOut) {
	Parcel::deliverItem(rcOut);
	print(rcOut);
}

void OvernightPackage::calculateCost() {
	if (mVolume > PACKAGE_SIZE_DIVIDE) {
		mCost = LARGE_PACKAGE_COST;
	}
	else {
		mCost = SMALL_PACKAGE_COST;
	}
}

void OvernightPackage::calculateDistance() {
	if (mTravelDistance > TRAVEL_TIME_DIVIDE) {
		mTravelTime = LONG_DISTANCE_TIME;
	}
	else {
		mTravelTime = SHORT_DISTANCE_TIME;
	}
}

void OvernightPackage::read(istream& rcIn) {
	Parcel::read(rcIn);
	rcIn >> mVolume;
	calculateCost();
	calculateDistance();
}

void OvernightPackage::print(ostream& rcOut) {
	Parcel::print(rcOut);
	rcOut << " OVERNIGHT!";
}