#pragma once
#include "Person.h"
class Student :
    public Person
{
public:
    string idStudent;
    string major;

public:
    Student();
    Student(string idStudent, string major, Person person);
    string toString();
    string getIdStudent();

};

