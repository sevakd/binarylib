#ifndef __BINARY_H_INCLUDED__
#define __BINARY_H_INCLUDED__

/* Sevak Deirmendjian
 * 9/24/12
 * Deirmendjian_number2.h
 *
 * Library that enables certain operation on binary, hexadecimal, and octal values (add, convert to base 10)
 *  
 * Input: none (placeholder driver prog for testing)
 * Output: dependent on driver prog
 */

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class number {
protected:
  
  vector <int> val;

  number(){val.assign(1,0);}; //default constructor
  number(vector <int> theval) //copy constructor
        {val = theval;};
  friend ostream& operator<< (ostream&, number); //output overload 
  friend istream& operator>> (istream&, number&); //input overload
  int decimal();
  number native(int forSum){};
};

class binary : public number {
private:
  void native(int dec);
public:
  binary operator+ (binary); //addition overload
  binary& operator+=(binary); //addition assignment overload
  binary(){};
  int decimal();
};

class hexadecimal : public number {
private:
  void native(int dec);
public:
  hexadecimal operator+ (hexadecimal); //addition overload
  hexadecimal& operator+=(hexadecimal); //addition assignment overload
  hexadecimal(){};
  int decimal();
};


class octal : public number {
private:
  void native(int dec);
public:
  octal operator+ (octal); //addition overload
  octal& operator+=(octal); //addition assignment overload
  octal(){};
  int decimal();
};
#endif // __BINARY_H_INCLUDED__
