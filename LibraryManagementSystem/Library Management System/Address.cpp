#include "Address.h"

Address::Address(string streetAddress, string ward, string district, string city)
{
	this->streetAddress = streetAddress;
	this->ward = ward;
	this->district = district;
	this->city = city;
}

string Address::toString()
{
	return this->streetAddress
		+ "/P." + this->ward
		+ "/Q." + this->district
		+ "/TP." + this->city;
}
