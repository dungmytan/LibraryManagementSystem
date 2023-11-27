#pragma once
#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include <Windows.h>
using namespace std;

#include "BasicTypes.h"
#include "Person.h"

class Staff :
    public Person
{
public:
    string idStaff;
    list<Staff> staffList;

public:
    Staff();
    Staff(string id, Person person);
    string toString();
    string getIdStaff();

    void setConsoleColor(ConsoleColor textColor, ConsoleColor bgColor);

    list<Staff> getStaff();
    bool addStaff(Staff staff);
    void inputStaffFromFile();
    void getViewStaff();
    Staff* searchStaff(const string& idStaff);
    bool deleteStaff(const string& idStaff);
};

