#include <iostream>
using namespace std;

struct example {
  unsigned char flag : 1;
};

int main() {
  int number;
  struct example e;

  cout << "Enter a number: ";
  cin >> number;

  if (number % 2 == 0) {
    e.flag = 1;
  } else {
    e.flag = 0;
  }
  // cout is assuming e.falg as a boolean value so using  type casting we convert it to an int for printing
  cout << "Flag is: " << (int)e.flag << endl;
}