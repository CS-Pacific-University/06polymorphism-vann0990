#pragma once
#include <string>
#include <iostream>

using namespace std;

class Parcel {
public:
	Parcel();

	virtual void addInsurance();
	virtual void rushItem();
	virtual void deliverItem(ostream&);
	virtual void calculateCost() = 0;
	virtual void calculateDistance() = 0;

	virtual void read(istream&);
	virtual void print(ostream&);

private:
	int mTrackingNum;
	string mTo;
	string mFrom;
	bool mInsured;
	bool mRushed;

protected:
	static const int MIN_TRAVEL_TIME;
	double mWeight;
	double mTravelDistance;
	double mCost;
	double mTravelTime;
	double mNewCost;
};