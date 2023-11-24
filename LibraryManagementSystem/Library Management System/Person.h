#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "Address.h"

class Person
{
public:
	string name;
	Address address;
	string email;
	string phone;

public:
	Person();
	Person(
		string name, 
		string phone, 
		string email);
	Person(
		string name,
		string phone,
		string email,
		Address address
	);
	string toString();
	string getName();
	Address getAddress();
	string getEmail();
	string getPhone();
};

