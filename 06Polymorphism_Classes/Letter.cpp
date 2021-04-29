#include "Letter.h"

const double Letter::COST_PER_OUNCE = 0.45;
const int Letter::DAILY_TRAVEL = 100;
const double Letter::INSURANCE_COST = 0.45;
const double Letter::RUSH_COST = 0.10;

Letter::Letter() : Parcel(){
}

void Letter::addInsurance(ostream& rcOut) {
	Parcel::addInsurance(rcOut);
	mCost += INSURANCE_COST;

	rcOut << INSURANCE_COST << endl;
	print(rcOut);
}

void Letter::rushItem(ostream& rcOut) {
	Parcel::rushItem(rcOut);
	if (mTravelTime > MIN_TRAVEL_TIME) {
		mTravelTime--;
	}

	rcOut << fixed << (mCost * RUSH_COST) << endl;
	mCost += (mCost * RUSH_COST);
	print(rcOut);
}

void Letter::deliverItem(ostream& rcOut) {
	Parcel::deliverItem(rcOut);
	print(rcOut);
}

void Letter::calculateCost() {
	mCost = mWeight * COST_PER_OUNCE;
}

void Letter::calculateDistance() {
	mTravelTime = (mTravelDistance / DAILY_TRAVEL);
	if (mTravelTime < MIN_TRAVEL_TIME) {
		mTravelTime = MIN_TRAVEL_TIME;
	}
}

void Letter::read(istream& rcIn) {
	Parcel::read(rcIn);
	calculateCost();
	calculateDistance();
}

void Letter::print(ostream& rcOut) {
	Parcel::print(rcOut);
}