#include "number2.h"

int main(){
  hexadecimal meow, moo, s;
  cin >> meow;
  cin >> moo;
  meow += moo;
  cout << "sum " << meow << endl;
  s = meow;
  cout<< "as dec: " << s.decimal() <<endl;
  
  return 0;
}
