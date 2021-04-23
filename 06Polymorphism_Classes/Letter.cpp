#include "Letter.h"

const double Letter::COST_PER_OUNCE = 0.45;
const int Letter::DAILY_TRAVEL = 100;

Letter::Letter() : Parcel(){
}

void Letter::addInsurance(ostream& rcOut) {
	Parcel::addInsurance(rcOut);
	mNewCost += mCost + .45;
	rcOut << "$" << mNewCost;
	print(rcOut);
}

void Letter::rushItem(ostream& rcOut) {
	Parcel::rushItem(rcOut);
	mNewCost += mCost * .10;
	if (mTravelTime > MIN_TRAVEL_TIME) {
		mTravelTime--;
	}
	rcOut << "$" << mNewCost;
	print(rcOut);
}

void Letter::deliverItem(ostream& rcOut) {

}

void Letter::calculateCost() {
	mCost = mWeight * COST_PER_OUNCE;
}

void Letter::calculateDistance() {
	mTravelTime = (mTravelDistance / DAILY_TRAVEL);
}

void Letter::read(istream& rcIn) {
	Parcel::read(rcIn);
	calculateCost();
	calculateDistance();
}

void Letter::print(ostream& rcOut) {
	Parcel::print(rcOut);
}