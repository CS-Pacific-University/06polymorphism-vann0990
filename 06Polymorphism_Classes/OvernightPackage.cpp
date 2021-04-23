#include "OvernightPackage.h"

const double OvernightPackage::SMALL_PACKAGE_COST = 12;
const double OvernightPackage::LARGE_PACKAGE_COST = 20;
const int OvernightPackage::LONG_DISTANCE_TIME = 2;
const int OvernightPackage::SHORT_DISTANCE_TIME = 1;
const int OvernightPackage::PACKAGE_SIZE_DIVIDE = 100;
const int OvernightPackage::TRAVEL_TIME_DIVIDE = 1000;

OvernightPackage::OvernightPackage() : Parcel(){
	mVolume = 0;
}

void OvernightPackage::addInsurance() {
	mNewCost = mCost + .25;
}

void OvernightPackage::rushItem() {
	mNewCost = mCost * .75;
	if (mTravelTime > MIN_TRAVEL_TIME) {
		mTravelTime--;
	}
}

void OvernightPackage::deliverItem(ostream& rcOut) {

}

void OvernightPackage::calculateCost() {
	if (mVolume > PACKAGE_SIZE_DIVIDE) {
		mCost = LARGE_PACKAGE_COST;
	}
	else {
		mCost = SMALL_PACKAGE_COST;
	}
}

void OvernightPackage::calculateDistance() {
	if (mTravelDistance > TRAVEL_TIME_DIVIDE) {
		mTravelTime = LONG_DISTANCE_TIME;
	}
	else {
		mTravelTime = SHORT_DISTANCE_TIME;
	}
}

void OvernightPackage::read(istream& rcIn) {
	Parcel::read(rcIn);
	rcIn >> mVolume;
	calculateCost();
	calculateDistance();
}

void OvernightPackage::print(ostream& rcOut) {
	Parcel::print(rcOut);
	rcOut << "OVERNIGHT!";
}