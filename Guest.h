#pragma once
#include "person.h"


class Guest : public person
{
	string nationality;
	string address;
	string phone;
public:
	//default constructor
	Guest() {}
	//constructor with all attrributes
	Guest(string first_name, string last_name, string gender, int age, string address, string phone, 
		 string nationality) : person(first_name, last_name, gender, age), 
		address(address), phone(phone), nationality(nationality) {}

	//Getters and Setters
	string getNationality();
	void setNationality(string nationality);
	string getAddress();
	void setAddress(string address);
	string getPhone();
	void setPhone(string phone);

};
