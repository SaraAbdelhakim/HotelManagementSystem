#include "Staff.h"

void Staff::setPosition(string position)
{
	this->position = position;
}

string Staff::getPosition() const
{
	return position;
}

void Staff::setSalary(double salary)
{
	this->salary = salary;
}

double Staff::getSalary() const
{
	return salary;
}

string Staff::getEmploymentDate()
{
	int year=EmploymentDate.getYear();
	int month=EmploymentDate.getMonth();
	int day =EmploymentDate.getDay();
	string strYear = to_string(year);
	string strMonth = to_string(month);
	string strDay = to_string(day);
	return strYear + "/" + strMonth + "/" + strDay;
}

bool Staff::isFullTime()
{
	if (shiftHours >= 8)
		return true;
	else
		return false;
}

bool Staff::ifPartTime()
{
	if (shiftHours < 8)
		return true;
	else
		return false;
}

void Staff::getStaffInfo()
{
	cout << "Employee Info: " << endl 
		<< "Name: " << getName() << endl
		<< "Gender: " << getGender() << endl
		<< "Age" << getAge() << endl
		<< "Position: " << getPosition() << endl
		<< "Salary: " << getSalary() << "EUR" << endl;

	if (isFullTime())
		cout << "Shift: Full-Time" << endl;
	else
		cout << "Shift: Part-Time" << endl;
}

