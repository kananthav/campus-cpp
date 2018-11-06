#include <iostream>

using namespace std;
#include "phoneCard.cpp"

int main() {
  // default constructor
  phoneCard xl;
  xl.toString();
  xl.setPhoneNumber("08134556789");
  xl.toString();

  // constructor paramater
  phoneCard As("12345", 10000);
  As.toString();

  // using pointer
  phoneCard *Im3 = new phoneCard("098765", 5000);
  Im3->toString();
  delete Im3;

  return 0;
}
