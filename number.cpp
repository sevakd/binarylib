#include "number.h"
using namespace std;

//output a binary number
ostream& operator<< (ostream& co, binary b) { //ostream reference and binary object

  vector <int>::iterator itr; //iterate through vector 
  for (itr = b.bin.begin(); itr != b.bin.end(); ++itr){
    co << *itr; //output each element
  }
  
  return co;
}

//input a binary number
istream& operator>> (istream& ci, binary& b) { //istream reference and binary reference
  
  string input; //user input
  ci >> input; //receive string

  b.bin.erase(b.bin.begin()); //erase default value
  
  for (int i = 0; i<input.length(); i++) { //iterate through input string
    b.bin.insert(b.bin.begin() + i, input[i] - '0'); //pass iter loc and string element val to vector element
  }
  
  return ci;
}

//convert to decimal
int binary :: decimal() {
  
  int total = 0;
  vector <int>::iterator itr; //iterate through vector
  for (itr = bin.begin(); itr != bin.end(); ++itr){
    total = total * 2 + *itr; //mult each prev total by 2, add current vector element
  }
  return total;
}

// add binary + binary
binary binary :: operator+ (binary roper) {

  int decLeftOper; //left operand as deciaml
  int decRightOper; //right operand as decimal
  int decSum; //sum as decimal
  binary binSum;

  binSum.bin.erase(binSum.bin.begin()); //erase default value

  //convert left oper to decimal
  decLeftOper = decimal();
 
  //convert right oper to decimal
  decRightOper = roper.decimal();
  
  //add decimal values
  decSum = decLeftOper + decRightOper;

  //convert to binary
  while (decSum != 0) { //divide until 0
    binSum.bin.insert(binSum.bin.begin(), decSum%2); //store remainder in vector
    decSum = decSum / 2; //halve sum
  }
  return binSum; //binary
}

//add right oper to left and assign to left
binary& binary :: operator+= (binary roper) {
  
  *this = roper + *this; //binary addition 

  return *this; //dereference and return
} 
