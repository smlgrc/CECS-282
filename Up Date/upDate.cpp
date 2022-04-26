#include "upDate.h"
#include <iostream>
using namespace std;

int upDate::count = 0;
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
upDate::upDate()
{
	dptr = new int[3];
	dptr[0] = 5;
	dptr[1] = 11;
	dptr[2] = 1959;
	count++;
}
upDate::upDate(int M, int D, int Y)
{
	dptr = new int[3];
	if ((M < 1 || M > 12) || (D < 1 || D > 31) || (Y < 1))
	{
		dptr[0] = 5;
		dptr[1] = 11;
		dptr[2] = 1959;
		count++;
	}
	else
	{
		dptr[0] = M;
		dptr[1] = D;
		dptr[2] = Y;
		count++;
	}
}
upDate::upDate(int J)
{   
	dptr = new int[3];
	Julian2Greg(J, dptr[0], dptr[1], dptr[2]);
	count++;
}
upDate::upDate(const upDate& D)
{
	dptr = new int[3];
	this->setDate(D.dptr[0], D.dptr[1], D.dptr[2]);
	count++;
}
upDate::~upDate()
{
	delete[] dptr;
	count--;
}
void upDate::setDate(int M, int D, int Y)
{
	dptr[0] = M;
	dptr[1] = D;
	dptr[2] = Y;
}
int upDate::getMonth()
{
	return dptr[0];
}
int upDate::getDay()
{
	return dptr[1];
}
int upDate::getYear()
{
	return dptr[2];
}
string upDate::getMonthName()
{
	if (dptr[0] == 1)
	{
		return "January";
	}
	else if (dptr[0] == 2)
	{
		return "February";
	}
	else if (dptr[0] == 3)
	{
		return "March";
	}
	else if (dptr[0] == 4)
	{
		return "April";
	}
	else if (dptr[0] == 5)
	{
		return "May";
	}
	else if (dptr[0] == 6)
	{
		return "June";
	}
	else if (dptr[0] == 7)
	{
		return "July";
	}
	else if (dptr[0] == 8)
	{
		return "August";
	}
	else if (dptr[0] == 9)
	{
		return "September";
	}
	else if (dptr[0] == 10)
	{
		return "October";
	}
	else if (dptr[0] == 11)
	{
		return "November";
	}
	else
	{
		return "December";
	}
}
void upDate::incrementDate(int n)
{
	int newJulian = this->julian() + n;
	Julian2Greg(newJulian, dptr[0], dptr[1], dptr[2]);
}
void upDate::decrementDate(int n)
{
	int oldDate = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	int newDate = oldDate - n;

	Julian2Greg(newDate, dptr[0], dptr[1], dptr[2]);
}
int upDate::daysBetween(upDate D)
{
	int thisDate = Greg2Julian(dptr[0], dptr[1], dptr[2]);
	int thatDate = Greg2Julian(D.getMonth(), D.getDay(), D.getYear());

	return thisDate - thatDate;
}
int upDate::GetDateCount()
{
	return count;
}
int upDate::julian() // int x = D1.julian();
{
	return Greg2Julian(dptr[0], dptr[1], dptr[2]);
}

// Overloaded Operators
upDate upDate::operator=(upDate D)  // D1 = D2; assignment operator
{
	this->setDate(D.dptr[0], D.dptr[1], D.dptr[2]);

	return *this;
}

upDate upDate::operator+=(int n) // D1 += 1;
{
	int newJD = this->julian() + n;
	Julian2Greg(newJD, dptr[0], dptr[1], dptr[2]);
	return *this;
}
upDate upDate::operator+(int n) // D1 = D2 + int;
{
	upDate temp(*this);
	temp.incrementDate(n);

	return temp;
}
upDate operator+(int n, upDate D) // int + D1; friend overloaded // 5.operator+(upDate)
{
	D.incrementDate(n);
	return D;
}

upDate upDate::operator-=(int n)  // D1 -= 1;
{
	int JD = Greg2Julian(dptr[0], dptr[1], dptr[2]);
    upDate temp(JD - n);

	this->setDate(temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	return *this;
}
upDate upDate::operator-(int n)  // D1 - int;
{
	upDate temp(*this);
    temp.decrementDate(n);

	return temp;
}
upDate operator-(int n, upDate D) // x = int - D1; friend overloaded
{
	D.decrementDate(n);
	return D;
}
int upDate::operator-(upDate D) // x = D1 - D2;
{
	return daysBetween(D);
}

upDate& upDate::operator++()  // ++D1
{
	this->incrementDate(1);
	return *this;
}
upDate upDate::operator++(int dummy)  // D1++ // dummy variable so that the compiler knows that it is post increment
{
	upDate temp(*this); // we create a temp in order to return a pre incremented version of the implicit object before it is incremented
	this->incrementDate(1);

	return temp; // even though this is not incremented, the implicit is and will show whenever it is called again.
}
upDate& upDate::operator--()  // --D1
{
	this->decrementDate(1);
	return *this;
}
upDate upDate::operator--(int dummy)  // D1--
{
	upDate temp(*this); 
	this->decrementDate(1);

	return temp;
}

ostream& operator<<(ostream& out, const upDate& D)  // cout << D1;
{
	out << D.dptr[0];
	out << "/";
	out << D.dptr[1];
	out << "/";
	out << D.dptr[2];
	return out;
}

// Comparison Operators
bool upDate::operator==(upDate D)
{
	if (daysBetween(D) == 0) { return true; }
	else { return false; }
}
bool upDate::operator>(upDate D)
{
	if (daysBetween(D) > 0) { return true; }
	else { return false; }
}
bool upDate::operator<(upDate D)
{
	if (daysBetween(D) < 0) { return true; }
	else { return false; }
}