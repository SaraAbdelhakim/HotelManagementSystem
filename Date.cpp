#include "Date.h"

Date::Date() : yyyy(2023), mm(1), dd(1) {}

Date::Date(int yyyy, int mm, int dd)
{
	setYear(yyyy);
	setMonth(mm);
	setDay(dd);
}

void Date::setYear(int yyyy)
{
	if (yyyy >= 2023)
		this->yyyy = yyyy;
	else
		this->yyyy = 2023;
}

void Date::setMonth(int mm)
{
	if (mm >= 1 && mm <= 12)
		this->mm = mm;
	else
		this->mm = 1;
}

void Date::setDay(int dd)
{
	if (dd >= 1 && dd <= 31)
		this->dd = dd;
	else
		this->dd = 1;
}

int Date::getYear() 
{
	return yyyy;
}

int Date::getMonth()
{
	return mm;
}

int Date::getDay()
{
	return dd;
}

void Date::getDate() {
	cout << yyyy << "/" << mm << "/" << dd << endl;
}