#ifndef UPDATE_H
#define UPDATE_H
#include <string>
using namespace std;

static int count;
int Greg2Julian(int, int, int);
void Julian2Greg(int, int&, int&, int&);
class upDate
{
	private:
		int* dptr;
		static int count;
	public:
		upDate();                                             // default constructor
		upDate(int, int, int);				                  // overloaded constructor
		upDate(int);                                          // overloaded constructor - D1(julian)
		upDate(const upDate&);				                  // copy constructor -> Box B1(B2) and Box B1 = B2
		~upDate();
		void setDate(int, int, int);
		int getMonth();
		int getDay();
		int getYear();
		string getMonthName();
		void incrementDate(int);
		void decrementDate(int);
		int daysBetween(upDate);
		static int GetDateCount();
		int julian();                                         // x = D1.julian();

		// Overloaded Operators
		upDate operator=(upDate);			                  // D1 = D2; assignment operator
	
		upDate operator+=(int);				                  // D1 += 1;
		upDate operator+(int);				                  // D1 + int;
		friend upDate operator+(int, upDate);                 // int + D1; friend overloaded // 5.operator+(upDate)

		upDate operator-=(int);                               // D1 -= 1;
		upDate operator-(int);                                // D1 - int;
		friend upDate operator-(int, upDate);                 // x = int - D1; friend overloaded
		int operator-(upDate);                                // x = D1 - D2;

		upDate& operator++();                                 // ++D1
		upDate operator++(int);                               // D1++
		upDate& operator--();                                 // --D1
		upDate operator--(int);                               // D1--

		friend ostream& operator<<(ostream&, const upDate&);  // cout << D1;

		// Comparison Operators
		bool operator==(upDate);                              // if (D1 == D2)
		bool operator>(upDate);                               // if (D1 > D2)
		bool operator<(upDate);                               // if (D1 < D2)
};
#endif
