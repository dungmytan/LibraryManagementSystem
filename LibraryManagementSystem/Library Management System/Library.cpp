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


// ============= Book ============= //

//list<Book> Library::getBook()
//{
//	return this->bookList;
//}
//
//bool Library::addBook(Book book)
//{
//	this->bookList.push_back(book);
//	ofstream fileOut("Book.txt", std::ios::app);
//
//	if (fileOut.is_open()) {
//		fileOut << book.toString() << std::endl;
//	}
//	else {
//		std::cerr << "Khong the mo file de ghi." << std::endl;
//	}
//
//	fileOut.close();
//	return true;
//}
//
//void Library::inputFromFile()
//{
//	std::ifstream fileIn("Book.txt");
//	std::string line, space;
//	Book book;
//	if (!fileIn.is_open()) {
//		std::cerr << "Khong the mo file de doc." << std::endl;
//		return;
//	}
//	std::string typeBook;
//
//	while (!fileIn.eof())
//	{
//		while (getline(fileIn, line)) {
//			std::istringstream iss(line);
//			std::string key;
//
//			getline(iss, key, ':');
//
//			if (key == "Book ID") {
//				if (book.bookId != "")
//				{
//					this->bookList.push_back(book);
//					book = Book();
//				}
//				getline(iss, space, ' ');
//				space = "";
//				getline(iss, book.bookId);
//			}
//			else if (key == "Title") {
//				getline(iss, space, ' ');
//				space = "";
//				getline(iss, book.title);
//			}
//			else if (key == "Gender") {
//				getline(iss, space, ' ');
//				space = "";
//				getline(iss, typeBook);
//				if (typeBook == "Novel")
//					book.type = GenderBook::Novel;
//				else if (typeBook == "Comic")
//					book.type = GenderBook::Comic;
//				else if (typeBook == "Poem")
//					book.type = GenderBook::Poem;
//				else if (typeBook == "Autobiography")
//					book.type = GenderBook::Autobiography;
//				else if (typeBook == "Encyclopedia")
//					book.type = GenderBook::Encyclopedia;
//				else if (typeBook == "Thriller")
//					book.type = GenderBook::Thriller;
//				else if (typeBook == "Cookery")
//					book.type = GenderBook::Cookery;
//			}
//			else if (key == "Price") {
//				getline(iss, space, ' ');
//				space = "";
//				std::string price;
//				getline(iss, price,'.');
//				price = price + "000";
//				book.priceRending = std::stod(price);
//			}
//			else if (key == "Publishing house") {
//				getline(iss, space, ' ');
//				space = "";
//				getline(iss, book.publishingHouse.name);
//			}
//			else if (key == "Nation") {
//				getline(iss, space, ' ');
//				space = "";
//				getline(iss, book.publishingHouse.nation);
//			}
//			else if (key == "Author") {
//				getline(iss, space, ' ');
//				space = "";
//				getline(iss, book.author.authorName);
//			}
//			else if (key == "Description") {
//				getline(iss, space, ' ');
//				space = "";
//				getline(iss, book.author.description);
//			}
//		}
//		if (book.bookId != "")
//			this->bookList.push_back(book);
//	}
//	fileIn.close();
//}
//
//void Library::getViewBook()
//{
//	cout << "Books in Library " << this->name << ":\n";
//
//	for (auto &book : this->bookList)
//	{
//		cout << book.toString() << "\n\n";
//	}
//}
//
//Book* Library::searchBook(const string& title)
//{
//	for (auto& book : this->bookList)
//	{
//		if (book.getTitle() == title)
//		{
//			cout << book.toString() << "\n";
//			return &book;
//		}
//	}
//	return nullptr;
//}
//
//bool Library::deleteBook(const string& bookId)
//{
//	auto it = remove_if(this->bookList.begin(), this->bookList.end(),
//		[bookId](Book& book) { return book.getBookId() == bookId; });
//	
//	if (it != this->bookList.end())
//	{
//		this->bookList.erase(it, this->bookList.end());
//		cout << "Book with ID \"" << bookId << "\" deleted successfully.\n";
//		ofstream fileOut("Book.txt");
//
//		if (fileOut.is_open()) {
//			for (auto& book : this->bookList)
//			{
//				fileOut << book.toString() << std::endl;
//			}
//		}
//		else {
//			std::cerr << "Khong the mo file de ghi." << std::endl;
//		}
//
//		fileOut.close();
//		return true;
//	}
//	else
//	{
//		cout << "No books found with ID \"" << bookId << "\" in Library " << this->name << "\n";
//		return false;
//	}
//}


