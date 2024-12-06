#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class Professor : public Person {
private:
    int publications;
    int cur_id;
    static int id;
public:
    Professor() {
        cur_id = ++id;
    }
    void getdata() override {
        cout << "Enter Professor's name, age, and number of publications: ";
        cin >> name >> age >> publications;
    }
    void putdata() override {
        cout << "Professor: " << name << " " << age << " " << publications << " " << cur_id << endl;
    }
};

class Student : public Person {
private:
    int marks[6];
    int cur_id;
    static int id;
public:
    Student() {
        cur_id = ++id;
    }
    void getdata() override {
        cout << "Enter Student's name, age, and marks for 6 subjects: ";
        cin >> name >> age;
        for (int i = 0; i < 6; i++) {
            cin >> marks[i];
        }
    }
    void putdata() override {
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            sum += marks[i];
        }
        cout << "Student: " << name << " " << age << " " << sum << " " << cur_id << endl;
    }
};

int Student::id = 0;
int Professor::id = 0;

int main() {
    int n, val;
    cout << "Enter the number of persons: ";
    cin >> n;

    Person* persons[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter 1 for Professor or 2 for Student: ";
        cin >> val;
        if (val == 1) {
            persons[i] = new Professor();
        } else {
            persons[i] = new Student();
        }
        persons[i]->getdata();
    }

    cout << "\nDetails of Persons:\n";
    for (int i = 0; i < n; i++) {
        persons[i]->putdata();
    }

    // Clean up memory
    for (int i = 0; i < n; i++) {
        delete persons[i];
    }

    return 0;
}
