#include "Parcel.h"

const int Parcel::MIN_TRAVEL_TIME = 0;

Parcel::Parcel() {
	mTo = "";
	mFrom = "";
	mWeight = 0;
	mTravelDistance = 0;
	mCost = 0;
	mTravelTime = 0;
	bool mInsured = false;
	bool mRushed = false;
}

void Parcel::setCost(double cost) {

}

void Parcel::setTravelTime(double travelTime) {

}

double Parcel::getWeight() {

}

double Parcel::getDistance() {

}

double Parcel::getCost() {

}

void Parcel::addInsurance() {

}

void Parcel::rushItem() {

}

void Parcel::deliverItem(ostream& rcOut) {

}

void Parcel::read(istream& rcIn) {

}

void Parcel::print(ostream& rcOut) {

}