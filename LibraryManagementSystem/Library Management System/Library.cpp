#include <fstream>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "Library.h"

Library::Library(string name)
{
	this->name = name;
}

string Library::toString()
{
	return "Library: " + this->name;
}