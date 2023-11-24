#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;
class DateTime
{
private:
	int day, month, year;
	int hour, minute, second;
	int dataType;

public:
	DateTime(int dt01, int dt02, int dt03, int datatype = 1);
	DateTime(int day, int month, int year,
		int hour, int minute, int second);
	DateTime() = default;

	int getDay();
	int getMonth();
	int getYear();

	DateTime afterNDays(int n);

	string toString();
};

