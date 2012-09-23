#include "number2.h"

//output a number
ostream& operator<< (ostream& co, number n) {
  
  vector <int>::iterator itr; //iterate through vector
  for (itr = n.val.begin(); itr != n.val.end(); ++itr){
    if (*itr > 64){
      char letter = *itr;
      co << letter;
    }
    else{
      co << *itr;
    }
  }
  return co;
}

//input a number
istream& operator>> (istream& ci, number& n) {

  string input;
  ci >> input;

  n.val.erase(n.val.begin());
  
  for (int i = 0; i<input.length(); i++){
    if (isalpha(input[i])){
      n.val.insert(n.val.begin() + i, input[i]);
    }
    else{
      n.val.insert(n.val.begin() + i, input[i] - '0');
    }
  }
  return ci;
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

void binary :: native(int dec){

  while (dec != 0) { //divide until 0
    val.insert(val.begin(), dec%2); //store remainder in vector
    dec = dec / 2; //halve sum
  }
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

//--------------------------------------------hexadecimal class impl

int hexadecimal :: decimal(){

  int total = 0; //dec value

  //convert to decimal
  int i = 0;
  vector<int>::iterator it;
  for ( it=val.end() - 1; it >= val.begin(); it-- ) {
    if (*it<=9){

      total += *it * pow(16,i);
    }
    else{
      //lookup
      total += (*it-55) * pow(16,i);
    }
    i++;
  }
  return total;
}

void hexadecimal :: native(int dec){
  while (dec != 0) { //divide until 0
    if (dec%16<10){
      val.insert(val.begin(), dec%16); //store remainder in vector
    }
    else{
      val.insert(val.begin(), dec%16+55);
    }
    dec = dec / 16; //halve sum
  }
}

//hex add number + number
hexadecimal hexadecimal :: operator+ (hexadecimal roper) {

  int decLeftOper;
  int decRightOper;
  int decSum;
  hexadecimal hexSum;

  hexSum.val.erase(hexSum.val.begin());

  //convert left oper to decimal
  decLeftOper = decimal();

  //convert right oper to decimal
  decRightOper = roper.decimal();

  //add decimal values
  decSum = decLeftOper + decRightOper;

  //convert to native base
  hexSum.native(decSum);

  return hexSum;
}

//add right oper to left and assign to left
hexadecimal& hexadecimal :: operator+= (hexadecimal roper) {

  *this = roper + *this; //binary addition

  return *this;
}

//-------------------------------------octal class impl

int octal :: decimal(){

  int total = 0;
  int i = 0;
  vector <int>::iterator itr; //iterate through vector
  for (itr = val.end() - 1; itr >= val.begin(); itr--){
    total += *itr * pow(8,i); //mult each prev total by 2, add current vector element
    i++;
  }
  return total;
}

void octal :: native(int dec){

  while (dec != 0) { //divide until 0
    val.insert(val.begin(), dec%8); //store remainder in vector
    dec = dec / 8; //halve sum
  }
}

//binary add number + number
octal octal :: operator+ (octal roper) {

  int decLeftOper;
  int decRightOper;
  int decSum;
  octal octSum;

  octSum.val.erase(octSum.val.begin());

  //convert left oper to decimal
  decLeftOper = decimal();

  //convert right oper to decimal
  decRightOper = roper.decimal();

  //add decimal values
  decSum = decLeftOper + decRightOper;

  //convert to native base
  octSum.native(decSum);

  return octSum;
}

//add right oper to left and assign to left
octal& octal :: operator+= (octal roper) {

  *this = roper + *this; //binary addition

  return *this;
}

