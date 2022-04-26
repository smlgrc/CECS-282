// Samuel Garcia
// CECS 282-07
// Prog 5 - goldRabbits: BigInt using vectors and maps
// 5/4/2020

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <limits>
#include <map>

using namespace std;

class BigInt
{
private:
    vector<char> list;
public:
    BigInt();
    BigInt(string);
    BigInt(int x);

    void print();

    BigInt operator+(BigInt);
    BigInt operator-(BigInt);

    BigInt operator++(int);
    BigInt operator+(int);
    BigInt operator-(int);

    bool operator==(BigInt);
    bool operator<=(BigInt B);
    bool operator<(const BigInt&) const;
    bool operator>(const BigInt&) const;

    friend ostream& operator<<(ostream&, BigInt&);
};

BigInt goldRabbits(BigInt);
void pause() { cout << "Press Enter to continue..."; getchar(); }

int main()
{
    BigInt B1("123456789123456789123456789123456789");
    BigInt B2(B1);
    BigInt MAX(INT_MAX);
    cout << "B1:" << B1 << "\nB2:" << B2 << "\nMAX:" << MAX << endl;

    pause();
    cout << "\nB1:";
    B1.print();
    cout << endl;
    pause();
    for (BigInt i = 0; i <= BigInt(3000); i++)
    {
        BigInt GR = goldRabbits(i);
        cout << "\ngoldRabbits(" << i << ") = " << GR; // I had to assign goldRabbits(i) to GR in order to print it out, otherwise I would get an error.
    }
    cout << endl;
    pause();
    cout << "\nThis is the value of goldRabbits(3000)\n\n";
    BigInt gR3000 = goldRabbits(BigInt(3000));
    gR3000.print();
    cout << endl;
    pause();

    return 0;
}

BigInt goldRabbits(BigInt B)
{
    static map<BigInt, BigInt> fiboMap;

    // Presets values for 0 and 1
    fiboMap[BigInt(0)] = 1;
    fiboMap[BigInt(1)] = 1;

    if (B == BigInt(0) || B == BigInt(1))
    {
        fiboMap[B] = BigInt(1);

    }
    else if (fiboMap.find(B) == fiboMap.end()) // if can't find B
    {
        fiboMap[B] = goldRabbits(B - 1) + goldRabbits(B - 2);
    }

    BigInt temp = fiboMap[B];
    return temp;
}

BigInt::BigInt()
{
    list.push_back(0);
}

BigInt::BigInt(string str)
{
    int value;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        value = str.at(i) - '0'; // - '0' subtracts the ASCII value of '0' to the value found at str.at(i)
        list.push_back(value);
    }
}

BigInt::BigInt(int num)
{
    while (num > 9)
    {
        int digit = num % 10;
        list.push_back(digit);
        num = num / 10;
    }
    if (num < 10)
    {
        list.push_back(num);
    }
}

void BigInt::print()
{
    vector<char>::reverse_iterator rit;
    for (rit = list.rbegin(); rit != list.rend(); rit++)
    {
        cout << (int)*rit;
    }
}

