#include "Letter.h"

const double Letter::COST_PER_OUNCE = 0.45;
const int Letter::DAILY_TRAVEL = 100;

Letter::Letter() : Parcel(){
}

void Letter::addInsurance() {

}

void Letter::rushItem() {

}

void Letter::deliverItem(ostream& rcOut) {

}

void Letter::calculateCost() {
	Parcel::setCost(getWeight() * COST_PER_OUNCE);
}

void Letter::calculateDistance() {
	Parcel::setTravelTime(getDistance() / DAILY_TRAVEL);
}

void Letter::read(istream& rcIn) {
	Parcel::read(rcIn);
	calculateCost();
	calculateDistance();
}

void Letter::print(ostream& rcOut) {
	Parcel::print(rcOut);
}