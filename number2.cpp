#include "number2.h"

//output a number
ostream& operator<< (ostream& co, number n) { //ostream reference and number object
  
  vector <int>::iterator itr; //iterate through vector
  for (itr = n.val.begin(); itr != n.val.end(); ++itr){
    if (*itr > 9){ //if element is multiple digits
      char letter = *itr; //convert as ascii to char
      co << letter; //output letter
    }
    else{
      co << *itr; //output element
    }
  }
  return co; //return reference
}

//input a number
istream& operator>> (istream& ci, number& n) { //istream reference and number reference

  string input;
  ci >> input; //store input as str
  int element; //value to insert into vector

  n.val.erase(n.val.begin()); //remove default value (set in base constructor)
  
  for (int i = 0; i<input.length(); i++){ //loop through input str
    if (isalpha(input[i])){ //if char is a letter
      element = input[i]; //store ascii value
    }
    else{ //char is a digit
      element = input[i] - '0'; //convert to int and store 
    }
    n.val.insert(n.val.begin() + i, element); //insert element into val loc
  }
  return ci; //return reference
}

//-------------------------------------binary class
int binary :: decimal(){ //convert to decimal

  int total = 0; //decimal value
  vector <int>::iterator itr; //iterator
  for (itr = val.begin(); itr != val.end(); ++itr){ //iter through vector
    total = total * 2 + *itr; //mult each prev total by 2, add current vector element
  }
  return total; //return as decimal
}

void binary :: native(int dec){ //convert to binary

  while (dec != 0) { //divide until 0
    val.insert(val.begin(), dec%2); //store remainder in vector
    dec /= 2; //halve and update sum
  }
}

//binary add number + number
binary binary :: operator+ (binary roper) {

  int decLeftOper; //left operand as decimal
  int decRightOper; //right as dec
  int decSum; //sum of dec operands
  binary binSum; //sum in binary

  binSum.val.erase(binSum.val.begin()); //remove default val of 0

  //convert left oper to decimal
  decLeftOper = decimal();

  //convert right oper to decimal
  decRightOper = roper.decimal();

  //add decimal values
  decSum = decLeftOper + decRightOper;

  //convert to native base
  binSum.native(decSum);

  return binSum; //return binary sum
}

//add right oper to left and assign to left
binary& binary :: operator+= (binary roper) {

  *this = roper + *this; //binary addition

  return *this; //dereference and return updated left operand
}

//---------------------------------hexadecimal class
int hexadecimal :: decimal(){ //convert to decimal

  int total = 0; //dec value
  int element; //hex digit

  int i = 0; //counter for exponent
  vector<int>::iterator it;
  for ( it=val.end() - 1; it >= val.begin(); it-- ) { //iter backwards through vector
    if (*it>9){ //if element is multiple digits
      element = *it-55; //convert element(ascii val to hex letter as dec)
    }
    else{
      element = *it; //store element
    }
    total += element * pow(16,i); //convert to dec and add to total
    i++; //increment counter
  }
  return total; //return as decimal
}

void hexadecimal :: native(int dec){

  int element; //hex digit

  while (dec != 0) { //divide until 0
    if (dec%16>9){ //if remainder(hex digit) is multiple dec digits(checking if letter)
      element = dec%16+55; //convert dec equiv of hex letter to ascii
    }
    else{
      element = dec%16; //store remainder(hex digit) in vector
    }
    val.insert(val.begin(), element);
    dec /= 16; //divide and update sum
  }
}

//hex add number + number
hexadecimal hexadecimal :: operator+ (hexadecimal roper) {

  int decLeftOper; //left operand as decimal
  int decRightOper; //right as dec
  int decSum; //sum of dec operands
  hexadecimal hexSum; //sum as hex

  hexSum.val.erase(hexSum.val.begin()); //remove default value

  //convert left oper to decimal
  decLeftOper = decimal();

  //convert right oper to decimal
  decRightOper = roper.decimal();

  //add decimal values
  decSum = decLeftOper + decRightOper;

  //convert to native base
  hexSum.native(decSum);

  return hexSum; //return sum as hex
}

//add right oper to left and assign to left
hexadecimal& hexadecimal :: operator+= (hexadecimal roper) {

  *this = roper + *this; //binary addition

  return *this; //dereference and return updated left operand
}

//-----------------------------------octal class impl
int octal :: decimal(){ //convert to decimal

  int total = 0; //val as dec

  int i = 0; //counter for exponent
  vector <int>::iterator itr; //iterator
  for (itr = val.end() - 1; itr >= val.begin(); itr--){ //iter backwards through vector
    total += *itr * pow(8,i); //mult each element by 8^counter, add to total
    i++; //increment counter
  }
  return total; //as decimal
}

void octal :: native(int dec){ //convert to octal

  while (dec != 0) { //divide until 0
    val.insert(val.begin(), dec%8); //store remainder in vector
    dec /= 8; //divide and update sum
  }
}

//octal add number + number
octal octal :: operator+ (octal roper) {

  int decLeftOper; //left operand as decimal
  int decRightOper; //right as dec
  int decSum; //sum of dec operands
  octal octSum; //sum in octal

  octSum.val.erase(octSum.val.begin()); //remove default val

  //convert left oper to decimal
  decLeftOper = decimal();

  //convert right oper to decimal
  decRightOper = roper.decimal();

  //add decimal values
  decSum = decLeftOper + decRightOper;

  //convert to native base
  octSum.native(decSum);

  return octSum; //as octal
}

//add right oper to left and assign to left
octal& octal :: operator+= (octal roper) {

  *this = roper + *this; //binary addition

  return *this; //dereference and return updated left operand
}
