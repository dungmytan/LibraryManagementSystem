#include "Person.h"

Person::Person(){}

Person::Person(string name, string phone, string email)
{
	this->name = name;
	this->phone = phone;
	this->email = email;
}

Person::Person(string name, string phone, string email, Address address)
{
	this->name = name;
	this->phone = phone;
	this->email = email;
	this->address = address;
}

string Person::toString()
{
	return "Name: " + this->name
		+ "\nPhone: " + this->phone
		+ "\nEmail: " + this->email
		+ "\nAddress: " + this->address.toString();
}

string Person::getName()
{
	return this->name;
}

Address Person::getAddress()
{
	return this->address;
}

string Person::getEmail()
{
	return this->email;
}

string Person::getPhone()
{
	return this->phone;
}
