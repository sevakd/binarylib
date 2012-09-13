#ifndef __BINARY_H_INCLUDED__
#define __BINARY_H_INCLUDED__

//dependencies
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//class
class binary {
  vector <int> bin; //each digit of intput being a seperate element
public:
  binary (){}; //constructor
  binary operator+ (binary); //addtion overload
  binary& operator+=(binary); //plus equals overload
  friend ostream& operator<< (ostream&, binary); //output overload
  friend istream& operator>> (istream&, binary&); //input overload
  int decimal(); //binary to decimal converter
};
#endif // __BINARY_H_INCLUDED__
