#include "RentingBook.h"

RentingBook::RentingBook(DateTime startDate, int durationInDays)
{
	this->startDate = startDate;
	this->durationInDays = durationInDays;

	this->status = BookingStatus::Requested;
	this->reservationNumber = "123";
	this->checkin = DateTime(0, 0, 0);
	this->checkout = DateTime(0, 0, 0);
}

string RentingBook::toString()
{
	return
	"[Booking] start "
		+ startDate.toString() + " - "
		+ startDate.afterNDays(durationInDays).toString();
}
