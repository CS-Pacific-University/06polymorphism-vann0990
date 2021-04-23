#include "Postcard.h"

const double Postcard::STARTING_COST = 0.15;
const int Postcard::DAILY_TRAVEL = 10;

Postcard::Postcard() : Parcel(){
	mMessage = "";
}

void Postcard::addInsurance() {
	mNewCost = mCost + .15;
}

void Postcard::rushItem() {
	mNewCost = mNewCost + .25;
	if (mTravelTime > MIN_TRAVEL_TIME) {
		mTravelTime--;
	}
}

void Postcard::deliverItem(ostream& rcOut) {

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