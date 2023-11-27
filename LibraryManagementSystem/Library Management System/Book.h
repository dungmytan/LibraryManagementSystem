#pragma once
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <cstdio>
#include <iomanip>
#include <Windows.h>
using namespace std;

#include "BasicTypes.h"
#include "PublishingHouse.h"
#include "Author.h"

class Book
{
private:
	string bookId;
	string title;
	string type;
	Author author;
	double priceRenting;
	PublishingHouse publishingHouse;
	
	list <Book> bookList;

public:
	Book(
		string bookId,
		string title,
		string type,
		double priceRenting,
		PublishingHouse publishingHouse,
		Author author		
	);
	Book() = default;
	string toString();

	string getBookId();
	string getTitle();

	void setConsoleColor(ConsoleColor textColor, ConsoleColor bgColor);

	void readBooksFromFile(const string& fileName);
	void getViewBook();
	string readMaxBookId();
	bool addBook(Book book);
	Book* searchBook(const string& bookName);
	bool deleteBook(const string& idBook);
};

