#include "Parcel.h"

const int Parcel::MIN_TRAVEL_TIME = 0;

Parcel::Parcel() {
	mTrackingNum = 0;
	mTo = "";
	mFrom = "";
	mWeight = 0;
	mTravelDistance = 0;
	mCost = 0;
	mTravelTime = MIN_TRAVEL_TIME;
	bool mInsured = false;
	bool mRushed = false;
}

void Parcel::setCost(double cost) {
	mCost = cost;
}

void Parcel::setTravelTime(double travelTime) {
	if (travelTime >= MIN_TRAVEL_TIME) {
		mTravelTime = travelTime;
	}
}

double Parcel::getWeight() {
	return mWeight;
}

double Parcel::getDistance() {
	return mTravelDistance;
}

double Parcel::getCost() {
	return mCost;
}

void Parcel::addInsurance() {

}

void Parcel::rushItem() {

}

void Parcel::deliverItem(ostream& rcOut) {

}

void Parcel::read(istream& rcIn) {
	rcIn >> mTrackingNum >> mTo >> mFrom >> mWeight >> mTravelDistance;
}

void Parcel::print(ostream& rcOut) {
	rcOut << "TID: " << mTrackingNum << "\t";
	rcOut << "From: " << mFrom << "\t";
	rcOut << "To: " << mTo << "\t";

	if (mInsured == true) {
		rcOut << "INSURED" << "\t";
	}

	if (mRushed == true) {
		rcOut << "RUSH" << "\t";
	}
}