/* Sevak Deirmendjian
 * 9/9/12
 * Deirmendjian_driver.cpp
 *
 * Program that enables certain operation on binary values (add, convert from base 10)
 *  
 * Input: none (placeholder driver prog for testing)
 * Output: dependent on driver prog
 */

#include <iostream>
using namespace std;

class binary {
  char bin [20];
public:
  binary (){};
  binary operator+ (binary);
  friend ostream& operator<< (ostream&, binary);
  friend istream& operator>> (istream&, binary&);
};

//output a binary number
ostream& operator<< (ostream& co, binary b) {

  co << b.bin;
  return co;
}

//input a binary number
istream& operator>> (istream& ci, binary& b) {
  
  ci >> b.bin;
  return ci;
}

/*// add binary + binary
binary binary :: operator+ (binary roper) {

  binary sum;

  return sum;
}*/

int main() {

  binary one, two;
  binary three;

  cout << "Type in two binary numbers to add: ";
  cin >> one;
  cin >> two;
  cout << one << ' ' << two << endl;
  //one = one + two;
  //cout << "Sum is: " << one << endl;
  
  return 0;
}
