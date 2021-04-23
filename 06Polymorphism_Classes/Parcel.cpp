#include "Parcel.h"

const int Parcel::MIN_TRAVEL_TIME = 0;

Parcel::Parcel() {
	mTrackingNum = 0;
	mTo = "";
	mFrom = "";
	mWeight = 0;
	mTravelDistance = 0;
	mCost = 0;
	mNewCost = 0;
	mTravelTime = MIN_TRAVEL_TIME;
	bool mInsured = false;
	bool mRushed = false;
}

void Parcel::addInsurance() {
	mInsured = true;
	cout << "Added Insurance for ";
}

void Parcel::rushItem() {
	mRushed = true;
	cout << "Added Rush for ";
}

void Parcel::deliverItem(ostream& rcOut) {
	cout << "Delivered!";
	cout << mTravelTime << " Day, ";
	cout << "$" << mCost;
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