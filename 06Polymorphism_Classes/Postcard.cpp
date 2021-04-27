#include "Postcard.h"

const double Postcard::STARTING_COST = 0.15;
const int Postcard::DAILY_TRAVEL = 10;
const double INSURANCE_COST = 0.15;
const double RUSH_COST = 0.25;

Postcard::Postcard() : Parcel(){
	mMessage = "";
}

void Postcard::addInsurance(ostream& rcOut) {
	Parcel::addInsurance(rcOut);
	mCost += INSURANCE_COST;

	rcOut << INSURANCE_COST << endl;
	print(rcOut);
}

void Postcard::rushItem(ostream& rcOut) {
	Parcel::rushItem(rcOut);
	mCost += RUSH_COST;
	if (mTravelTime > MIN_TRAVEL_TIME) {
		mTravelTime -= 2;
	}

	rcOut << RUSH_COST << endl;
	print(rcOut);
}

void Postcard::deliverItem(ostream& rcOut) {
	Parcel::deliverItem(rcOut);
	print(rcOut);
}

void Postcard::calculateCost() {
	mCost = (STARTING_COST);
}
void Postcard::calculateDistance() {
	mTravelTime = (mTravelDistance / DAILY_TRAVEL);
}

void Postcard::read(istream& rcIn) {
	Parcel::read(rcIn);
	rcIn >> mMessage;
	calculateCost();
	calculateDistance();
}

void Postcard::print(ostream& rcOut) {
	Parcel::print(rcOut);
	rcOut << mMessage;
}