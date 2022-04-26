#include <iostream>
using namespace std;
int crazy(int, int*, int&, int, int*, int*);

int main()
{
    int a = 4; // a variable has both an address in memory and a value stored in it
    int b = 6;
    int c = 10;
    int d = 12;
    int e = 17;
    int* ptr1 = &e; // pointers point to variables given an address
    int* ptr2 = &c;




    int f = crazy(a, &b, c, d, ptr1, ptr2);
    //int f = crazy(a, &b, c, d, &e, &c);


    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    cout << "e = " << e << endl;
    cout << "f = " << f << endl;


    //getchar();



    //int t1 = 9;
    //int t2 = 4;
    //int t3 = 0;

    //cout << "t3 = " << t3 << endl;
    //int* ptrT3 = &t3;
    //*ptrT3 = 5;
    //cout << "t3 = " << t3 << endl;


    //cout << "int* ptr1 = &e = " << ptr1 << endl;
    //cout << "&e = " << &e << endl;




    return 0;
}

int crazy(int x1, int* x2, int& x3, int x4, int* x5, int* x6)
{
    // Parameter list
    // int x1, x4: passed by value (doesnt affect the calling function, stays only in this method)
    // int* x2, x5, x6: its a pointer that currently points to nothing
    // int& x3: passed by reference (whatever modifications haven to x3, the parameter passed will be updated)


    int* temp = x5;
    x5 = x6;
    *x5 = 8;
    *x6 = 6;
    x6 = temp;
    x1 = 9;
    x2 = &x1;
    x3 = 2;
    x4 = *x5 + 6;
    *x5 = x1; 

    return x1 + *x2 + x3 + x4 + *x5;
}

/*

*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu