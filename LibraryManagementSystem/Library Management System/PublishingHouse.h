#pragma once
#include <iostream>
#include <string>
using namespace std;

class PublishingHouse
{
public:
	string name;
	string nation;

public:
	PublishingHouse(string name, string nation);
	PublishingHouse() = default;
	string toString();
};

