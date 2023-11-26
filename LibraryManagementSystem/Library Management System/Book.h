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
#include "RentingBook.h"

class Book
{
private:
	string bookId;
	string title;
	string type;
	Author author;
	double priceRending;
	PublishingHouse publishingHouse;
	
	list<RentingBook> bookingList;
	list <Book> bookList;

public:
	Book(
		string bookId,
		string title,
		string type,
		double priceRending,
		PublishingHouse publishingHouse,
		Author author		
	);
	Book() = default;
	string toString();
	string bookingListToString();

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

