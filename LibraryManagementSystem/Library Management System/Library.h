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
	list<Staff> staffList;
	list<Student> studentList;
	list<Author> authorList;
	
public:
	// Library
	Library(string name);
	string toString();

	//Book
	list<Book> getBook();
	bool addBook(Book book);
	void inputFromFile();
	void getViewBook();
	Book* searchBook(const string& title);
	bool deleteBook(const string& bookId);

	//Staff
	list<Staff> getStaff();
	bool addStaff(Staff staff);
	void inputStaffFromFile();
	void getViewStaff();
	Staff* searchStaff(const string& idStaff);
	bool deleteStaff(const string& idStaff);

	//Student
	list<Student> getStudent();
	bool addStudent(Student student);
	void inputStudentFromFile();
	void getViewStudent();
	Student* searchStudent(const string& idStudent);
	bool deleteStudent(const string& idStudent);
};

