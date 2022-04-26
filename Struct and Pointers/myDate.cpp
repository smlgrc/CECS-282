// Samuel Garcia
// CECS 282-07
// Prog 3 - Struct and Pointers
// 3/23/2020
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
	month = 5;
	day = 11;
	year = 1959;
}
myDate::myDate(int M, int D, int Y) // Overloaded constructor. This sets date based on values passed in. 
{
	// checks to see if incoming date is valid if not it sets date to default
	if ((M < 1 || M > 12) || (D < 1 || D > 31) || (Y < 1))
	{
		// sets it to the default date of the constructor
		month = 5;
		day = 11;
		year = 1959;
	}
	else
	{
		month = M;
		day = D;
		year = Y;
	}
}
void myDate::display()
{
	switch (month)
	{
	case 1:
		cout << "January " << day << ", " << year;
		break;
	case 2:
		cout << "February " << day << ", " << year;
		break;
	case 3:
		cout << "March " << day << ", " << year;
		break;
	case 4:
		cout << "April " << day << ", " << year;
		break;
	case 5:
		cout << "May " << day << ", " << year;
		break;
	case 6:
		cout << "June " << day << ", " << year;
		break;
	case 7:
		cout << "July " << day << ", " << year;
		break;
	case 8:
		cout << "August " << day << ", " << year;
		break;
	case 9:
		cout << "September " << day << ", " << year;
		break;
	case 10:
		cout << "October " << day << ", " << year;
		break;
	case 11:
		cout << "November " << day << ", " << year;
		break;
	case 12:
		cout << "December " << day << ", " << year;
		break;
	}
}
string myDate::toString()
{
	if (month == 1)
	{
		return "January " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 2)
	{
		return "February " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 3)
	{
		return "March " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 4)
	{
		return "April " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 5)
	{
		return "May " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 6)
	{
		return "June " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 7)
	{
		return "July " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 8)
	{
		return "August " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 9)
	{
		return "September " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 10)
	{
		return "October " + to_string(day) + ", " + to_string(year);
	}
	else if (month == 11)
	{
		return "November " + to_string(day) + ", " + to_string(year);
	}
	else
	{
		return "December " + to_string(day) + ", " + to_string(year);
	}
}
void myDate::increaseDate(int n)
{
	// Converts old date to Julian then increases by n days.
	int oldDate = Greg2Julian(month, day, year);
	int newDate = oldDate + n;

	// Converts new date to Gregorian given the calculated difference
	Julian2Greg(newDate, month, day, year);
}
void myDate::decreaseDate(int n)
{
	// Converts old date to Julian then decreases by n days.
	int oldDate = Greg2Julian(month, day, year);
	int newDate = oldDate - n;

	// Converts new date to Gregorian given the calculated difference
	Julian2Greg(newDate, month, day, year);
}
int myDate::daysBetween(myDate D)
{
	int thisDate = Greg2Julian(month, day, year);
	int thatDate = Greg2Julian(D.getMonth(), D.getDay(), D.getYear());

	return thisDate - thatDate;
}
int myDate::getMonth()
{
	return month;
}
int myDate::getDay()
{
	return day;
}
int myDate::getYear()
{
	return year;
}
int myDate::dayOfYear()
{
	int startOfYear = Greg2Julian(1, 1, year);
	int currentDate = Greg2Julian(month, day, year);
	int days = (currentDate - startOfYear) + 1;

	return days;
}
string myDate::dayName()
{
	int julianDate = Greg2Julian(month, day, year);
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