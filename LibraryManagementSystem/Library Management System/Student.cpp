#include "Student.h"

Student::Student():Person(){}

Student::Student(string idStudent, string major, Person person)
	:Person(
		person.getName(),
		person.getPhone(),
		person.getEmail()
	)
{
	this->idStudent = idStudent;
	this->major = major;
}

string Student::toString()
{
	return "ID: " + this->idStudent
		+ "\nName: " + this->getName()
		+ "\nPhone: " + this->getPhone()
		+ "\nEmail: " + this->getEmail()
		+ "\nMajor: " + this->major;
}

string Student::getIdStudent()
{
	return this->idStudent;
}
