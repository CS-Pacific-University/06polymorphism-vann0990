#pragma once

#include "Parcel.h"
#include <string>
#include <iostream>

using namespace std;

class OvernightPackage : public Parcel {
public:
	OvernightPackage();
	void calculateCost();
	void calculateTravelTime();

	virtual void addInsurance();
	virtual void rushItem();
	virtual void deliverItem(ostream&);

	virtual void read(istream&);
	virtual void print(ostream&);

private:
	static const double SMALL_PACKAGE_COST;
	static const double LARGE_PACKAGE_COST;
	static const int LONG_DISTANCE_TIME;
	static const int SHORT_DISTANCE_TIME;
	static const int PACKAGE_SIZE_DIVIDE;
	double mVolume;
	double mOriginalCost;
};