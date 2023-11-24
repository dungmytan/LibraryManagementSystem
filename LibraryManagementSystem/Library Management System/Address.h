#pragma once
#include <iostream>
#include <string>
using namespace std;

class Address
{
public:
	string streetAddress;
	string ward;
	string district;
	string city;

public:
	Address(
		string streetAddress,
		string ward,
		string district,
		string city
	);
	Address() = default;
	string toString();
};

