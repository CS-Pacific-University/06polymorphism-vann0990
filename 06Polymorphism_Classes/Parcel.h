//***************************************************************************
// File name:  Parcel.h
// Author:     Jordan Vann
// Date:       4/23/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Declares the functions and variables for Parcel
// numbers
//***************************************************************************

#pragma once
#include <string>
#include <iostream>

using namespace std;

class Parcel {
public:
	Parcel();

	virtual void addInsurance(ostream&);
	virtual void rushItem(ostream&);
	virtual void deliverItem(ostream&);
	virtual void calculateCost() = 0;
	virtual void calculateDistance() = 0;

	virtual void read(istream&);
	virtual void print(ostream&);

private:
	int mTrackingNum;
	string mTo;
	string mFrom;

protected:
	static const int MIN_TRAVEL_TIME;
	double mWeight;
	double mTravelDistance;
	double mCost;
	double mTravelTime;
	bool mInsured;
	bool mRushed;
};