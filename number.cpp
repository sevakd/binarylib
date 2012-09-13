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
#include <vector>
#include <string>
using namespace std;

class binary {
  vector <char> bin;
public:
  binary (){};
  binary operator+ (binary);
  friend ostream& operator<< (ostream&, binary);
  friend istream& operator>> (istream&, binary&);
};

//output a binary number
ostream& operator<< (ostream& co, binary b) {

  vector <char>::iterator itr;
  for (itr = b.bin.begin(); itr != b.bin.end(); ++itr){
    co << *itr;
  }
  //co << b.bin;
  return co;
}

//input a binary number
istream& operator>> (istream& ci, binary& b) {
  
  string input;
  ci >> input; 
  
  for (int i = 0; i<input.length(); i++) {
    b.bin.insert(b.bin.begin() + i, input[i]);
  }
  
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
