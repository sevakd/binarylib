#include "number2.h"

//output a number
ostream& operator<< (ostream& co, number n) {
  
  vector <int>::iterator itr; //iterate through vector
  for (itr = n.val.begin(); itr != n.val.end(); ++itr){
    co << *itr;
  }
  return co;
}

//input a number
istream& operator>> (istream& ci, number& n) {

  string input;
  ci >> input;

  n.val.erase(n.val.begin());

  for (int i = 0; i<input.length(); i++){
    n.val.insert(n.val.begin() + i, input[i] - '0');
  }
  return ci;
}

//binary add number + number
binary binary :: operator+ (binary roper) {

  int decLeftOper;
  int decRightOper;
  int decSum;
  binary binSum;

  binSum.val.erase(binSum.val.begin());

  //convert left oper to decimal
  decLeftOper = decimal();

  //convert right oper to decimal
  decRightOper = roper.decimal();

  //add decimal values
  decSum = decLeftOper + decRightOper;

  //convert to native base
  binSum.native(decSum);

  return binSum;
}

//add right oper to left and assign to left
binary& binary :: operator+= (binary roper) {

  *this = roper + *this; //binary addition

  return *this;
}

//-------------------------------------binary class impl

int binary :: decimal(){

  int total = 0;
  vector <int>::iterator itr; //iterate through vector
  for (itr = val.begin(); itr != val.end(); ++itr){
    total = total * 2 + *itr; //mult each prev total by 2, add current vector element
  }
  return total;
}

void binary :: native(int forSum){
  while (forSum != 0) { //divide until 0
    val.insert(val.begin(), forSum%2); //store remainder in vector
    forSum = forSum / 2; //halve sum
  }
}
