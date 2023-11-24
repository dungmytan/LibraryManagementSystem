#include "DateTime.h"

DateTime::DateTime(int dt01, int dt02, int dt03, int datatype)
{
	if (datatype == 1) 
	{
		this->day = dt01;
		this->month = dt02;
		this->year = dt03;
		this->dataType = 1;
	}
	else 
	{
		hour = dt01;
		minute = dt02;
		second = dt03;
		this->dataType = 2;
	}
}

DateTime::DateTime(int day, int month, int year, int hour, int minute, int second)
{
	this->dataType = 0;
	this->year = year;
	this->month = month;
	this->day = day;
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}

int DateTime::getDay()
{
	return this->day;
}

int DateTime::getMonth()
{
	return this->month;
}

int DateTime::getYear()
{
	return this->year;
}

DateTime DateTime::afterNDays(int n)
{
	return DateTime(this->day + n, this->month, this->year);
}

string DateTime::toString()
{
	return to_string(this->day)
		+ "/" + to_string(this->month)
		+ "/" + to_string(this->year);
}