// ============= Staff ============= //

list<Staff> Library::getStaff()
{
	return this->staffList;
}

bool Library::addStaff(Staff staff)
{
	this->staffList.push_back(staff);
	ofstream fileOut("Staff.txt", std::ios::app);

	if (fileOut.is_open()) {
		fileOut << staff.toString() << std::endl;
	}
	else {
		std::cerr << "Khong the mo file de ghi." << std::endl;
	}

	fileOut.close();
	return true;
}

void Library::inputStaffFromFile()
{
	std::ifstream fileIn("Staff.txt");
	std::string line, space;
	Staff staff;
	if (!fileIn.is_open()) {
		std::cerr << "Khong the mo file de doc." << std::endl;
		return;
	}

	while (!fileIn.eof())
	{
		while (getline(fileIn, line)) {
			std::istringstream iss(line);
			std::string key;

			getline(iss, key, ':');

			if (key == "ID") {
				if (staff.idStaff != "")
				{
					this->staffList.push_back(staff);
					staff = Staff();
				}
				getline(iss, space, ' ');
				space = "";
				getline(iss, staff.idStaff);
			}
			else if (key == "Name") {
				getline(iss, space, ' ');
				space = "";
				getline(iss, staff.name);
			}
			else if (key == "Phone") {
				getline(iss, space, ' ');
				space = "";
				getline(iss, staff.phone);
			}
			else if (key == "Email") {
				getline(iss, space, ' ');
				space = "";
				getline(iss, staff.email);
			}
			else if (key == "Address") {
				getline(iss, space, ' ');
				space = "";
				getline(iss, staff.address.streetAddress, '/');
				getline(iss, space, '.');
				space = "";
				getline(iss, staff.address.ward, '/');
				getline(iss, space, '.');
				space = "";
				getline(iss, staff.address.district, '/');
				getline(iss, space, '.');
				space = "";
				getline(iss, staff.address.city);
			}

		}
		if (staff.idStaff != "")
			this->staffList.push_back(staff);
	}
	fileIn.close();
}

void Library::getViewStaff()
{
	cout << "Staffs in Library " << this->name << ":\n";

	for (auto& staff : this->staffList)
	{
		cout << staff.toString() << "\n\n";
	}
}

Staff* Library::searchStaff(const string& idStaff)
{
	for (auto& staff : this->staffList)
	{
		if (staff.getIdStaff() == idStaff)
		{
			cout << staff.toString() << "\n";
			return &staff;
		}
	}
	return nullptr;
}

bool Library::deleteStaff(const string& idStaff)
{
	auto it = remove_if(this->staffList.begin(), this->staffList.end(),
		[idStaff](Staff& staff) { return staff.getIdStaff() == idStaff; });

	if (it != this->staffList.end())
	{
		this->staffList.erase(it, this->staffList.end());
		cout << "Staff with ID \"" << idStaff << "\" deleted successfully.\n";
		ofstream fileOut("Staff.txt");

		if (fileOut.is_open()) {
			for (auto& staff : this->staffList)
			{
				fileOut << staff.toString() << std::endl;
			}
		}
		else {
			std::cerr << "Khong the mo file de ghi." << std::endl;
		}

		fileOut.close();
		return true;
	}
	else
	{
		cout << "No staff found with ID \"" << idStaff << "\" in Library " << this->name << "\n";
		return false;
	}
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
		std::cerr << "Khong the mo file de ghi." << std::endl;
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
		std::cerr << "Khong the mo file de doc." << std::endl;
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
			std::cerr << "Khong the mo file de ghi." << std::endl;
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

