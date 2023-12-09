#include "Author.h"

Author::Author(string id, string authorName, string description)
{
	this->id = id;
	this->authorName = authorName;
	this->description = description;
}

string Author::toString()
{
	return "Author ID: " + this->id
		+ "\nAuthor: " + this->authorName
		+ "\nDescription: " + this->description;
}

void Author::setConsoleColor(ConsoleColor textColor, ConsoleColor bgColor)
{
    int color = textColor + bgColor * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);   
}

bool Author::addAuthor(Author author)
{
    this->authorList.push_back(author);
    ofstream fileOut("Author.txt", ios::app);

    if (fileOut.is_open()) {
        fileOut << author.toString() << endl;
    }
    else {
        cerr << "Can not create a file to record." << endl;
    }

    fileOut.close();
    return true;
}

void Author::readAuthorsFromFile(const string& fileName)
{
    ifstream inFile(fileName);

    if (inFile.is_open()) {
        string line;
        string id, authorName, description;

        while (getline(inFile, line)) {
            if (line.find("Author ID:") == 0) {
                id = line.substr(11);
            }
            else if (line.find("Author:") == 0) {
                authorName = line.substr(8);
            }
            else if (line.find("Description:") == 0) {
                description = line.substr(13);
                // Thêm tác giả vào danh sách
                authorList.push_back(Author(id, authorName, description));
            }
        }

        inFile.close();
    }
    else {
        cout << "Can not open file and read!" << endl;
    }
}

string Author::readMaxAuthorId()
{
    string maxId = "0";
    ifstream inFile("Author.txt");

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            // Nếu dòng bắt đầu với "Author ID:"
            if (line.find("Author ID:") == 0) {
                // Lấy id từ dòng và chuyển thành số nguyên
                int id = stoi(line.substr(11));

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

Author* Author::searchAuthor(const string& idAuthor)
{
    for (auto& author : this->authorList) {
        if (author.id == idAuthor) {
            cout << author.toString() << "\n";
            return &author;
        }
    }
    return nullptr;
}

string Author::getIdAuthor()
{
    return this->id;
}

bool Author::deleteAuthor(const string& idAuthor)
{
    auto it = remove_if(this->authorList.begin(), this->authorList.end(),
        [idAuthor](Author& student) { return student.getIdAuthor() == idAuthor; });

    if (it != this->authorList.end())
    {
        this->authorList.erase(it, this->authorList.end());
        setConsoleColor(Green, Black);
        cout << "Author with ID \"" << idAuthor << "\" deleted successfully.\n";
        ofstream fileOut("Author.txt");

        if (fileOut.is_open()) {
            for (auto& author : this->authorList)
            {
                fileOut << author.toString() << endl;
            }
        }
        else {
            cerr << "Can not create a file to record." << endl;
        }

        fileOut.close();
        return true;
    }
    else
    {
        setConsoleColor(Red, White);
        cout << "No author found with ID \"" << idAuthor << "\" in Library " << "\n";
        return false;
    }
}

void Author::getViewAuthor()
{
    cout << "Author list:\n";
    for (auto& author : this->authorList) {
        cout << author.toString() << "\n\n";
    }
}

tuple<bool, string, string, string> Author::isAuthorExist(string& authorID)
{
    ifstream inFile("Author.txt");
    if (!inFile.is_open()) {
        cerr << "Could not open the Author file." << endl;
        return { false, "", "", "" };
    }

    string line;
    while (getline(inFile, line)) {
        if (line.find("Author ID:") == 0) {
            string id = line.substr(11);
            if (id == authorID) {
                // Đọc Author Name
                if (!getline(inFile, line) || line.find("Author:") != 0) {
                    inFile.close();
                    return { false, "", "", "" };
                }
                string name = line.substr(8);

                // Đọc Description
                if (!getline(inFile, line) || line.find("Description:") != 0) {
                    inFile.close();
                    return { false, "", "", "" };
                }
                string description = line.substr(13);

                inFile.close();
                return { true, authorID, name, description };
            }
        }
    }

    inFile.close();
    return { false, "", "", "" };
}
