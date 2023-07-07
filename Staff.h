#pragma once
#include "person.h"


class Staff : public person
{
	string position;
	double salary{};
	Date EmploymentDate;
	int shiftHours{};
public:
	Staff(){}
	Staff(string first_name, string last_name, string gender, int age,
		string position, double salary, const Date& EmploymentDate, int shiftHours) : 
		person(first_name, last_name, gender, age),
		position(position), salary(salary), EmploymentDate(EmploymentDate), shiftHours(shiftHours){}

	void setPosition(string position);
	string getPosition() const;

	void setSalary(double salary);
	double getSalary() const;
	string getEmploymentDate();

	bool isFullTime();
	bool ifPartTime();
	void getStaffInfo();
};

