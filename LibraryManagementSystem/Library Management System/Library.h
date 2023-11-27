#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

#include "Book.h"
#include "Staff.h"
#include "Student.h"

class Library
{
private:
	string name;
	list<Book> bookList;
	list<Student> studentList;
	
public:
	// Library
	Library(string name);
	string toString();

	//Student
	list<Student> getStudent();
	bool addStudent(Student student);
	void inputStudentFromFile();
	void getViewStudent();
	Student* searchStudent(const string& idStudent);
	bool deleteStudent(const string& idStudent);
};

