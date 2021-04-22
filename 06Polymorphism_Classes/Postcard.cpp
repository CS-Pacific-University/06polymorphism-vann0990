#include "Postcard.h"

const double Postcard::STARTING_COST = 0.15;
const int Postcard::DAILY_TRAVEL = 10;

Postcard::Postcard() : Parcel(){
	mMessage = "";
}

void Postcard::addInsurance() {

}

void Postcard::rushItem() {

}

void Postcard::deliverItem(ostream& rcOut) {

}

void Postcard::read(istream& rcIn) {
	Parcel::read(rcIn);
	rcIn >> mMessage;
}

void Postcard::print(ostream& rcOut) {
	Parcel::print(rcOut);
	rcOut << mMessage;
}