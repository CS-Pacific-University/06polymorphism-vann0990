//***************************************************************************
// File name:  Letter.h
// Author:     Jordan Vann
// Date:       4/23/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Declares the functions and variables for Letter
// numbers
//***************************************************************************

#pragma once

#include "Parcel.h"
#include <string>
#include <iostream>

using namespace std;

class Letter : public Parcel{
public:
	Letter();

	virtual void addInsurance(ostream&);
	virtual void rushItem(ostream&);
	virtual void deliverItem(ostream&);
	virtual void calculateCost();
	virtual void calculateDistance();

	virtual void read(istream&);
	virtual void print(ostream&);

private:
	static const double COST_PER_OUNCE;
	static const int DAILY_TRAVEL;
	static const double INSURANCE_COST;
	static const double RUSH_COST;
};