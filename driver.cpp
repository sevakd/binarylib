#include "number.h"
using namespace std;

int main() {

  binary one, two; //binary objects
  binary three;

  cout << "Type in two binary numbers to add: ";
  cin >> one; //check input overload
  cin >> two; 
  cout << one << ' ' << two << endl; //check output
  one = one + two; //check operator equal overload
  cout << "Sum is: " << one << endl; //check addition
  cout << one << "is equivalent to " << one.decimal() << endl;

  three = one;
  cout << "The value of 'three' is: " << three << endl;
  three += two;
  cout << "The value of 'three' is now: " << three << endl;
  
  return 0;
}
