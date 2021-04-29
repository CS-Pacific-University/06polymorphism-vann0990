//***************************************************************************
// File name:  OvernightPackage.h
// Author:     Jordan Vann
// Date:       4/23/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Declares the functions and variables for OvernightPackage
// numbers
//***************************************************************************

#pragma once

#include "Parcel.h"
#include <string>
#include <iostream>

using namespace std;

class OvernightPackage : public Parcel {
public:
	OvernightPackage();

	virtual void addInsurance(ostream&);
	virtual void rushItem(ostream&);
	virtual void deliverItem(ostream&);
	virtual void calculateCost();
	virtual void calculateDistance();

	virtual void read(istream&);
	virtual void print(ostream&);

private:
	static const double SMALL_PACKAGE_COST;
	static const double LARGE_PACKAGE_COST;
	static const int LONG_DISTANCE_TIME;
	static const int SHORT_DISTANCE_TIME;
	static const int PACKAGE_SIZE_DIVIDE;
	static const int TRAVEL_TIME_DIVIDE;
	static const double INSURANCE_COST;
	static const double RUSH_COST;
	double mVolume;
};