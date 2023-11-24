#pragma once
#include "Person.h"
class Staff :
    public Person
{
public:
    string idStaff;

public:
    Staff();
    Staff(string id, Person person);
    string toString();
    string getIdStaff();
};

