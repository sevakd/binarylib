#include "number.h"
using namespace std;

int main() {

  binary one, two; //binary objects
  binary three;

  cout << "Type in two binary numbers to add: ";
  cin >> one; //check input overload
  cin >> two;
  one = one + two; //check addition and operator equal overload
  cout << "Sum is: " << one << endl;
  cout << one << " is equivalent to " << one.decimal() << endl; //check binary to decimal conversion

  three = one;
  cout << "The value of 'three' is: " << three << endl;
  three += two; //check operator plus equals overload
  cout << "The value of 'three' is now: " << three << endl;
  
  return 0;
}
