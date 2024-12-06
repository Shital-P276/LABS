#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(const string& first_name, const string& last_name)
        : first_name_(first_name), last_name_(last_name) {}

    const string& get_first_name() const {
        return first_name_;
    }

    const string& get_last_name() const {
        return last_name_;
    }

private:
    string first_name_;
    string last_name_;
};

ostream& operator<<(ostream& os, const Person& pr) {
    os << "first_name=" << pr.get_first_name() << ",last_name=" << pr.get_last_name();
    return os;
}

int main() {
    string first_name, last_name, event;

    // Prompt for user input
    cout << "Enter first name: ";
    cin >> first_name;
    cout << "Enter last name: ";
    cin >> last_name;
    cout << "Enter event: ";
    cin >> event;

    Person p(first_name, last_name);

    // Display the person's information and the event
    cout << p << " " << event << endl;

    return 0;
}
