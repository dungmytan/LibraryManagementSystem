#include "PublishingHouse.h"

PublishingHouse::PublishingHouse(string name, string nation)
{
	this->name = name;
	this->nation = nation;
}

string PublishingHouse::toString()
{
	return "Publishing house: " + this->name
		+ "\nNation: " + this->nation;
}
