#include "Category.h"

Category::Category(string categoryId, string categoryName)
{
	this->categoryId = categoryId;
	this->categoryName = categoryName;
}

string Category::toString()
{
	return "Category ID: " + this->categoryId
		+ "\nCategory Name: " + this->categoryName;
}

void Category::setConsoleColor(ConsoleColor textColor, ConsoleColor bgColor)
{
    int color = textColor + bgColor * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}

bool Category::addCategory(Category category)
{
    this->categoryList.push_back(category);
    ofstream fileOut("Category.txt", ios::app);

    if (fileOut.is_open()) {
        fileOut << category.toString() << endl;
    }
    else {
        cerr << "Can not create a file to record." << endl;
    }

    fileOut.close();
    return true;
}

void Category::readCategoriesFromFile(const string& fileName)
{
    ifstream inFile(fileName);

    if (inFile.is_open()) {
        string line;
        string categoryId, categoryName;

        while (getline(inFile, line)) {
            if (line.find("Category ID:") == 0) {
                categoryId = line.substr(13);
            }
            else if (line.find("Category Name:") == 0) {
                categoryName = line.substr(15);
                categoryList.push_back(Category(categoryId, categoryName));
            }
        }

        inFile.close();
    }
    else {
        cout << "Can not open file to read!" << endl;
    }
}

void Category::getViewCategory()
{
    cout << "List of books available at the library:\n";
    for (auto& category : this->categoryList) {
        cout << category.toString() << "\n\n";
    }
}

Category* Category::searchCategory(const string& categoryName)
{
    for (auto& cat : this->categoryList) {
        if (cat.categoryName == categoryName) {
            cout << cat.toString() << "\n";
            return &cat;
        }
    }
    return nullptr;
}

bool Category::deleteCategory(const string& idCategory)
{
    auto it = remove_if(this->categoryList.begin(), this->categoryList.end(),
        [idCategory](Category& student) { return student.getIdCategory() == idCategory; });

    if (it != this->categoryList.end())
    {
        this->categoryList.erase(it, this->categoryList.end());
        setConsoleColor(Green, Black);
        cout << "Author with ID \"" << idCategory << "\" deleted successfully.\n";
        ofstream fileOut("Author.txt");

        if (fileOut.is_open()) {
            for (auto& cat : this->categoryList)
            {
                fileOut << cat.toString() << endl;
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
        cout << "No category found with ID \"" << idCategory << "\" in Library " << "\n";
        return false;
    }
}

bool Category::isCategoryExist(string categoryName)
{
    ifstream inFile("Category.txt");
    if (!inFile.is_open()) {
        cerr << "Could not open the Category file." << std::endl;
        return false;
    }

    string line;
    while (getline(inFile, line)) {
        if (line.find("Category Name:") == 0) {
            string name = line.substr(15);
            if (name == categoryName) {
                inFile.close();
                return true;
            }
        }
    }

    inFile.close();
    return false;
}

string Category::readMaxCategoryId()
{
    string maxId = "0";
    ifstream inFile("Category.txt");

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            // Nếu dòng bắt đầu với "Author ID:"
            if (line.find("Category ID:") == 0) {
                // Lấy id từ dòng và chuyển thành số nguyên
                int id = stoi(line.substr(13));

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

string Category::getIdCategory()
{
    return this->categoryId;
}
