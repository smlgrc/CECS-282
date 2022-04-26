// Samuel Garcia
// CECS 282-07
// Prog 3 - Struct and Pointers
// 3/23/2020

#include <iostream>
#include <cstring>
#include <string>
#include <time.h>
#include <iomanip>
#include "myDate.h"

using namespace std;

struct Student
{
    char name[20];
    myDate birthday;
    int ID;
    char grade;
    string hometown;
};

// function prototypes
myDate randomDate(myDate lower, myDate upper);
void populateStudents(Student* studentPtr[]);
void displayMenu();
void displayStudents(Student* studentPtr[]);
void sortByName(Student* studentPtr[]);
void sortByID(Student* studentPtr[]);
void sortByGrade(Student* studentPtr[]);
void sortByBirthday(Student* studentPtr[]);
void sortByHometown(Student* studentPtr[]);

int main()
{
    srand(time(0));
    Student* ptrsToStudents[10]; // creates an array of pointers
    int menuOption;
    bool quit = false;
    // initializes the array with type Student
    for (int i = 0; i < 10; i++)
    {
        //Student* student1;  // this is a pointer = ptrsToStudents[i] 
        //student1 = new Student; // the pointer is pointing to an instance of Student structure
        ptrsToStudents[i] = new Student;
    }
    // Populates array of pointers to instances of student
    populateStudents(ptrsToStudents);

    while (quit != true)
    {
        displayMenu();
        cout << "\nPlease enter a valid menu option: ";
        cin >> menuOption;
        cout << endl;

        // displays sorted by name
        if (menuOption == 1)
        {
            sortByName(ptrsToStudents);
            displayStudents(ptrsToStudents);
        }
        // display sorted by ID
        else if (menuOption == 2)
        {
            sortByID(ptrsToStudents);
            displayStudents(ptrsToStudents);
        }
        // display sorted by grade
        else if (menuOption == 3)
        {
            sortByGrade(ptrsToStudents);
            displayStudents(ptrsToStudents);
        }
        // display sorted by birthday
        else if (menuOption == 4)
        {
            sortByBirthday(ptrsToStudents);
            displayStudents(ptrsToStudents);
        }
        // display sorted by hometown
        else if (menuOption == 5)
        {
            sortByHometown(ptrsToStudents);
            displayStudents(ptrsToStudents);
        }
        // exits program
        else if (menuOption == 6)
        {
            cout << "End of program.\n";
            quit = true;
        }
        else
        {
            cout << "Invalid input, try again.\n" << endl;
        }
    }
    return 0;
}
myDate randomDate(myDate lower, myDate upper)
{
    myDate randDate = lower;
    int daysBetween = lower.daysBetween(upper);
    int randDays = rand() % (daysBetween + 1);
    randDate.increaseDate(randDays);
    return randDate;
}
void populateStudents(Student* studentPtr[])
{
    string input;
    int year = 0;
    int month = 0;
    int day = 0;
    myDate birthday;
    char grade[5] = { 'A', 'B', 'C', 'D', 'F' };
    string names[10] = { "Samuel Garcia", "Jensen Ackles", "Jared Padalecki", "Misha Collins",
                        "Mark Sheppard", "Mark Pellegrino", "Jim Beaver", "Jeffrey Dean Morgan",
                        "Richard Speight", "Kiera Wheatley" };
    string hometowns[10] = { "Long Beach", "Dallas", "San Antonio", "Boston", "London", "Los Angeles",
                         "Laramie", "Seattle", "Nashville", "Royal Oak" };

    // for every index in pointer array
    for (int i = 0; i < 10; i++)
    {
        // Sets same
        strcpy_s(studentPtr[i]->name, names[i].c_str());

        // Sets student ID
        (*studentPtr[i]).ID = rand() % (9999 - 1000 + 1) + 1000; // studentPtr[i]->ID = (*studentPtr[i]).ID

        // Sets grade
        int randGrade = rand() % 5;
        studentPtr[i]->grade = grade[randGrade];

        // Sets birthday
        myDate lowerDate(1, 1, 1999);
        myDate upperDate(12, 31, 2004);
        studentPtr[i]->birthday = randomDate(lowerDate, upperDate);

        // Sets home town
        studentPtr[i]->hometown = hometowns[i];
    }
}
void displayMenu()
{
    cout << "1) Display list sorted by Name" << endl;
    cout << "2) Display list sorted by Student ID" << endl;
    cout << "3) Display list sorted by Grade" << endl;
    cout << "4) Display list sorted by Birthday" << endl;
    cout << "5) Display list sorted by Home Town" << endl;
    cout << "6) Quit" << endl;
}
void displayStudents(Student* studentPtr[])
{
    cout << setw(25) << left << "Name";
    cout << setw(15) << left << "Student ID";
    cout << setw(10) << left << "Grade";
    cout << setw(20) << left << "Birthday";
    cout << setw(25) << left << "Home Town" << endl;

    cout << setw(25) << left << "-----";
    cout << setw(15) << left << "-----------";
    cout << setw(10) << left << "-----";
    cout << setw(20) << left << "--------";
    cout << setw(25) << left << "---------" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << setw(25) << left << (*studentPtr[i]).name; // studentPtr[i]->name = (*studentPtr[i]).name // the second part dereferences the pointer
        cout << setw(15) << left << studentPtr[i]->ID;
        cout << setw(10) << left << studentPtr[i]->grade;
        cout << setw(20) << left << studentPtr[i]->birthday.toString();
        cout << setw(25) << left << studentPtr[i]->hometown << endl;
        /*
        cout << left << setw(25) << (*studentPtr[i]).name; // studentPtr[i]->name = (*studentPtr[i]).name // the second part dereferences the pointer
        cout << left << setw(15) << studentPtr[i]->ID;
        cout << left << setw(10) << studentPtr[i]->grade;
        cout << left << setw(20) << studentPtr[i]->birthday.toString();
        cout << left << setw(25) << studentPtr[i]->hometown << endl;
        */
    }
    cout << endl;
}
void sortByName(Student* studentPtr[])
{
    int i, j;
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            // if name at j is bigger than name at j + 1, then swap
            if (strcmp(studentPtr[j]->name, studentPtr[j + 1]->name) > 0)
            {
                Student* temp = studentPtr[j];
                studentPtr[j] = studentPtr[j + 1];
                studentPtr[j + 1] = temp;
            }
        }
    }
}
void sortByID(Student* studentPtr[])
{
    int i, j;
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if ((studentPtr[j]->ID) > (studentPtr[j + 1]->ID))
            {
                Student* temp = studentPtr[j];
                studentPtr[j] = studentPtr[j + 1];
                studentPtr[j + 1] = temp;
            }
        }
    }
}
void sortByGrade(Student* studentPtr[])
{
    int i, j;
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            // if name at j is bigger than name at j + 1, then swap
            if ((studentPtr[j]->grade) > (studentPtr[j + 1]->grade))
            {
                Student* temp = studentPtr[j];
                studentPtr[j] = studentPtr[j + 1];
                studentPtr[j + 1] = temp;
            }
        }
    }
}
void sortByBirthday(Student* studentPtr[])
{
    int i, j;
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            // if the implicit date is bigger than explicit date, then swap
            myDate thisDate = studentPtr[j]->birthday;
            myDate thatDate = studentPtr[j + 1]->birthday;
            //if ((studentPtr[j]->birthday.daysBetween(studentPtr[j + 1]->birthday)) > 0)
            if (thisDate.daysBetween(thatDate) > 0)
            {
                Student* temp = studentPtr[j];
                studentPtr[j] = studentPtr[j + 1];
                studentPtr[j + 1] = temp;
            }
        }
    }
}
void sortByHometown(Student* studentPtr[])
{
    int i, j;
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (studentPtr[j]->hometown.compare(studentPtr[j + 1]->hometown) > 0)
            {
                Student* temp = studentPtr[j];
                studentPtr[j] = studentPtr[j + 1];
                studentPtr[j + 1] = temp;
            }
        }
    }
}



