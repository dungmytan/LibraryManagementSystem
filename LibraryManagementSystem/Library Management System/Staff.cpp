#include "Staff.h"

Staff::Staff():Person(){}

Staff::Staff(string idStaff, Person person)
	:Person(
		person.getName(),
		person.getPhone(),
		person.getEmail(),
		person.getAddress()
	)
{
	this->idStaff = idStaff;
}

string Staff::toString()
{
	return "ID: " + this->idStaff
		+ "\nName: " + this->getName()
		+ "\nPhone: " + this->getPhone()
		+ "\nEmail: " + this->getEmail()
		+ "\nAddress: " + this->getAddress().toString();
}

string Staff::getIdStaff()
{
	return this->idStaff;
}
