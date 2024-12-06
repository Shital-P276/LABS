#include <iostream>
using namespace std;

class Box {
private:
    int l, b, h;

public:
    // Default constructor
    Box() : l(0), b(0), h(0) {}

    // Parameterized constructor
    Box(int length, int breadth, int height) : l(length), b(breadth), h(height) {}

    // Copy constructor
    Box(const Box& B) : l(B.l), b(B.b), h(B.h) {}

    // Getters
    int getLength() { return l; }
    int getBreadth() { return b; }
    int getHeight() { return h; }

    // Calculate volume
    long long CalculateVolume() { return (long long)l * b * h; }

    // Overload < operator
    friend bool operator<(Box& A, Box& B);

    // Overload << operator
    friend ostream& operator<<(ostream& output, const Box& B);
};

bool operator<(Box& A, Box& B) {
    if ((A.l < B.l) || ((A.b < B.b) && (A.l == B.l)) || ((A.h < B.h) && (A.l == B.l) && (A.b == B.b))) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& output, const Box& B) {
    output << B.l << " " << B.b << " " << B.h;
    return output;
}

void check2() {
    int n;
    cout << "Enter the number of operations: ";
    cin >> n;

    Box temp;
    for (int i = 0; i < n; i++) {
        int type;
        cout << "Enter operation type: ";
        cin >> type;

        if (type == 1) {
            cout << "Current Box: " << temp << endl;
        }
        if (type == 2) {
            int l, b, h;
            cout << "Enter dimensions (length breadth height): ";
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << "Updated Box: " << temp << endl;
        }
        if (type == 3) {
            int l, b, h;
            cout << "Enter dimensions to compare (length breadth height): ";
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp) {
                cout << "Lesser\n";
            } else {
                cout << "Greater\n";
            }
        }
        if (type == 4) {
            cout << "Volume of Box: " << temp.CalculateVolume() << endl;
        }
        if (type == 5) {
            Box NewBox(temp);
            cout << "Copied Box: " << NewBox << endl;
        }
    }
}

int main() {
    check2();
    return 0;
}
