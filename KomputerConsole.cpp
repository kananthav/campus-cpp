#include <iostream>

using namespace std;
#include "Komputer.cpp"

int main() {
  Komputer asus("toshiba", 400);
  asus.setMerk("asus");
  asus.setStorage(10);
  asus.tampilkan();
  
  return 0;
}
