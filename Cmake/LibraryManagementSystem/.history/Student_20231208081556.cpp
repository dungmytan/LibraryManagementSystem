#include "Student.h"

Student::Student():Person(){}

Student::Student(string idStudent, string major, Person person)
	:Person(
		person.getName(),
		person.getPhone(),
		person.getEmail()
	)
{
	this->idStudent = idStudent;
	this->major = major;
}

string Student::toString()
{
	return "ID: " + this->idStudent
		+ "\nName: " + this->getName()
		+ "\nPhone: " + this->getPhone()
		+ "\nEmail: " + this->getEmail()
		+ "\nMajor: " + this->major;
}

string Student::getIdStudent()
{
	return this->idStudent;
}

void Student::setConsoleColor(ConsoleColor textColor, ConsoleColor bgColor)
{
	int color = textColor + bgColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

list<Student> Student::getStudent()
{
	return this->studentList;
}

bool Student::addStudent(Student student)
{
	this->studentList.push_back(student);
	ofstream fileOut("Student.txt", std::ios::app);

	if (fileOut.is_open()) {
		fileOut << student.toString() << std::endl;
	}
	else {
		std::cerr << "Can not create a file to record." << std::endl;
	}

	fileOut.close();
	return true;
}

void Student::inputStudentFromFile()
{
	std::ifstream fileIn("Student.txt");
	std::string line, space;
	Student student;
	if (!fileIn.is_open()) {
		std::cerr << "Khong the mo file de doc." << std::endl;
		return;
	}

	while (!fileIn.eof())
	{
		while (getline(fileIn, line)) {
			std::istringstream iss(line);
			std::string key;

			getline(iss, key, ':');

			if (key == "ID") {
				if (student.idStudent != "")
				{
					this->studentList.push_back(student);
					student = Student();
				}
				getline(iss, space, ' ');
				space = "";
				getline(iss, student.idStudent);
			}
			else if (key == "Name") {
				getline(iss, space, ' ');
				space = "";
				getline(iss, student.name);
			}
			else if (key == "Phone") {
				getline(iss, space, ' ');
				space = "";
				getline(iss, student.phone);
			}
			else if (key == "Email") {
				getline(iss, space, ' ');
				space = "";
				getline(iss, student.email);
			}
			else if (key == "Major") {
				getline(iss, space, ' ');
				space = "";
				getline(iss, student.major);
			}

		}
		if (student.idStudent != "")
			this->studentList.push_back(student);
	}
	fileIn.close();
}

void Student::getViewStudent()
{
	cout << "Students in Library " << this->name << ":\n";

	for (auto& student : this->studentList)
	{
		cout << student.toString() << "\n\n";
	}
}

Student* Student::searchStudent(const string& idStudent)
{
	for (auto& student : this->studentList)
	{
		if (student.getIdStudent() == idStudent)
		{
			cout << student.toString() << "\n";
			return &student;
		}
	}
	return nullptr;
}

bool Student::deleteStudent(const string& idStudent)
{
	auto it = remove_if(this->studentList.begin(), this->studentList.end(),
		[idStudent](Student& student) { return student.getIdStudent() == idStudent; });

	if (it != this->studentList.end())
	{
		this->studentList.erase(it, this->studentList.end());
		setConsoleColor(Green, Black);
		cout << "Student with ID \"" << idStudent << "\" deleted successfully.\n";
		ofstream fileOut("Student.txt");

		if (fileOut.is_open()) {
			for (auto& student : this->studentList)
			{
				fileOut << student.toString() << std::endl;
			}
		}
		else {
			std::cerr << "Khong the mo file de ghi." << std::endl;
		}

		fileOut.close();
		return true;
	}
	else
	{
		setConsoleColor(Red, White);
		cout << "No student found with ID \"" << idStudent << "\" in Library " << this->name << "\n";
		return false;
	}
}
