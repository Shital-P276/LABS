#include <iostream>
using namespace std;

class Student {
private:
    int scores[5];
    int sum;

public:
    Student() : sum(0) {}

    int calculateTotalScore() {
        return sum;
    }

    void input() {
        cout << "Enter scores for 5 subjects: ";
        for (int i = 0; i < 5; i++) {
            cin >> scores[i];
            sum += scores[i];
        }
    }
};

int main() {
    int n; // number of students
    cout << "Enter the number of students: ";
    cin >> n;

    Student *students = new Student[n]; // an array of n students

    for (int i = 0; i < n; i++) {
        cout << "Entering data for student " << i + 1 << ":\n";
        students[i].input();
    }

    // Calculate Kristen's score
    int kristen_score = students[0].calculateTotalScore();

    // Determine how many students scored higher than Kristen
    int count = 0;
    for (int i = 1; i < n; i++) {
        int total = students[i].calculateTotalScore();
        if (total > kristen_score) {
            count++;
        }
    }

    // Print result
    cout << "Number of students scoring higher than Kristen: " << count << endl;

    delete[] students;
    return 0;
}
