#include "Book.h"

Book::Book(string bookId, string title, GenderBook type, double priceRending, PublishingHouse publishingHouse, Author author)
{
	this->bookId = bookId;
	this->title = title;
	this->type = type;
	this->priceRending = priceRending;
	this->publishingHouse = publishingHouse;
	this->author = author;
}

string Book::genderBookToString(GenderBook gender)
{
	static const std::map<GenderBook, std::string> genderMap = {
		{GenderBook::Novel, "Novel"},
		{GenderBook::Comic, "Comic"},
		{GenderBook::Poem, "Poem"},
		{GenderBook::Autobiography, "Autobiography"},
		{GenderBook::Encyclopedia, "Encyclopedia"},
		{GenderBook::Thriller, "Thriller"},
		{GenderBook::Cookery, "Cookery"} };

	auto it = genderMap.find(gender);
	if (it != genderMap.end())
	{
		return it->second;
	}
	return "Unknown";
}

string Book::toString()
{
	int priceInThousands = static_cast<int>(this->priceRending / 1000);
	int priceRemainder = static_cast<int>(this->priceRending) % 1000;

	char priceString[20]; // Đảm bảo đủ kích thước để chứa giá và định dạng mong muốn
	snprintf(priceString, sizeof(priceString), "%d.%03d vnd", priceInThousands, priceRemainder);

	return "Book ID: " + this->bookId
		+ "\nTitle: " + this->title
		+ "\nGender: " + genderBookToString(this->type)
		+ "\nPrice: " + priceString
		+ "\n" + this->publishingHouse.toString()
		+ "\n" + this->author.toString(); 
}

string Book::bookingListToString()
{
	string str =
		"Book: " + this->bookId
		+ " - " + "Price: " + to_string(this->priceRending);
	
	for (auto booking : bookingList)
	{
		str = str + "\n\r\t" + booking.toString();
	}

	return str;
}

string Book::getBookId()
{
	return this->bookId;
}

string Book::getTitle()
{
	return this->title;
}
