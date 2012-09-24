#ifndef __Deirmendjian_number2_H_INCLUDED__
#define __Deirmendjian_number2_H_INCLUDED__

/* Sevak Deirmendjian
 * 9/24/12
 * Deirmendjian_number2.h
 *
 * Library that enables certain operation on binary, hexadecimal, and octal values (add, convert to base 10)
 *  
 * Input: binary, hex, or octal values (placeholder driver prog for testing)
 * Output: value, value as decimal, or sum of addition (dependent on driver prog)
 */

//dependencies
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class number { //number base class
protected: //grants children access
  vector <int> val; //each digit of input as a seperate int element

  number(){val.assign(1,0);}; //default base constructor
  number(vector <int> theval) //base copy constructor
        {val = theval;};
  friend ostream& operator<< (ostream&, number); //output overload 
    /*pre: cout as left and hex as right operand 
      post: prints hex value*/
  friend istream& operator>> (istream&, number&); //input overload
    /*pre: cin as left and hex as right operand
      post: updates hex to given value*/
};

class binary : public number { //binary subclass
private:
  void native(int dec); //convert decimal to binary
public:
  binary operator+ (binary); //addition overload
    /*pre: binary left and binary right operand
      post: returns new binary sum*/
  binary& operator+=(binary); //addition assignment overload
    /*pre: binary left and binary right operand
      post: updates left operand to sum*/
  binary():number(){}; //subclass constructer with initialization list
  int decimal(); //binary to decimal converter
};

class hexadecimal : public number { //hex subclass
private:
  void native(int dec); //convert decimal to hex
public:
  hexadecimal operator+ (hexadecimal); //addition overload
    /*pre: hex left and hex right operand
      post: returns new hex sum*/
  hexadecimal& operator+=(hexadecimal); //addition assignment overload
    /*pre: hex left and hex right operand
      post: updates left operand to sum*/
  hexadecimal():number(){}; //constr and init list
  int decimal(); //hex to decimal converter
};

class octal : public number { //octal subclass
private:
  void native(int dec); //convert decimal to octal
public:
  octal operator+ (octal); //addition overload
    /*pre: octal left and octal right operand
      post: returns new octal sum*/
  octal& operator+=(octal); //addition assignment overload
    /*pre: octal left and octal right operand
      post: updates left operand to sum*/
  octal():number(){}; //constr and init list
  int decimal(); //octal to decimal converter
};

#endif // __Deirmendjian_number2_H_INCLUDED__
