// testDate.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Samuel Garcia
// CECS 282-07
// Prog 2 - My Date
// 3/4/2020

#include <iostream>
#include <time.h>
#include "myDate.h"
using namespace std;

int Greg2Julian(int month, int day, int year)
{
	int I;
	int J;
	int K;
	int JD; // Julian date
	I = year;
	J = month;
	K = day;
	JD = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;
	return JD;
}
void Julian2Greg(int JD, int& month, int& day, int& year)
{
	int I;
	int J;
	int K;
	int L;
	int N;
	L = JD + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;
	year = I;
	month = J;
	day = K;
}
myDate::myDate() // Default constructor. Sets default date to May 11 1959
{
	this->month = 5;
	this->day = 11;
	this->year = 1959;
}
myDate::myDate(int M, int D, int Y) // Overloaded constructor. This sets date based on values passed in. 
{
	// checks to see if incoming date is valid if not it sets date to default
	if ((M < 1 || M > 12) || (D < 1 || D > 31) || (Y < 1))
	{
		// sets it to the default date of the constructor
		this->month = 5;
		this->day = 11;
		this->year = 1959;
	}
	else
	{
		this->month = M;
		this->day = D;
		this->year = Y;
	}
}
void myDate::display()
{
	switch (this->month)
	{
	case 1:
		cout << "January " << this->day << ", " << this->year;
		break;
	case 2:
		cout << "February " << this->day << ", " << this->year;
		break;
	case 3:
		cout << "March " << this->day << ", " << this->year;
		break;
	case 4:
		cout << "April " << this->day << ", " << this->year;
		break;
	case 5:
		cout << "May " << this->day << ", " << this->year;
		break;
	case 6:
		cout << "June " << this->day << ", " << this->year;
		break;
	case 7:
		cout << "July " << this->day << ", " << this->year;
		break;
	case 8:
		cout << "August " << this->day << ", " << this->year;
		break;
	case 9:
		cout << "September " << this->day << ", " << this->year;
		break;
	case 10:
		cout << "October " << this->day << ", " << this->year;
		break;
	case 11:
		cout << "November " << this->day << ", " << this->year;
		break;
	case 12:
		cout << "December " << this->day << ", " << this->year;
		break;
	}
}
void myDate::randomDate()
{
	srand(time(0));
	// Generates a random date given a time range
	int lowerBoundJD = Greg2Julian(1, 1, 1999);
	int upperBoundJD = Greg2Julian(12, 31, 2020);
	int randJD = rand() % (upperBoundJD - lowerBoundJD + 1) + lowerBoundJD;

	// Converts new date to Gregorian given the calculated difference
	Julian2Greg(randJD, this->month, this->day, this->year);
}
void myDate::increaseDate(int n)
{
	// Converts old date to Julian then increases by n days.
	int oldDate = Greg2Julian(this->month, this->day, this->year);
	int newDate = oldDate + n;

	// Converts new date to Gregorian given the calculated difference
	Julian2Greg(newDate, this->month, this->day, this->year);
}
void myDate::decreaseDate(int n)
{
	// Converts old date to Julian then decreases by n days.
	int oldDate = Greg2Julian(this->month, this->day, this->year);
	int newDate = oldDate - n;

	// Converts new date to Gregorian given the calculated difference
	Julian2Greg(newDate, this->month, this->day, this->year);
}
int myDate::daysBetween(myDate D)
{
	int thisDate = Greg2Julian(this->month, this->day, this->year);
	int thatDate = Greg2Julian(D.getMonth(), D.getDay(), D.getYear());

	return thatDate - thisDate;
}
int myDate::getMonth()
{
	return this->month;
}
int myDate::getDay()
{
	return this->day;
}
int myDate::getYear()
{
	return this->year;
}
int myDate::dayOfYear()
{
	int startOfYear = Greg2Julian(1, 1, this->year);
	int currentDate = Greg2Julian(this->month, this->day, this->year);
	int days = (currentDate - startOfYear) + 1;

	return days;
}
string myDate::dayName()
{
	int julianDate = Greg2Julian(this->month, this->day, this->year);
	int dayOfWeek = (julianDate % 7);

	if (dayOfWeek == 0)
	{
		return "Monday";
	}
	else if (dayOfWeek == 1)
	{
		return "Tuesday";
	}
	else if (dayOfWeek == 2)
	{
		return "Wednesday";
	}
	else if (dayOfWeek == 3)
	{
		return "Thursday";
	}
	else if (dayOfWeek == 4)
	{
		return "Friday";
	}
	else if (dayOfWeek == 5)
	{
		return "Saturday";
	}
	else
	{
		return "Sunday";
	}
}