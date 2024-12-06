#include <iostream>
#include <string>
#include <exception>
using namespace std;

class BadLengthException : public exception {
private:
    int n;
public:
    BadLengthException(int length) : n(length) {}

    int what() {
        return n;
    }
};

bool checkUsername(string username) {
    bool isValid = true;
    int n = username.length();
    if (n < 5) {
        throw BadLengthException(n);
    }
    for (int i = 0; i < n - 1; i++) {
        if (username[i] == 'w' && username[i + 1] == 'w') {
            isValid = false;
        }
    }
    return isValid;
}

int main() {
    int T;
    cout << "Enter the number of usernames: ";
    cin >> T;
    while (T--) {
        string username;
        cout << "Enter username: ";
        cin >> username;
        try {
            bool isValid = checkUsername(username);
            if (isValid) {
                cout << "Valid" << endl;
            } else {
                cout << "Invalid" << endl;
            }
        } catch (BadLengthException e) {
            cout << "Too short: " << e.what() << endl;
        }
    }
    return 0;
}
