#include "person.h"
#include <stdexcept>

string person::getName()
{
	return first_name;
}

void person::setName(string first_name, string last_name)
{
	this->first_name = first_name;
	this->last_name = last_name;
}

int person::getAge()
{
	return age;
}

void person::setAge(int age)
{
	if (age < 1 && age>100)
		throw invalid_argument("Inavlid age!");
	this->age = age;
}


string person::getGender()
{
	return gender;
}

void person::setGender(string gender) 
{
	if (gender != "female" || gender != "Female" || gender != "male" || gender != "Male")
		throw invalid_argument("Inavlid gender!");
	this->gender = gender;
}

bool person::isAdult()
{
	if (age >= 18)
		return true;
	else
		return false;
}
