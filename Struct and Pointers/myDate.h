// Samuel Garcia
// CECS 282-07
// Prog 3 - Struct and Pointers
// 3/23/2020
#ifndef MYDATE_H
#define MYDATE_H
#include <string>

using namespace std;

int Greg2Julian(int, int, int);
void Julian2Greg(int, int&, int&, int&);
class myDate
{
private:
	int month;
	int day;
	int year;
public:
	myDate();
	myDate(int, int, int);
	void display();
	string toString();
	void increaseDate(int);
	void decreaseDate(int);
	int daysBetween(myDate);
	int getMonth();
	int getDay();
	int getYear();
	int dayOfYear();
	string dayName();
};
#endif