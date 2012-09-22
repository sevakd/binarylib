#ifndef __BINARY_H_INCLUDED__
#define __BINARY_H_INCLUDED__

/* Sevak Deirmendjian
 * 9/9/12
 * Deirmendjian_number.h
 *
 * Library that enables certain operation on binary values (add, convert to base 10)
 *  
 * Input: none (placeholder driver prog for testing)
 * Output: dependent on driver prog
 */

//dependencies
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//class
class binary {
  vector <int> bin; //each digit of input being a seperate element
public:
  binary (){bin.assign(1,0);}; //default constructor (set value to 0)
  binary (vector <int> thebin) //copy constructor
         {bin = thebin;};
  binary operator+ (binary); //addition overload
    /*pre: binary left and binary right operands
      post: returns new binary sum*/
  binary& operator+=(binary); //plus equals overload
    /*pre: binary left and binary right operands
      post: updates left operand to sum*/
  friend ostream& operator<< (ostream&, binary); //output overload
    /*pre: cout left and binary right operands 
      post: prints binary value*/
  friend istream& operator>> (istream&, binary&); //input overload
    /*pre: cin left and binary right operands
      post: updates right operand to given value*/
  int decimal(); //binary to decimal converter
};

#endif // __BINARY_H_INCLUDED__
