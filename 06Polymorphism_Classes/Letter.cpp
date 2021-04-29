//***************************************************************************
// File name:  Letter.cpp
// Author:     Jordan Vann
// Date:       4/23/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Implements the functions and the constructor for Letter
//***************************************************************************

#include "Letter.h"

const double Letter::COST_PER_OUNCE = 0.45;
const int Letter::DAILY_TRAVEL = 100;
const double Letter::INSURANCE_COST = 0.45;
const double Letter::RUSH_COST = 0.10;

//***************************************************************************
// Constructor: Letter
//
// Description: Initializes the member variables to theit default values
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Letter::Letter() : Parcel(){
}

//***************************************************************************
// Function:    addInsurance
//
// Description: Adds the insurance cost to mCost and calls on the print 
//              function and the addInsurance function in Parcel
//
// Parameters:  rcOut - ostream used to output a message, to call the print
//                      function and the addInsurance function in Parcel
//
// Returned:    None
//***************************************************************************
void Letter::addInsurance(ostream& rcOut) {
	Parcel::addInsurance(rcOut);
	mCost += INSURANCE_COST;

	rcOut << INSURANCE_COST << endl;
	print(rcOut);
}

//***************************************************************************
// Function:    rushItem
//
// Description: Adds the rush cost cost to mCost and calls on the print 
//              function, and the rushItem function in Parcel
//
// Parameters:  rcOut - ostream used to output a message, to call the print
//                      function, and the rushItem function in Parcel
//
// Returned:    None
//***************************************************************************
void Letter::rushItem(ostream& rcOut) {
	Parcel::rushItem(rcOut);
	if (mTravelTime > MIN_TRAVEL_TIME) {
		mTravelTime--;
	}

	rcOut.precision(2);
	rcOut << fixed << (mCost * RUSH_COST) << endl;
	mCost += (mCost * RUSH_COST);
	print(rcOut);
}

//***************************************************************************
// Function:    deliverItem
//
// Description: Calls on the deliverItem function in Parcel, and calls on
//              the print function
//
// Parameters:  rcOut - ostream used to call on the functions
//
// Returned:    None
//***************************************************************************
void Letter::deliverItem(ostream& rcOut) {
	Parcel::deliverItem(rcOut);
	print(rcOut);
}

//***************************************************************************
// Function:    calculateCost
//
// Description: calculates and sets the value of mCost
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Letter::calculateCost() {
	mCost = mWeight * COST_PER_OUNCE;
}

//***************************************************************************
// Function:    calculateDistance
//
// Description: calculates and sets the value of mTravelDistance
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Letter::calculateDistance() {
	mTravelTime = (mTravelDistance / DAILY_TRAVEL);
	if (mTravelTime < MIN_TRAVEL_TIME) {
		mTravelTime = MIN_TRAVEL_TIME;
	}
}

//***************************************************************************
// Function:    read
//
// Description: reads in information and sets member variable equal to that 
//              information and calls on the read function in Parcel, and 
//              calls on calculateCost and calculateDistance
//
// Parameters:  rcIn - istream used to read in information
//
// Returned:    None
//***************************************************************************
void Letter::read(istream& rcIn) {
	Parcel::read(rcIn);
	calculateCost();
	calculateDistance();
}

//***************************************************************************
// Function:    print
//
// Description: calls on the print function in Parcel
//
// Parameters:  rcOut - ostream used to call on the print function
//
// Returned:    None
//***************************************************************************
void Letter::print(ostream& rcOut) {
	Parcel::print(rcOut);
}