#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <conio.h>
using namespace std;

#include "Person.h"
#include "Student.h"
#include "Book.h"
#include "Author.h"
#include "PublishingHouse.h"
#include "Library.h"
#include "Staff.h"
#include "Category.h"

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
        cout << "Chon chuc nang: ";
        cin >> choose;
        switch (choose) {
        case 1:
        {
            Book book;
            book.readBooksFromFile("Book.txt");

            int chooseBook;
            string chooseBookContinue;
            do {
                
                system("cls");
                cout << "===== Menu Book =====\n";
                cout << "1. Get all\n";
                cout << "2. Add\n";
                cout << "3. Search\n";
                cout << "4. Delete\n";
                cout << "0. Back\n";
                cout << "=====================\n";
                cout << "Chon chuc nang: ";
                cin >> chooseBook;
                switch (chooseBook)
                {
                case 1:
                {
                    book.getViewBook();
                    _getch();
                    break;
                }
                case 2:
                {
                    string addAuthorContinue;
                    do {
                        string bookId, title, gender, price, publishingHouse, nation, authorId, authorName, description;
                        string maxId;
                        int getMaxId;

                        cout << "Ten sach: ";
                        cin.ignore();
                        getline(cin, title);

                        cout << "Loai sach: ";
                        getline(cin, gender);

                        cout << "Gia thue: ";
                        getline(cin, price);

                        cout << "Nha xuat ban: ";
                        getline(cin, publishingHouse);

                        cout << "Quoc gia:";
                        getline(cin, nation);

                        cout << "Ma tac gia: ";
                        getline(cin, authorId);

                        cout << "Ten tac gia:";
                        getline(cin, authorName);

                        cout << "Mo ta: ";
                        getline(cin, description);

                        //Doc file Author.txt de lay Author id cao nhat
                        Book book;
                        maxId = book.readMaxBookId();
                        getMaxId = stoi(maxId) + 1;
                        bookId = to_string(getMaxId);

                        book.addBook(Book(
                            bookId, title, gender, stod(price),
                            PublishingHouse(publishingHouse, nation),
                            Author(authorId, authorName, description)
                        ));

                        cout << "Ban co muon them tac gia tiep khong?(y/n)";
                        cin >> addAuthorContinue;
                    } while (addAuthorContinue == "Y" || addAuthorContinue == "y");
                    break;



                    /*string addBookContinue;
                    do {
                        string idBook, titleBook, publishingHouseName, publishingHouseNation, authorName, authorDescription;
                        double priceRenting;

                        cout << "Nhap id book:";
                        cin.ignore();
                        getline(cin, idBook);

                        cout << "Nhap tua sach:";
                        getline(cin, titleBook);

                        cout << "Nhap gia thue:";
                        cin >> priceRenting;

                        cout << "Nhap ten nha xuat ban:";
                        cin.ignore();
                        getline(cin, publishingHouseName);

                        cout << "Nhap quoc gia:";
                        getline(cin, publishingHouseNation);

                        cout << "Nhap ten tac gia:";
                        getline(cin, authorName);

                        cout << "Nhap mo ta tac gia:";
                        getline(cin, authorDescription);

                        int chooseType;
                        cout << "Cac loai sach:\n";
                        cout << "1. Novel\n";
                        cout << "2. Comic\n";
                        cout << "3. Poem\n";
                        cout << "4. Autobiography\n";
                        cout << "5. Encyclopedia\n";
                        cout << "6. Thriller\n";
                        cout << "7. Cookery\n";
                        cout << "Chon loai sach:";
                        cin >> chooseType;

                        switch (chooseType) {
                        case 1:
                            HSLibrary.addBook(Book(idBook, titleBook, GenderBook::Novel, priceRenting, PublishingHouse(publishingHouseName, publishingHouseNation), Author(authorName, authorDescription)));
                            HSLibrary.addAuthor(Author(authorName, authorDescription));
                            break;
                        case 2:
                            HSLibrary.addBook(Book(idBook, titleBook, GenderBook::Comic, priceRenting, PublishingHouse(publishingHouseName, publishingHouseNation), Author(authorName, authorDescription)));
                            HSLibrary.addAuthor(Author(authorName, authorDescription));
                            break;
                        case 3:
                            HSLibrary.addBook(Book(idBook, titleBook, GenderBook::Poem, priceRenting, PublishingHouse(publishingHouseName, publishingHouseNation), Author(authorName, authorDescription)));
                            HSLibrary.addAuthor(Author(authorName, authorDescription));
                            break;
                        case 4:
                            HSLibrary.addBook(Book(idBook, titleBook, GenderBook::Autobiography, priceRenting, PublishingHouse(publishingHouseName, publishingHouseNation), Author(authorName, authorDescription)));
                            HSLibrary.addAuthor(Author(authorName, authorDescription));
                            break;
                        case 5:
                            HSLibrary.addBook(Book(idBook, titleBook, GenderBook::Encyclopedia, priceRenting, PublishingHouse(publishingHouseName, publishingHouseNation), Author(authorName, authorDescription)));
                            HSLibrary.addAuthor(Author(authorName, authorDescription));
                            break;
                        case 6:
                            HSLibrary.addBook(Book(idBook, titleBook, GenderBook::Thriller, priceRenting, PublishingHouse(publishingHouseName, publishingHouseNation), Author(authorName, authorDescription)));
                            HSLibrary.addAuthor(Author(authorName, authorDescription));
                            break;
                        case 7:
                            HSLibrary.addBook(Book(idBook, titleBook, GenderBook::Cookery, priceRenting, PublishingHouse(publishingHouseName, publishingHouseNation), Author(authorName, authorDescription)));
                            HSLibrary.addAuthor(Author(authorName, authorDescription));
                            break;
                        }

                        cout << "Ban co muon them sach tiep khong?(Yes/No)";
                        cin >> addBookContinue;
                    } while (addBookContinue == "Yes" || addBookContinue == "yes");
                    HSLibrary.getViewBook();
                    break;*/
                }
                case 3:
                {
                    string Continue;
                    do {
                        string searchBookName;
                        cout << "Nhap ten danh muc muon tim kiem:";
                        cin.ignore();
                        getline(cin, searchBookName);

                        Book* foundBook = book.searchBook(searchBookName);

                        if (foundBook == nullptr) {
                            cout << "Khong tim thay danh muc co ten: " << searchBookName + "\n" << endl;
                        }

                        cout << "Ban co muon tim kiem tiep khong?(y/n)";
                        cin >> Continue;
                    } while (Continue == "Y" || Continue == "y");
                    break;
                }
                case 4:
                {
                    string Continue;
                    do {
                        string deleteBookId;
                        cout << "Nhap category id muon xoa:";
                        cin.ignore();
                        getline(cin, deleteBookId);
                        book.deleteBook(deleteBookId);
                        cout << "Ban co muon xoa tiep khong?(y/n)";
                        cin >> Continue;
                    } while (Continue == "Y" || Continue == "y");
                    HSLibrary.getViewStudent();
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
            string chooseStaffContinue;
            do {
                int chooseStaff;
                system("cls");
                cout << "===== Menu Staff =====\n";
                cout << "1. Get all\n";
                cout << "2. Add\n";
                cout << "3. Search\n";
                cout << "4. Delete\n";
                cout << "======================\n";
                cout << "Chon chuc nang: ";
                cin >> chooseStaff;
                switch (chooseStaff)
                {
                case 1:
                    if (getDataStaff == 0)
                    {
                        HSLibrary.inputStaffFromFile();
                        getDataStaff++;
                    }
                    HSLibrary.getViewStaff();
                    break;
                case 2:
                {
                    string addStaffContinue;
                    do {
                        string idStaff, name, phone, email, address, ward, district, city;

                        cout << "Nhap id staff:";
                        cin.ignore();
                        getline(cin, idStaff);

                        cout << "Nhap ho ten:";
                        getline(cin, name);

                        cout << "Nhap so dien thoai:";
                        getline(cin, phone);

                        cout << "Nhap email:";
                        getline(cin, email);

                        cout << "Nhap dia chi:";
                        getline(cin, address);

                        cout << "Nhap ward:";
                        getline(cin, ward);

                        cout << "Nhap district:";
                        getline(cin, district);

                        cout << "Nhap city:";
                        getline(cin, city);

                        HSLibrary.addStaff(Staff(idStaff, Person(name, phone, email, Address(address, ward, district, city))));

                        cout << "Ban co muon them sach tiep khong?(Yes/No)";
                        cin >> addStaffContinue;
                    } while (addStaffContinue == "Yes" || addStaffContinue == "yes");
                    break;
                }
                case 3:
                {
                    string searchStaffContinue;
                    do {
                        string searchIdStaff;
                        cout << "Nhap id nhan vien muon tim kiem:";
                        cin.ignore();
                        getline(cin, searchIdStaff);
                        HSLibrary.searchStaff(searchIdStaff);
                        cout << "Ban co muon tim nhan vien tiep khong?(Yes/No)";
                        cin >> searchStaffContinue;
                    } while (searchStaffContinue == "Yes" || searchStaffContinue == "yes");
                    break;
                }
                case 4:
                {
                    string deleteStaffContinue;
                    do {
                        string deleteIdStaff;
                        cout << "Nhap id staff muon xoa:";
                        cin.ignore();
                        getline(cin, deleteIdStaff);
                        HSLibrary.deleteStaff(deleteIdStaff);
                        cout << "Ban co muon xoa nhan vien tiep khong?(Yes/No)";
                        cin >> deleteStaffContinue;
                    } while (deleteStaffContinue == "Yes" || deleteStaffContinue == "yes");
                    HSLibrary.getViewStaff();
                    break;
                }
                }
                cout << "Ban co muon chon tiep chuc nang khac de thao tac?(Yes/No)";
                cin >> chooseStaffContinue;
            } while (chooseStaffContinue == "Yes" || chooseStaffContinue == "yes");
            break;
        }
        case 3:
        {
            string chooseStudentContinue;
            do {
                int chooseStudent;
                system("cls");
                cout << "===== Menu Student =====\n";
                cout << "1. Get all\n";
                cout << "2. Add\n";
                cout << "3. Search\n";
                cout << "4. Delete\n";
                cout << "0. Back\n";
                cout << "========================\n";
                cout << "Chon chuc nang: ";
                cin >> chooseStudent;
                switch (chooseStudent)
                {
                case 0:
                {
                    break;
                }
                case 1:
                {
                    if (getDataStudent == 0)
                    {
                        HSLibrary.inputStudentFromFile();
                        getDataStudent++;
                    }
                    HSLibrary.getViewStudent();
                    break;
                }
                case 2:
                {
                    string addStudentContinue;
                    do {
                        string idStudent, name, phone, email, major;

                        cout << "Nhap id student:";
                        cin.ignore();
                        getline(cin, idStudent);

                        cout << "Nhap ho ten:";
                        getline(cin, name);

                        cout << "Nhap so dien thoai:";
                        getline(cin, phone);

                        cout << "Nhap email:";
                        getline(cin, email);

                        cout << "Nhap nganh hoc:";
                        getline(cin, major);

                        HSLibrary.addStudent(Student(idStudent, major, Person(name, phone, email)));

                        cout << "Ban co muon them sach tiep khong?(Yes/No)";
                        cin >> addStudentContinue;
                    } while (addStudentContinue == "Yes" || addStudentContinue == "yes");
                    break;
                }
                case 3:
                {
                    string searchStudentContinue;
                    do {
                        string searchIdStudent;
                        cout << "Nhap id sinh vien muon tim kiem:";
                        cin.ignore();
                        getline(cin, searchIdStudent);
                        HSLibrary.searchStudent(searchIdStudent);
                        cout << "Ban co muon tim sinh vien tiep khong?(Yes/No)";
                        cin >> searchStudentContinue;
                    } while (searchStudentContinue == "Yes" || searchStudentContinue == "yes");
                    break;
                }
                case 4:
                {
                    string deleteStudentContinue;
                    do {
                        string deleteIdStudent;
                        cout << "Nhap id student muon xoa:";
                        cin.ignore();
                        getline(cin, deleteIdStudent);
                        HSLibrary.deleteStudent(deleteIdStudent);
                        cout << "Ban co muon xoa sinh vien tiep khong?(Yes/No)";
                        cin >> deleteStudentContinue;
                    } while (deleteStudentContinue == "Yes" || deleteStudentContinue == "yes");
                    HSLibrary.getViewStudent();
                    break;
                }
                }
                cout << "Ban co muon chon tiep chuc nang khac de thao tac?(Yes/No)";
                cin >> chooseStudentContinue;
            } while (chooseStudentContinue == "Yes" || chooseStudentContinue == "yes");
            break;
        }
        case 4:
        {
            Author author;
            author.readAuthorsFromFile("Author.txt");

            string chooseAuthorContinue;
            do {
                int chooseFunction;
                system("cls");
                cout << "==== Menu Author ====\n";
                cout << "1. Get all\n";
                cout << "2. Add\n";
                cout << "3. Search\n";
                cout << "4. Delete\n";
                cout << "0. Back\n";
                cout << "=====================\n";
                cout << "Chon chuc nang: ";
                cin >> chooseFunction;
                switch (chooseFunction)
                {
                case 1:
                {
                    author.getViewAuthor();
                    break;
                }
                case 2:
                {
                    string addAuthorContinue;
                    do {
                        string id, MaxId, authorName, description;
                        int getMaxId;

                        cout << "Nhap ten tac gia:";
                        cin.ignore();
                        getline(cin, authorName);

                        cout << "Nhap mo ta:";
                        getline(cin, description);

                        //Doc file Author.txt de lay Author id cao nhat
                        Author author;
                        MaxId = author.readMaxAuthorId();
                        getMaxId = stoi(MaxId) + 1;
                        id = to_string(getMaxId);

                        author.addAuthor(Author(id, authorName, description));

                        cout << "Ban co muon them tac gia tiep khong?(Yes/No)";
                        cin >> addAuthorContinue;
                    } while (addAuthorContinue == "Yes" || addAuthorContinue == "yes");
                    break;
                }
                case 3:
                {
                    string searchAuthorContinue;
                    do {
                        string searchIdAuthor;
                        cout << "Nhap id tac gia muon tim kiem:";
                        cin.ignore();
                        getline(cin, searchIdAuthor);
                        Author* foundAuthor = author.searchAuthor(searchIdAuthor);

                        if (foundAuthor == nullptr) {
                            cout << "Khong tim thay tac gia co Author ID: " << searchIdAuthor + "\n" << endl;
                        }

                        cout << "Ban co muon tim sinh vien tiep khong?(Yes/No)";
                        cin >> searchAuthorContinue;
                    } while (searchAuthorContinue == "Yes" || searchAuthorContinue == "yes");
                    break;
                }
                case 4:
                {
                    string addAuthorContinue;
                    do {
                        string deleteIdStudent;
                        cout << "Nhap id author muon xoa:";
                        cin.ignore();
                        getline(cin, deleteIdStudent);
                        author.deleteAuthor(deleteIdStudent);
                        cout << "Ban co muon xoa sinh vien tiep khong?(Yes/No)";
                        cin >> addAuthorContinue;
                    } while (addAuthorContinue == "Yes" || addAuthorContinue == "yes");
                    HSLibrary.getViewStudent();
                    break;
                }
                }
                cout << "Ban co muon chon tiep chuc nang khac de thao tac?(Yes/No)";
                cin >> chooseAuthorContinue;
            } while (chooseAuthorContinue == "Yes" || chooseAuthorContinue == "yes");
            break;
        }
        case 5:
        {
            Category category;
            category.readCategoriesFromFile("Category.txt");

            int chooseFunction;
            string chooseCategoryContinue;
            do {
                system("cls");
                
                cout << "==== Menu Category ====\n";
                cout << "1. Get all\n";
                cout << "2. Add\n";
                cout << "3. Search\n";
                cout << "4. Delete\n";
                cout << "0. Back\n";
                cout << "=======================\n";
                cout << "Chon chuc nang: ";

                cin >> chooseFunction;
                switch (chooseFunction)
                {
                case 1:
                {
                    category.getViewCategory();
                    _getch();
                    break;
                }
                case 2:
                {
                    string addCategoryContinue;
                    do {
                        string categoryId, MaxId, categoryName;
                        int getMaxId;

                        cout << "Nhap ten loai sach moi:";
                        cin.ignore();
                        getline(cin, categoryName);

                        //Doc file Category.txt de lay CategoryId cao nhat
                        MaxId = category.readMaxCategoryId();
                        getMaxId = stoi(MaxId) + 1;
                        categoryId = to_string(getMaxId);

                        category.addCategory(Category(categoryId, categoryName));

                        cout << "Ban co muon them tac gia tiep khong?(Yes/No)";
                        cin >> addCategoryContinue;
                    } while (addCategoryContinue == "Yes" || addCategoryContinue == "yes");
                    break;
                }
                case 3:
                {
                    string chooseCategoryContinue;
                    do {
                        string searchCategoryName;
                        cout << "Nhap ten danh muc muon tim kiem:";
                        cin.ignore();
                        getline(cin, searchCategoryName);

                        Category* foundCategory = category.searchCategory(searchCategoryName);

                        if (foundCategory == nullptr) {
                            cout << "Khong tim thay danh muc co ten: " << searchCategoryName + "\n" << endl;
                        }

                        cout << "Ban co muon tim kiem tiep khong?(Yes/No)";
                        cin >> chooseCategoryContinue;
                    } while (chooseCategoryContinue == "Yes" || chooseCategoryContinue == "yes");
                    break;
                }
                case 4:
                {
                    string addCategoryContinue;
                    do {
                        string deleteCategoryId;
                        cout << "Nhap category id muon xoa:";
                        cin.ignore();
                        getline(cin, deleteCategoryId);
                        category.deleteCategory(deleteCategoryId);
                        cout << "Ban co muon xoa tiep khong?(Yes/No)";
                        cin >> addCategoryContinue;
                    } while (addCategoryContinue == "Yes" || addCategoryContinue == "yes" ||
                        addCategoryContinue == "Y" || addCategoryContinue == "y");
                    HSLibrary.getViewStudent();
                    break;
                }
                }
                /*cout << "Ban co muon chon tiep chuc nang khac de thao tac?(Yes/No)";
                cin >> chooseCategoryContinue;*/
            } while (chooseFunction != 0);
            break;
        }
        default:
            cout << "Don not have this function. Please, Choose agian!" << endl;
            _getch();
        }
    }while (choose != 0);
} 