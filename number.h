#ifndef __BINARY_H_INCLUDED__
#define __BINARY_H_INCLUDED__

//dependencies
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//class
class binary {
  vector <int> bin;
public:
  binary (){}; //constructor
  binary operator+ (binary);
  binary& operator+=(binary);
  friend ostream& operator<< (ostream&, binary);
  friend istream& operator>> (istream&, binary&);
  int decimal();
};
#endif // __BINARY_H_INCLUDED__
