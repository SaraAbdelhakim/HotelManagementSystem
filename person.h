#include <string>
#include "Date.h"
#include <iostream>
using namespace std;
#pragma once

class person {
protected:
	string first_name;
	string last_name;
	string gender;
	int age{};
public:
	//default constructor
	person(){}
	//constructor with all attrributes
	person(string first_name, string last_name, string gender, int age):
		first_name(first_name), last_name(last_name), gender(gender), age(age){}
	
	//Getters and Setters
	string getName();
	void setName(string first_name, string last_name);
	int getAge();
	void setAge(int age);
	string getGender();
	void setGender(string gender);

	//some other operations
	bool isAdult();
};