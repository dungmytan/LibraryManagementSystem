#pragma once
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <cstdio>
using namespace std;

#include "BasicTypes.h"
#include "PublishingHouse.h"
#include "Author.h"
#include "RentingBook.h"

class Book
{
public:
	string bookId;
	string title;
	GenderBook type;
	Author author;
	double priceRending;
	PublishingHouse publishingHouse;
	
	list<RentingBook> bookingList;

public:
	Book(
		string bookId,
		string title,
		GenderBook type,
		double priceRending,
		PublishingHouse publishingHouse,
		Author author
		
	);
	string genderBookToString(GenderBook gender);
	Book() = default;
	string toString();
	string bookingListToString();
	string getBookId();
	string getTitle();
};

