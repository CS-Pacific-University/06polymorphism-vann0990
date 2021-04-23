#include "Postcard.h"

const double Postcard::STARTING_COST = 0.15;
const int Postcard::DAILY_TRAVEL = 10;

Postcard::Postcard() : Parcel(){
	mMessage = "";
}

void Postcard::addInsurance(ostream& rcOut) {
	mNewCost =+ mCost + .15;
	Parcel::addInsurance(rcOut);
	print(rcOut);
}

void Postcard::rushItem(ostream& rcOut) {
	mNewCost += mNewCost + .25;
	if (mTravelTime > MIN_TRAVEL_TIME) {
		mTravelTime--;
	}
	Parcel::rushItem(rcOut);
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