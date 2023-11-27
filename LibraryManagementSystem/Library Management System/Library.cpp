#include <fstream>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "Library.h"
#include "Staff.h"
#include "Student.h"

Library::Library(string name)
{
	this->name = name;
}

string Library::toString()
{
	return "Library: " + this->name;
}

// ============= Student ============= //

list<Student> Library::getStudent()
{
	return this->studentList;
}

bool Library::addStudent(Student student)
{
	this->studentList.push_back(student);
	ofstream fileOut("Student.txt", std::ios::app);

	if (fileOut.is_open()) {
		fileOut << student.toString() << std::endl;
	}
	else {
		std::cerr << "Can not create a file to record." << std::endl;
	}

	fileOut.close();
	return true;
}

void Library::inputStudentFromFile()
{
	std::ifstream fileIn("Student.txt");
	std::string line, space;
	Student student;
	if (!fileIn.is_open()) {
		std::cerr << "Can not open file to read!" << std::endl;
		return;
	}

	while (!fileIn.eof())
	{
		while (getline(fileIn, line)) {
			std::istringstream iss(line);
			std::string key;

			getline(iss, key, ':');

			if (key == "ID") {
				if (student.idStudent != "")
				{
					this->studentList.push_back(student);
					student = Student();
				}
				getline(iss, space, ' ');
				space = "";
				getline(iss, student.idStudent);
			}
			else if (key == "Name") {
				getline(iss, space, ' ');
				space = "";
				getline(iss, student.name);
			}
			else if (key == "Phone") {
				getline(iss, space, ' ');
				space = "";
				getline(iss, student.phone);
			}
			else if (key == "Email") {
				getline(iss, space, ' ');
				space = "";
				getline(iss, student.email);
			}
			else if (key == "Major") {
				getline(iss, space, ' ');
				space = "";
				getline(iss, student.major);
			}

		}
		if (student.idStudent != "")
			this->studentList.push_back(student);
	}
	fileIn.close();
}

void Library::getViewStudent()
{
	cout << "Students in Library " << this->name << ":\n";

	for (auto& student : this->studentList)
	{
		cout << student.toString() << "\n\n";
	}
}

Student* Library::searchStudent(const string& idStudent)
{
	for (auto& student : this->studentList)
	{
		if (student.getIdStudent() == idStudent)
		{
			cout << student.toString() << "\n";
			return &student;
		}
	}
	return nullptr;
}

bool Library::deleteStudent(const string& idStudent)
{
	auto it = remove_if(this->studentList.begin(), this->studentList.end(),
		[idStudent](Student& student) { return student.getIdStudent() == idStudent; });

	if (it != this->studentList.end())
	{
		this->studentList.erase(it, this->studentList.end());
		cout << "Student with ID \"" << idStudent << "\" deleted successfully.\n";
		ofstream fileOut("Student.txt");

		if (fileOut.is_open()) {
			for (auto& student : this->studentList)
			{
				fileOut << student.toString() << std::endl;
			}
		}
		else {
			std::cerr << "Can not create a file to record." << std::endl;
		}

		fileOut.close();
		return true;
	}
	else
	{
		cout << "No student found with ID \"" << idStudent << "\" in Library " << this->name << "\n";
		return false;
	}
}

