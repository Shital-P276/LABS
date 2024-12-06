#include <iostream>
#include <string>
using namespace std;

template <class T>
class AddElements {
    T element;
public:
    AddElements(T arg) : element(arg) {}
    T add(T arg) { return element + arg; }
};

template<>
class AddElements<string>{
    string element;
public:
    AddElements(string arg) : element(arg) {}
    string concatenate(string arg) { return element + arg; }
};

int main() {
    // Test case 1: Adding two doubles
    double element1 = 5.5, element2 = 3.3;
    AddElements<double> myfloat(element1);
    cout << "Result (float): " << myfloat.add(element2) << endl;

    // Test case 2: Adding two integers
    int element3 = 10, element4 = 20;
    AddElements<int> myint(element3);
    cout << "Result (int): " << myint.add(element4) << endl;

    // Test case 3: Concatenating two strings
    string element5 = "Hello", element6 = " World";
    AddElements<string> mystring(element5);
    cout << "Result (string): " << mystring.concatenate(element6) << endl;

    return 0;
}
