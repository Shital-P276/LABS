#include <iostream>

using namespace std;

class A {
public:
    A() : callA(0) {}

protected:
    void func(int &a) {
        a = a * 2;
        inc();
    }

    int getA() const {
        return callA;
    }

private:
    int callA;
    void inc() {
        callA++;
    }
};

class B {
public:
    B() : callB(0) {}

protected:
    void func(int &a) {
        a = a * 3;
        inc();
    }

    int getB() const {
        return callB;
    }

private:
    int callB;
    void inc() {
        callB++;
    }
};

class C {
public:
    C() : callC(0) {}

protected:
    void func(int &a) {
        a = a * 5;
        inc();
    }

    int getC() const {
        return callC;
    }

private:
    int callC;
    void inc() {
        callC++;
    }
};

class D : public A, public B, public C {
    int val;

public:
    // Initially val is 1
    D() : val(1) {}

    // Implement this function
    void update_val(int new_val) {
        while (val < new_val) {
            if (new_val % val == 0) {
                if ((new_val / val) % 2 == 0) {
                    A::func(val); // Multiply by 2
                } else if ((new_val / val) % 3 == 0) {
                    B::func(val); // Multiply by 3
                } else if ((new_val / val) % 5 == 0) {
                    C::func(val); // Multiply by 5
                }
            } else {
                break;
            }
        }
    }

    // For Checking Purpose
    void check(int new_val) {
        update_val(new_val);
        cout << "Value = " << val << endl;
        cout << "A's func called " << getA() << " times " << endl;
        cout << "B's func called " << getB() << " times" << endl;
        cout << "C's func called " << getC() << " times" << endl;
    }
};

int main() {
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);
    return 0;
}
