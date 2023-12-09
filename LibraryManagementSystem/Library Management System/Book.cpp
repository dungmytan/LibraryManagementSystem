#include "Book.h"

Book::Book(string bookId, string title, string type, double priceRenting, PublishingHouse publishingHouse, Author author)
{
	this->bookId = bookId;
	this->title = title;
	this->type = type;
	this->priceRenting = priceRenting;
	this->publishingHouse = publishingHouse;
	this->author = author;
}

string Book::toString()
{
    ostringstream priceStream;
    priceStream << fixed << setprecision(2) << this->priceRenting;

	return "Book ID: " + this->bookId
		+ "\nTitle: " + this->title
		+ "\nGender: " + this->type
		+ "\nPrice: " + priceStream.str() + " vnd"
		+ "\n" + this->publishingHouse.toString()
		+ "\n" + this->author.toString(); 
}

string Book::getBookId()
{
	return this->bookId;
}

string Book::getTitle()
{
	return this->title;
}

void Book::setConsoleColor(ConsoleColor textColor, ConsoleColor bgColor)
{
    int color = textColor + bgColor * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);   
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
    cout << "\n========== BOOK LIST ==========\n";
	for (auto& book : this->bookList) {
		cout << book.toString() << "\n\n";
	}
}

string Book::readMaxBookId()
{
    string maxId = "0";
    ifstream inFile("Book.txt");

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            // Nếu dòng bắt đầu với "Author ID:"
            if (line.find("Book ID:") == 0) {
                // Lấy id từ dòng và chuyển thành số nguyên
                int id = stoi(line.substr(9));

                // Kiểm tra nếu id lớn hơn maxId
                if (id > stoi(maxId)) {
                    maxId = to_string(id);
                }
            }
        }

        inFile.close();
    }

    return maxId;
}

bool Book::addBook(Book book)
{
    this->bookList.push_back(book);
    ofstream fileOut("Book.txt", ios::app);

    if (fileOut.is_open()) {
        fileOut << book.toString() << endl;
    }
    else {
        cerr << "Can not open file and write." << endl;
    }

    fileOut.close();
    return true;
}

Book* Book::searchBook(const string& bookName)
{
    for (auto& book : this->bookList) {
        if (book.title == bookName) {
            cout << book.toString() << "\n";
            return &book;
        }
    }
    return nullptr;
}

bool Book::deleteBook(const string& idBook)
{
    auto it = remove_if(this->bookList.begin(), this->bookList.end(),
        [idBook](Book& student) { return student.getBookId() == idBook; });

    if (it != this->bookList.end())
    {
        this->bookList.erase(it, this->bookList.end());
        setConsoleColor(Green, Black);
        cout << "Book with ID \"" << idBook << "\" deleted successfully.\n";
        ofstream fileOut("Book.txt");

        if (fileOut.is_open()) {
            for (auto& book : this->bookList)
            {
                fileOut << book.toString() << endl;
            }
        }
        else {
            cerr << "Can not open file and write." << endl;
        }

        fileOut.close();
        return true;
    }
    else
    {
        setConsoleColor(Red, White);
        cout << "No book found with ID \"" << idBook << "\" in Library " << "\n";
        return false;
    }
}
