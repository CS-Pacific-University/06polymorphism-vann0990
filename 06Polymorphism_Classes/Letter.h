#pragma once

#include "Parcel.h"
#include <string>
#include <iostream>

using namespace std;

class Letter : public Parcel{
public:
	Letter();

	virtual void addInsurance();
	virtual void rushItem();
	virtual void deliverItem(ostream&);
	virtual void calculateCost();
	virtual void calculateDistance();

	virtual void read(istream&);
	virtual void print(ostream&);

private:
	static const double COST_PER_OUNCE;
	static const int DAILY_TRAVEL;
};