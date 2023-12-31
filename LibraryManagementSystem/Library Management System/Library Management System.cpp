﻿#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
using namespace std;

#include "BasicTypes.h"
#include "Person.h"
#include "Student.h"
#include "Book.h"
#include "Author.h"
#include "PublishingHouse.h"
#include "Library.h"
#include "Staff.h"
#include "Category.h"

void setConsoleColor(ConsoleColor textColor, ConsoleColor bgColor)
{
    int color = textColor + bgColor * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
    Library HSLibrary = Library("Thu vien Thanh Thai");

    int choose;
    int getData = 0, getDataStaff = 0, getDataStudent = 0, getDataAuthor = 0;
    do
    {
        system("cls");
        cout << "======= Menu =======\n";
        cout << "1. Book\n";
        cout << "2. Staff\n";
        cout << "3. Student\n";
        cout << "4. Author\n";
        cout << "5. Category\n";
        cout << "0. Exit\n";
        cout << "====================\n";
        cout << "Choose function: ";
        cin >> choose;
        switch (choose) {
        case 1:
        {
            Book book;
            book.readBooksFromFile("Book.txt");

            int chooseBook;
            string Continue;
            do {
                
                system("cls");
                cout << "===== Menu Book =====\n";
                cout << "1. Get all\n";
                cout << "2. Add\n";
                cout << "3. Search\n";
                cout << "4. Delete\n";
                cout << "0. Back\n";
                cout << "=====================\n";
                cout << "Choose function: ";
                cin >> chooseBook;
                switch (chooseBook)
                {
                case 0:
                    break;
                case 1:
                {
                    book.getViewBook();
                    _getch();
                    break;
                }
                case 2:
                {
                    cout << "Please! Fill down infomation of book that you want to add in system .\n\n";
                    do {
                        string bookId, title, genre, price, publishingHouse, nation, authorId, authorName, description;
                        string maxId, authId;
                        int getMaxId;

                        cout << "Title: ";
                        cin.ignore();
                        getline(cin, title);

                        cout << "Category: ";
                        getline(cin, genre);

                        cout << "Price: ";
                        getline(cin, price);

                        cout << "Publishing house: ";
                        getline(cin, publishingHouse);

                        cout << "Nation:";
                        getline(cin, nation);

                        cout << "Author ID: ";
                        getline(cin, authorId);
                        authId = authorId;

                        //Doc file Book.txt de lay Book ID cao nhat
                        Book book;
                        maxId = book.readMaxBookId();
                        getMaxId = stoi(maxId) + 1;
                        bookId = to_string(getMaxId);

                        Category cat;
                        Author auth;
                        bool isAuthorExist;
                        tie(isAuthorExist, authorId, authorName, description) = auth.isAuthorExist(authorId);

                        if (isAuthorExist)
                        {
                            if (cat.isCategoryExist(genre)) {
                                book.addBook(Book(
                                    bookId, title, genre, stod(price),
                                    PublishingHouse(publishingHouse, nation),
                                    Author(authorId, authorName, description)
                                ));
                            }
                            else {
                                setConsoleColor(Red, White);
                                cout << genre + " category do not exist in system. Please! Try agian." << endl;
                            }
                        }
                        else 
                        {
                            setConsoleColor(Red, White);
                            cout << "Author with id " + authId + " do not exist in system.Please!Try agian." << endl;
                        }
                        setConsoleColor(White, Black);
                        cout << "Do you want to continue to adding more books?(y/n)";
                        cin >> Continue;
                    } while (Continue == "Y" || Continue == "y");
                    break;
                }
                case 3:
                {
                    cout << "Please! Enter book title that you want to find.\n";
                    do {
                        string searchBookName;
                        cout << "Book title: ";
                        cin.ignore();
                        getline(cin, searchBookName);

                        Book* foundBook = book.searchBook(searchBookName);

                        if (foundBook == nullptr) {
                            setConsoleColor(Red, White);
                            cout << "Can not find the book with title is" << searchBookName + "\n" << endl;
                        }
                        setConsoleColor(White, Black);
                        cout << "Do you want to continue searching?(y/n)";
                        cin >> Continue;
                    } while (Continue == "Y" || Continue == "y");
                    break;
                }
                case 4:
                {
                    cout << "Please! Enter book id you want to delete.\n";
                    do {
                        string deleteBookId;
                        cout << "Book ID: ";
                        cin.ignore();
                        getline(cin, deleteBookId);
                        book.deleteBook(deleteBookId);
                        setConsoleColor(White, Black);
                        cout << "Do you want to continue to delete?(y/n)";
                        cin >> Continue;
                    } while (Continue == "Y" || Continue == "y");
                    break;
                }
                default:
                    cout << "Don not have this function. Please, Choose agian!" << endl;
                    _getch();
                }
            } while (chooseBook != 0);
            break;
        }
        case 2:
        {
            Staff stf;

            string Continue;
            int chooseFunction;
            do {
                system("cls");
                cout << "===== Menu Staff =====\n";
                cout << "1. Get all\n";
                cout << "2. Add\n";
                cout << "3. Search\n";
                cout << "4. Delete\n";
                cout << "0. Back\n";
                cout << "======================\n";
                cout << "Choose function: ";
                cin >> chooseFunction;
                switch (chooseFunction)
                {
                case 0:
                    break;
                case 1:
                {
                    if (getDataStaff == 0)
                    {
                        stf.inputStaffFromFile();
                        getDataStaff++;
                    }
                    stf.getViewStaff();
                    _getch();
                    break;
                }  
                case 2:
                {
                    cout << "Please! Fill down infomation of staff that you want to add in system.\n\n";
                    do {
                        string idStaff, name, phone, email, address, ward, district, city;

                        cout << "Staff ID:";
                        cin.ignore();
                        getline(cin, idStaff);

                        cout << "Full name:";
                        getline(cin, name);

                        cout << "Phone number:";
                        getline(cin, phone);

                        cout << "Email:";
                        getline(cin, email);

                        cout << "Address number:";
                        getline(cin, address);

                        cout << "Ward:";
                        getline(cin, ward);

                        cout << "District:";
                        getline(cin, district);

                        cout << "City:";
                        getline(cin, city);

                        stf.addStaff(Staff(idStaff, Person(name, phone, email, Address(address, ward, district, city))));

                        cout << "Do you want to continue to adding more staffs?(y/n)";
                        cin >> Continue;
                    } while (Continue == "Y" || Continue == "y");
                    break;
                }
                case 3:
                {
                    do {
                        string searchIdStaff;
                        cout << "Enter the Staff id you want to search:";
                        cin.ignore();
                        getline(cin, searchIdStaff);
                        stf.searchStaff(searchIdStaff);
                        cout << "Do you want to continue searching?(y/n)";
                        cin >> Continue;
                    } while (Continue == "Y" || Continue == "y");
                    break;
                }
                case 4:
                {
                    do {
                        string deleteIdStaff;
                        cout << "Enter the Staff id you want to delete:";
                        cin.ignore();
                        getline(cin, deleteIdStaff);
                        stf.deleteStaff(deleteIdStaff);
                        setConsoleColor(White, Black);
                        cout << "Do you want to continue to delete?(y/n)";
                        cin >> Continue;
                    } while (Continue == "Y" || Continue == "y");
                    break;
                }
                default:
                    cout << "Don not have this function. Please, Choose agian!" << endl;
                    _getch();
                }
            } while (chooseFunction != 0);
            break;
        }
        case 3:
        {
            Student stu;

            string Continue;
            int chooseFunction;
            do {
                system("cls");
                cout << "===== Menu Student =====\n";
                cout << "1. Get all\n";
                cout << "2. Add\n";
                cout << "3. Search\n";
                cout << "4. Delete\n";
                cout << "0. Back\n";
                cout << "========================\n";
                cout << "Choose function: ";
                cin >> chooseFunction;
                switch (chooseFunction)
                {
                case 0:
                    break;
                case 1:
                {
                    if (getDataStudent == 0)
                    {
                        stu.inputStudentFromFile();
                        getDataStudent++;
                    }
                    stu.getViewStudent();
                    _getch();
                    break;
                }
                case 2:
                {
                    cout << "Please! Fill down infomation of student that you want to add in system.\n\n";
                    do {
                        string idStudent, name, phone, email, major;

                        cout << "Student ID:";
                        cin.ignore();
                        getline(cin, idStudent);

                        cout << "Full name:";
                        getline(cin, name);

                        cout << "Phone number:";
                        getline(cin, phone);

                        cout << "Email:";
                        getline(cin, email);

                        cout << "Majors:";
                        getline(cin, major);

                        stu.addStudent(Student(idStudent, major, Person(name, phone, email)));

                        cout << "Do you want to continue to adding more students?(y/n)";
                        cin >> Continue;
                    } while (Continue == "Y" || Continue == "y");
                    break;
                }
                case 3:
                {
                    do {
                        string searchIdStudent;
                        cout << "Search(ID): ";
                        cin.ignore();
                        getline(cin, searchIdStudent);
                        stu.searchStudent(searchIdStudent);
                        cout << "Do you want to continue searching?(y/n)";
                        cin >> Continue;
                    } while (Continue == "Y" || Continue == "y");
                    break;
                }
                case 4:
                {
                    do {
                        string deleteIdStudent;
                        cout << "Detele student ID: ";
                        cin.ignore();
                        getline(cin, deleteIdStudent);
                        stu.deleteStudent(deleteIdStudent);
                        setConsoleColor(White, Black);
                        cout << "Do you want to continue to delete?(y/n)";
                        cin >> Continue;
                    } while (Continue == "Y" || Continue == "y");
                    break;
                }
                default:
                    cout << "Don not have this function. Please, Choose agian!" << endl;
                    _getch();
                }
            } while (chooseFunction != 0);
            break;
        }
        case 4:
        {
            Author author;
            author.readAuthorsFromFile("Author.txt");
            
            int chooseFunction;
            string Continue;
            do {
                
                system("cls");
                cout << "==== Menu Author ====\n";
                cout << "1. Get all\n";
                cout << "2. Add\n";
                cout << "3. Search\n";
                cout << "4. Delete\n";
                cout << "0. Back\n";
                cout << "=====================\n";
                cout << "Choose function: ";
                cin >> chooseFunction;
                switch (chooseFunction)
                {
                case 0:
                    break;
                case 1:
                {
                    author.getViewAuthor();
                    _getch();
                    break;
                }
                case 2:
                {
                    cout << "Please! Fill down infomation of author that you want to add in system.\n\n";
                    do {
                        string id, MaxId, authorName, description;
                        int getMaxId;

                        cout << "Author name:";
                        cin.ignore();
                        getline(cin, authorName);

                        cout << "Description:";
                        getline(cin, description);

                        //Doc file Author.txt de lay Author id cao nhat
                        MaxId = author.readMaxAuthorId();
                        getMaxId = stoi(MaxId) + 1;
                        id = to_string(getMaxId);

                        author.addAuthor(Author(id, authorName, description));

                        cout << "Do you want to continue adding more authors?(y/n)";
                        cin >> Continue;
                    } while (Continue == "Y" || Continue == "y");
                    break;
                }
                case 3:
                {
                    cout << "Please! Enter author id that you want to find.\n";
                    do {
                        string searchIdAuthor;
                        cout << "Search(ID): ";
                        cin.ignore();
                        getline(cin, searchIdAuthor);
                        Author* foundAuthor = author.searchAuthor(searchIdAuthor);

                        if (foundAuthor == nullptr) {
                            setConsoleColor(Red, White);
                            cout << "Can not find author with id is " << searchIdAuthor + "\n" << endl;
                        }
                        setConsoleColor(White, Black);
                        cout << "Do you want to continue searching?(y/n)";
                        cin >> Continue;
                    } while (Continue == "Y" || Continue == "y");
                    break;
                }
                case 4:
                {
                    do {
                        string deleteIdAuthor;
                        cout << "Delete author id:";
                        cin.ignore();
                        getline(cin, deleteIdAuthor);
                        author.deleteAuthor(deleteIdAuthor);
                        setConsoleColor(White, Black);
                        cout << "Do you want to continue deleting?(y/n)";
                        cin >> Continue;
                    } while (Continue == "Y" || Continue == "y");
                    break;
                }
                }
            } while (chooseFunction != 0);
            break;
        }
        case 5:
        {
            Category category;
            category.readCategoriesFromFile("Category.txt");

            int chooseFunction;
            string Continue;
            do {
                system("cls");
                cout << "==== Menu Category ====\n";
                cout << "1. Get all\n";
                cout << "2. Add\n";
                cout << "3. Search\n";
                cout << "4. Delete\n";
                cout << "0. Back\n";
                cout << "=======================\n";
                cout << "Choose function: ";
                cin >> chooseFunction;
                switch (chooseFunction)
                {
                case 0:
                    break;
                case 1:
                {
                    category.getViewCategory();
                    _getch();
                    break;
                }
                case 2:
                {
                    cout << "Please! Fill down infomation of Category that you want to add in system.\n\n";
                    do {
                        string categoryId, MaxId, categoryName;
                        int getMaxId;

                        cout << "Category: ";
                        cin.ignore();
                        getline(cin, categoryName);

                        //Doc file Category.txt de lay CategoryId cao nhat
                        MaxId = category.readMaxCategoryId();
                        getMaxId = stoi(MaxId) + 1;
                        categoryId = to_string(getMaxId);

                        category.addCategory(Category(categoryId, categoryName));

                        cout << "Do you want to continue adding more categories?(y/n)";
                        cin >> Continue;
                    } while (Continue == "Y" || Continue == "y");
                    break;
                }
                case 3:
                {
                    cout << "Please! Enter category name that you want to find.\n";
                    do {
                        string searchCategoryName;
                        cout << "Search(Name):";
                        cin.ignore();
                        getline(cin, searchCategoryName);

                        Category* foundCategory = category.searchCategory(searchCategoryName);

                        if (foundCategory == nullptr) {
                            cout << "Can not find " << searchCategoryName + " categoty\n" << endl;
                        }

                        cout << "Do you want to continue searching?(y/n)";
                        cin >> Continue;
                    } while (Continue == "Y" || Continue == "y");
                    break;
                }
                case 4:
                {
                    string Continue;
                    do {
                        string deleteCategoryId;
                        cout << "Delete with category id:";
                        cin.ignore();
                        getline(cin, deleteCategoryId);
                        category.deleteCategory(deleteCategoryId);
                        setConsoleColor(White, Black);
                        cout << "Do you want to continue deleting?(y/n)";
                        cin >> Continue;
                    } while (Continue == "Y" || Continue == "y");
                    break;
                }
                }
            } while (chooseFunction != 0);
            break;
        }
        default:
            cout << "Do not have this function. Please, Choose agian!" << endl;
            _getch();
        }
    }while (choose != 0);
} 