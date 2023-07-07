#include <iostream>
#pragma once
using namespace std;

class Date {
	int yyyy;
	int mm;
	int dd;
public:
	Date();
	Date(int yyyy, int mm, int dd);

	void setYear(int yyyy);
	void setMonth(int mm);
	void setDay(int dd);

	int getYear();
	int getMonth();
	int getDay();

	void getDate();
};
