/*
Author Details: 
  Shital Manoj Patil
  2324001011
  SY B77

Program Details : 
  Sub  : OOP
  Name : Assignment 09 - Operator Overloading
*/

#include <iostream>
using namespace std;

class Student
{
private:
    int fees;

public:
    Student(int studentFees = 0) : fees(studentFees) {}

    Student &operator++()
    {
        ++fees;
        return *this;
    }

    Student operator+(const Student &other)
    {
        return Student(fees + other.fees);
    }

    bool operator==(const Student &other) const
    {
        return fees == other.fees;
    }

    friend ostream &operator<<(ostream &os, const Student &student)
    {
        os << "Fees: $" << student.fees;
        return os;
    }

    friend istream &operator>>(istream &is, Student &student)
    {
        cout << "Enter student fees: ";
        is >> student.fees;
        return is;
    }
};

int main()
{
    cout << "Unary Operator (Pre-increment)\n------------------------------------" << endl;
    Student s1(1000);
    cout << "Before pre-increment: " << s1 << endl;
    ++s1;
    cout << "After pre-increment: " << s1 << endl;

    cout << "\n\nBinary Operator (Addition)\n------------------------------------" << endl;
    Student s2(2000);
    Student s3(3000);
    Student s4 = s2 + s3;
    cout << "s2 + s3: " << s4 << endl;

    cout << "\n\nComparative Operator (Equality)\n------------------------------------" << endl;
    cout << "s2 == s3: " << (s2 == s3) << endl;

    cout << "\n\nStream Operators\n------------------------------------" << endl;
    Student dynamicStudent;
    cin >> dynamicStudent;
    cout << "Entered Student: " << dynamicStudent << endl;

    return 0;
}
