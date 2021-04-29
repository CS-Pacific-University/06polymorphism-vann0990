//***************************************************************************
// File name:  Postcard.h
// Author:     Jordan Vann
// Date:       4/23/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Declares the functions and variables for Postcard
// numbers
//***************************************************************************

#pragma once

#include "Parcel.h"
#include <string>
#include <iostream>

using namespace std;

class Postcard : public Parcel {
public:
	Postcard();

	virtual void addInsurance(ostream&);
	virtual void rushItem(ostream&);
	virtual void deliverItem(ostream&);
	virtual void calculateCost();
	virtual void calculateDistance();

	void read(istream&);
	void print(ostream&);

private:
	static const double STARTING_COST;
	static const int DAILY_TRAVEL;
	static const double INSURANCE_COST;
	static const double RUSH_COST;
	string mMessage;
};