/* Sevak Deirmendjian
 * 9/9/12
 * Deirmendjian_driver.cpp
 *
 * Program that enables certain operation on binary values (add, convert from base 10)
 *  
 * Input: none (placeholder driver prog for testing)
 * Output: dependent on driver prog
 */

#include "number.h"
using namespace std;

//output a binary number
ostream& operator<< (ostream& co, binary b) {

  vector <int>::iterator itr;
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
    b.bin.insert(b.bin.begin() + i, input[i] - '0');
  }
  //cout << b.bin[0] << endl; 
  return ci;
}

//convert to decimal
int binary :: decimal() {
  
  int total = 0;
  vector <int>::iterator itr;
  for (itr = bin.begin(); itr != bin.end(); ++itr){
    total = total * 2 + *itr;
  }
  return total;
}

// add binary + binary
binary binary :: operator+ (binary roper) {

  int decLeftOper;
  int decRightOper;
  int decSum;
  binary binSum;

  //convert left oper to decimal
  int ltotal = 0;
  vector <int>::iterator itr;
  for (itr = bin.begin(); itr != bin.end(); ++itr){
    ltotal = ltotal * 2 + *itr;
  }
  decLeftOper = ltotal;
 
  //convert right oper to decimal
  int rtotal = 0;
  vector <int>::iterator itr2;
  for (itr2 = roper.bin.begin(); itr2 != roper.bin.end(); ++itr2){
    rtotal = rtotal * 2 + *itr2;
  }
  decRightOper = rtotal;
  
  //add decimal values
  decSum = decLeftOper + decRightOper;

  //convert to binary
  int i = 0;
  while (decSum != 0) {
    binSum.bin.insert(binSum.bin.begin() + i, decSum%2);
    decSum = decSum / 2;
  }

  return binSum;
}

binary& binary :: operator+= (binary roper) {
  
  *this = roper + *this;

  return *this;
} 
