#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

#include "BasicTypes.h"
#include "DateTime.h"

class RentingBook
{
	string reservationNumber;
	DateTime startDate;
	int durationInDays;

	BookingStatus status;
	DateTime checkin;
	DateTime checkout;

public:
	RentingBook(
		DateTime startDate,
		int durationInDays
	);

	string toString();
};

