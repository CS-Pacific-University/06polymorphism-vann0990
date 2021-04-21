#include "OvernightPackage.h"

const double OvernightPackage::SMALL_PACKAGE_COST = 20;
const double OvernightPackage::LARGE_PACKAGE_COST = 12;
const int OvernightPackage::LONG_DISTANCE_TIME = 2;
const int OvernightPackage::SHORT_DISTANCE_TIME = 1;
const int OvernightPackage::PACKAGE_SIZE_DIVIDE = 1000;

OvernightPackage::OvernightPackage() : Parcel(){
	mVolume = 0;
	mOriginalCost = 0;
}

void OvernightPackage::calculateCost() {

}

void OvernightPackage::calculateTravelTime() {

}

void OvernightPackage::addInsurance() {

}

void OvernightPackage::rushItem() {

}

void OvernightPackage::deliverItem(ostream& rcOut) {

}

void OvernightPackage::read(istream& rcIn) {

}

void OvernightPackage::print(ostream& rcOut) {

}