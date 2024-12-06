#include <iostream>

using namespace std;

// Base class Rectangle
class Rectangle {
public:
    int width;
    int height;

    void display() {
        cout << "Width: " << width << ", Height: " << height << endl;
    }
};

// Derived class RectangleArea
class RectangleArea : public Rectangle {
public:
    void read_input() {
        cout << "Enter width and height: ";
        cin >> width >> height;
    }

    void display() {
        cout << "Area: " << width * height << endl;
    }
};

int main() {
    // Create a RectangleArea object
    RectangleArea r_area;

    // Read the width and height
    r_area.read_input();

    // Display the width and height
    r_area.Rectangle::display();

    // Display the area
    r_area.display();

    return 0;
}
