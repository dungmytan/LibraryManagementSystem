#pragma once
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

#include "BasicTypes.h"

class Category
{
private:
	string categoryId;
	string categoryName;
	list<Category> categoryList;

public:
	Category(string categoryId, string categoryName);
	string toString();
	Category() = default;

	void setConsoleColor(ConsoleColor textColor, ConsoleColor bgColor);

	// Function
	bool addCategory(Category category);
	void readCategoriesFromFile(const string& fileName);
	void getViewCategory();
	Category* searchCategory(const string& categoryName);
	bool deleteCategory(const string& idCategory);
	bool isCategoryExist(string categoryName);

	string readMaxCategoryId();
	string getIdCategory();
};

