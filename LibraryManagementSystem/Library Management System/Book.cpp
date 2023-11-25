#include "Book.h"

Book::Book(string bookId, string title, string type, double priceRending, PublishingHouse publishingHouse, Author author)
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
		+ "\nGender: " + this->type
		+ "\nPrice: " + priceString
		+ "\n" + this->publishingHouse.toString()
		+ "\n" + this->author.toString(); 
}

//string Book::toStringFromFlie()
//{
//    // Chuyển giá trị double thành chuỗi
//    string priceString = to_string(this->priceRending);
//
//    // Tìm vị trí của dấu chấm thập phân
//    size_t dotPosition = priceString.find('.');
//
//    // Nếu không có dấu chấm thập phân, thêm ".000" vào cuối chuỗi
//    if (dotPosition == string::npos) {
//        priceString += ".000";
//    }
//    else {
//        // Nếu có dấu chấm thập phân, thêm các số '0' nếu cần thiết
//        size_t decimalPartLength = priceString.length() - dotPosition - 1;
//        if (decimalPartLength < 3) {
//            priceString += std::string(3 - decimalPartLength, '0');
//        }
//    }
//
//    // Định dạng giá trị thành chuỗi theo định dạng mong muốn
//    return "Book ID: " + this->bookId +
//        "\nTitle: " + this->title +
//        "\nGender: " + this->type +
//        "\nPrice: " + priceString +
//        "\n" + this->publishingHouse.toString() +
//        "\n" + this->author.toString();
//}

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

void Book::readBooksFromFile(const string& fileName)
{
    ifstream inFile(fileName);

    if (inFile.is_open()) {
        string line;
        string bookId, title, gender, priceStr, publishingHouse, nation, authorId, authorName, description;
        double price;

        while (getline(inFile, line)) {
            if (line.find("Book ID:") == 0 && line.length() >= 8) {
                bookId = line.substr(9);
            }
            else if (line.find("Title:") == 0) {
                title = line.substr(7);
            }
            else if (line.find("Gender:") == 0) {
                gender = line.substr(8);
            }
            else if (line.find("Price:") == 0) {
                // Loại bỏ "vnd" và khoảng trắng từ giá trị và chuyển đổi sang double
                priceStr = line.substr(7);

                priceStr.erase(remove(priceStr.begin(), priceStr.end(), ' '), priceStr.end());
                priceStr.erase(remove(priceStr.begin(), priceStr.end(), 'v'), priceStr.end());
                priceStr.erase(remove(priceStr.begin(), priceStr.end(), 'n'), priceStr.end());
                priceStr.erase(remove(priceStr.begin(), priceStr.end(), 'd'), priceStr.end());
                price = stod(priceStr);
            }
            else if (line.find("Publishing house:") == 0) {
                publishingHouse = line.substr(18);
            }
            else if (line.find("Nation:") == 0) {
                nation = line.substr(8);
            }
            else if (line.find("Author ID:") == 0 && line.length() >= 10) {
                authorId = line.substr(11);
            }
            else if (line.find("Author:") == 0) {
                authorName = line.substr(8);
            }
            else if (line.find("Description:") == 0) {
                description = line.substr(13);

                // Thêm vào danh sách
                bookList.push_back(Book(
                    bookId, title, gender, stod(priceStr),
                    PublishingHouse(publishingHouse, nation),
                    Author(authorId, authorName, description)
                ));
            }
        }

        inFile.close();
    }
    else {
        cout << "Can not open file and read!" << endl;
    }
}


void Book::getViewBook()
{
	cout << "Danh sach:\n";
	for (auto& book : this->bookList) {
		cout << book.toString() << "\n\n";
	}
}
