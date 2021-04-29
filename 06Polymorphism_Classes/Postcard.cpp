//***************************************************************************
// File name:  Postcard.cpp
// Author:     Jordan Vann
// Date:       4/23/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Implements the functions and the constructor for Postcard
//***************************************************************************

#include "Postcard.h"

const double Postcard::STARTING_COST = 0.15;
const int Postcard::DAILY_TRAVEL = 10;
const double Postcard::INSURANCE_COST = 0.15;
const double Postcard::RUSH_COST = 0.25;


//***************************************************************************
// Constructor: Postcard
//
// Description: Initializes the member variables to theit default values
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Postcard::Postcard() : Parcel(){
	mMessage = "";
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
void Postcard::addInsurance(ostream& rcOut) {
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
void Postcard::rushItem(ostream& rcOut) {
	Parcel::rushItem(rcOut);
	mCost += RUSH_COST;
	if (mTravelTime > MIN_TRAVEL_TIME) {
		mTravelTime -= 2;
	}

	rcOut << RUSH_COST << endl;
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
void Postcard::deliverItem(ostream& rcOut) {
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
void Postcard::calculateCost() {
	mCost = (STARTING_COST);
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
void Postcard::calculateDistance() {
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
void Postcard::read(istream& rcIn) {
	Parcel::read(rcIn);
	rcIn >> mMessage;
	calculateCost();
	calculateDistance();
}

//***************************************************************************
// Function:    print
//
// Description: prints out information about the Postcard using the member 
//              variables and calls on the print function in Parcel
//
// Parameters:  rcOut - ostream used to print out information
//
// Returned:    None
//***************************************************************************
void Postcard::print(ostream& rcOut) {
	Parcel::print(rcOut);
	rcOut << mMessage;
}