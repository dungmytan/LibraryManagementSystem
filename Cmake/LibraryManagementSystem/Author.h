#pragma once
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <tuple>
#include <Windows.h>
using namespace std;

#include "BasicTypes.h"

class Author
{
private:
    string id;
    string authorName;
    string description;
    list<Author> authorList;

public:
    Author(
        string id,
        string authorName, 
        string description);
    Author() = default;
    string getIdAuthor();
    string toString();

    void setConsoleColor(ConsoleColor textColor, ConsoleColor bgColor);

    bool addAuthor(Author author);
    void readAuthorsFromFile(const string& fileName);
    string readMaxAuthorId();
    Author* searchAuthor(const string& idAuthor);
    bool deleteAuthor(const string& idStudent);
    void getViewAuthor();

    tuple<bool, string, string, string> isAuthorExist( string& authorID);
};

