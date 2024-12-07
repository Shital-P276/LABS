#include <iostream>
using namespace std;

class Sample {
    int value;

public:
    // Constructor to initialize the object
    Sample(int v) : value(v) {}

    // Default constructor
    Sample() : value(0) {}

    // Getter to access the value
    int getValue() const {
        return value;
    }

    // Overload the << operator for printing
    friend ostream& operator<<(ostream& os, const Sample& obj) {
        os << obj.value;
        return os;
    }

    // Template function for operator+
    template <typename T>
    friend Sample operator+(T lhs, const Sample& rhs) {
        Sample temp;
        temp.value = lhs + rhs.value; // Add lhs to the Sample object's value
        return temp;
    }
};

int main() {
    Sample s(5);        // Sample object with value 5

    // Use operator+ with different types as the first operand
    Sample result1 = 1 + s;         // int + Sample
    Sample result2 = 3.5 + s;       // float + Sample
    Sample result3 = 'A' + s;       // char (ASCII value of 'A') + Sample

    // Print the results
    cout << "Result 1: " << result1 << endl;
    cout << "Result 2: " << result2 << endl;
    cout << "Result 3: " << result3 << endl;

    return 0;
}
