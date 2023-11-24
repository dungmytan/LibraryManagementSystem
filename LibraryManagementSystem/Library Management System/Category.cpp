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

bool Category::addCategory(Category category)
{
    this->categoryList.push_back(category);
    ofstream fileOut("Category.txt", ios::app);

    if (fileOut.is_open()) {
        fileOut << category.toString() << endl;
    }
    else {
        cerr << "Khong the mo file de ghi." << endl;
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
        cout << "Khong the mo file de doc!" << endl;
    }
}

void Category::getViewCategory()
{
    cout << "Danh sach cac loai sach hien co tai thu vien:\n";
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
        cout << "Author with ID \"" << idCategory << "\" deleted successfully.\n";
        ofstream fileOut("Author.txt");

        if (fileOut.is_open()) {
            for (auto& cat : this->categoryList)
            {
                fileOut << cat.toString() << endl;
            }
        }
        else {
            cerr << "Khong the mo file de ghi." << endl;
        }

        fileOut.close();
        return true;
    }
    else
    {
        cout << "No category found with ID \"" << idCategory << "\" in Library " << "\n";
        return false;
    }
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
