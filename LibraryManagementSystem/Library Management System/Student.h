#pragma once
#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include <Windows.h>
using namespace std;

#include "BasicTypes.h"
#include "Person.h"

class Student :
    public Person
{
public:
    string idStudent;
    string major;

    list<Student> studentList;

public:
    Student();
    Student(string idStudent, string major, Person person);
    string toString();
    string getIdStudent();

    void setConsoleColor(ConsoleColor textColor, ConsoleColor bgColor);

    list<Student> getStudent();
    bool addStudent(Student student);
    void inputStudentFromFile();
    void getViewStudent();
    Student* searchStudent(const string& idStudent);
    bool deleteStudent(const string& idStudent);
};

