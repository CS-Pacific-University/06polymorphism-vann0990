#pragma once

#include "Parcel.h"
#include <string>
#include <iostream>

using namespace std;

class Postcard : public Parcel {
public:
	Postcard();

	virtual void addInsurance();
	virtual void rushItem();
	virtual void deliverItem(ostream&);

	void read(istream&);
	void print(ostream&);

private:
	static const double STARTING_COST;
	static const int DAILY_TRAVEL;
	string mMessage;
};