bool BigInt::operator==(BigInt B)
{
    BigInt temp(*this);
    if (temp.list.size() == B.list.size())
    {
        for (int i = 0; i < temp.list.size(); i++)
        {
            if (temp.list[i] != B.list[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool BigInt::operator<=(BigInt B)
{
    if (*this < B || *this == B)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool BigInt::operator<(const BigInt& B) const
{
    BigInt temp(*this);
    if (temp.list.size() != B.list.size())
    {
        if (temp.list.size() < B.list.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        for (int i = temp.list.size() - 1; i >= 0; i--)
        {
            if (temp.list[i] != B.list[i])
            {
                if (temp.list[i] < B.list[i])
                {
                    //cout << "Pass" << endl;
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return false;
}

bool BigInt::operator>(const BigInt& B) const
{
    BigInt temp(*this);
    if (temp.list.size() != B.list.size())
    {
        if (temp.list.size() > B.list.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        for (int i = temp.list.size() - 1; i >= 0; i--)
        {
            if (temp.list[i] != B.list[i])
            {
                if (temp.list[i] > B.list[i])
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return false;
}

BigInt BigInt::operator+(BigInt B)
{
    BigInt left(*this);
    BigInt right(B);
    BigInt result(0);
    int largest = 0;
    int sizeDiff = 0;
    int rightSize = right.list.size();
    int leftSize = left.list.size();
    int carry = 0;

    // Finds the largest size BigInt and sets the size to largest
    if (leftSize > rightSize)
    {
        largest = leftSize;
        sizeDiff = largest - rightSize;
        for (int i = 0; i < sizeDiff; i++)
        {
            right.list.push_back(0);
        }
    }
    else if (leftSize < rightSize)
    {
        largest = rightSize;
        sizeDiff = largest - leftSize;
        for (int i = 0; i < sizeDiff; i++)
        {
            left.list.push_back(0);
        }
    }
    // if left or right are equal just grab either (left) and set largest
    else
    {
        largest = leftSize;
    }

    // Initialize the result to match the size of largest value
    for (int i = 0; i < largest - 1; i++)
    {
        result.list.push_back(0);
    }

    //add the two BigInts and set to result
    for (int i = 0; i < largest; i++)
    {
        int temp = left.list[i] + right.list[i] + carry;
        if (temp >= 10)
        {
            carry = 1;
            result.list[i] = temp % 10;
        }
        else
        {
            result.list[i] = temp;
            carry = 0;
        }
    }

    if (carry == 1)
    {
        result.list.push_back(1);
    }

    return result;
}

BigInt BigInt::operator-(BigInt B)
{
    BigInt left(*this);
    BigInt right(B);
    BigInt result(0);
    int largest = 0;
    int sizeDiff = 0;
    int rightSize = right.list.size();
    int leftSize = left.list.size();

    // Finds the largest size BigInt and sets the size to largest
    if (leftSize > rightSize)
    {
        largest = leftSize;
        sizeDiff = largest - rightSize;
        for (int i = 0; i < sizeDiff; i++)
        {
            right.list.push_back(0);
        }
    }
    else if (leftSize < rightSize)
    {
        largest = rightSize;
        sizeDiff = largest - leftSize;
        for (int i = 0; i < sizeDiff; i++)
        {
            left.list.push_back(0);
        }
    }
    // if left or right are equal just grab either (left) and set largest
    else
    {
        largest = leftSize;
    }

    // Initialize the result to match the size of largest value
    for (int i = 0; i < largest - 1; i++)
    {
        result.list.push_back(0);
    }

    // subtract the two BigInts and set to result
    for (int i = 0; i < largest; i++)
    {
        if (left.list[i] < right.list[i])
        {
            // takes 1 away from number next to i and adds it to itself
            left.list[i] += 10;
            left.list[i + 1] -= 1;

            result.list[i] = left.list[i] - right.list[i];
        }
        else
        {
            result.list[i] = left.list[i] - right.list[i];
        }
    }

    // removes leading zeros
    if (result.list[result.list.size() - 1] == 0 && result.list.size() > 1)
    {
        result.list.erase(result.list.end() - 1);
    }

    return result;
}

BigInt BigInt::operator++(int dummy)
{
    *this = *this + BigInt(1);
    return *this;
}

BigInt BigInt::operator+(int n)
{
    return *this + BigInt(n);
}

BigInt BigInt::operator-(int n)
{
    return *this - BigInt(n);
}

ostream& operator<<(ostream& out, BigInt& B)
{
    vector<char>::reverse_iterator rit;

    for (rit = B.list.rbegin(); rit != B.list.rend(); rit++)
    {
        if (B.list.size() <= 12)
        {
            out << (int)*rit;
        }
        else
        {
            out << (int)B.list[B.list.size() - 1] << ".";

            int digitCounter = 0;
            for (int i = B.list.size() - 2; i > 0; i--)
            {
                out << (int)B.list[i];
                digitCounter++;
                if (digitCounter > 8)
                {
                    out << "e" << B.list.size();
                    return out;
                }
            }
        }
    }
    return out;
}