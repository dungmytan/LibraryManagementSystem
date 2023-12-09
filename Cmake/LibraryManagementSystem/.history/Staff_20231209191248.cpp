#include "Staff.h"

Staff::Staff():Person(){}

Staff::Staff(string idStaff, Person person)
	:Person(
		person.getName(),
		person.getPhone(),
		person.getEmail(),
		person.getAddress()
	)
{
	this->idStaff = idStaff;
}

string Staff::toString()
{
	return "ID: " + this->idStaff
		+ "\nName: " + this->getName()
		+ "\nPhone: " + this->getPhone()
		+ "\nEmail: " + this->getEmail()
		+ "\nAddress: " + this->getAddress().toString();
}

string Staff::getIdStaff()
{
	return this->idStaff;
}

void Staff::setConsoleColor(ConsoleColor textColor, ConsoleColor bgColor)
{
	int color = textColor + bgColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

list<Staff> Staff::getStaff()
{
	return this->staffList;
}

bool Staff::addStaff(Staff staff)
{
	this->staffList.push_back(staff);
	ofstream fileOut("Staff.txt", std::ios::app);

	if (fileOut.is_open()) {
		fileOut << staff.toString() << std::endl;
	}
	else {
		std::cerr << "Can not create a file to record." << std::endl;
	}

	fileOut.close();
	return true;
}

void Staff::inputStaffFromFile()
{
	std::ifstream fileIn("Staff.txt");
	std::string line, space;
	Staff staff;
	if (!fileIn.is_open()) {
		std::cerr << "Can not open file to read!" << std::endl;
		return;
	}

	while (!fileIn.eof())
	{
		while (getline(fileIn, line)) {
			std::istringstream iss(line);
			std::string key;

			getline(iss, key, ':');

			if (key == "ID") {
				if (staff.idStaff != "")
				{
					this->staffList.push_back(staff);
					staff = Staff();
				}
				getline(iss, space, ' ');
				space = "";
				getline(iss, staff.idStaff);
			}
			else if (key == "Name") {
				getline(iss, space, ' ');
				space = "";
				getline(iss, staff.name);
			}
			else if (key == "Phone") {
				getline(iss, space, ' ');
				space = "";
				getline(iss, staff.phone);
			}
			else if (key == "Email") {
				getline(iss, space, ' ');
				space = "";
				getline(iss, staff.email);
			}
			else if (key == "Address") {
				getline(iss, space, ' ');
				space = "";
				getline(iss, staff.address.streetAddress, '/');
				getline(iss, space, '.');
				space = "";
				getline(iss, staff.address.ward, '/');
				getline(iss, space, '.');
				space = "";
				getline(iss, staff.address.district, '/');
				getline(iss, space, '.');
				space = "";
				getline(iss, staff.address.city);
			}

		}
		if (staff.idStaff != "")
			this->staffList.push_back(staff);
	}
	fileIn.close();
}

void Staff::getViewStaff()
{
	cout << "\n========== STAFF LIST ==========\n";

	for (auto& staff : this->staffList)
	{
		cout << staff.toString() << "\n\n";
	}
}

Staff* Staff::searchStaff(const string& idStaff)
{
	for (auto& staff : this->staffList)
	{
		if (staff.getIdStaff() == idStaff)
		{
			cout << staff.toString() << "\n";
			return &staff;
		}
	}
	return nullptr;
}

bool Staff::deleteStaff(const string& idStaff)
{
	auto it = remove_if(this->staffList.begin(), this->staffList.end(),
		[idStaff](Staff& staff) { return staff.getIdStaff() == idStaff; });

	if (it != this->staffList.end())
	{
		this->staffList.erase(it, this->staffList.end());
		setConsoleColor(Green, Black);
		cout << "Staff with ID \"" << idStaff << "\" deleted successfully.\n";
		ofstream fileOut("Staff.txt");

		if (fileOut.is_open()) {
			for (auto& staff : this->staffList)
			{
				fileOut << staff.toString() << std::endl;
			}
		}
		else {
			std::cerr << "Can not create a file to record." << std::endl;
		}

		fileOut.close();
		return true;
	}
	else
	{
		setConsoleColor(Red, White);
		cout << "No staff found with ID \"" << idStaff << "\" in Library " << this->name << "\n";
		return false;
	}
}
