#pragma once
#include <string>
#include <iostream>

using namespace std;

class Parcel {
public:
	Parcel();
	void setCost(double);
	void setTravelTime(double);

	double getWeight();
	double getDistance();
	double getCost();

	virtual void addInsurance();
	virtual void rushItem();
	virtual void deliverItem(ostream&) = 0;

	virtual void read(istream&);
	virtual void print(ostream&);

private:
	static const int MIN_TRAVEL_TIME;
	int mTrackingNum;
	string mTo;
	string mFrom;
	double mWeight;
	double mTravelDistance;
	double mCost;
	double mTravelTime;
	bool mInsured;
	bool mRushed;
};