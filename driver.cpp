#include "number.h"
using namespace std;

int main() {

  binary one, two;
  binary three;

  cout << "Type in two binary numbers to add: ";
  cin >> one;
  cin >> two;
  cout << one << ' ' << two << endl;
  one = one + two;
  cout << "Sum is: " << one << endl;
  cout << one << "is equivalent to " << one.decimal() << endl;

  three = one;
  cout << "The value of 'three' is: " << three << endl;
  three += two;
  cout << "The value of 'three' is now: " << three << endl;
  
  return 0;
}
