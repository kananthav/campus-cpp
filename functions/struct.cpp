#include <iostream>
//#include <string.h>

using namespace std;

struct SalesPerson {
  string nim;
  string nama;
  int umur;
} Sales;
//salesPerson ui;

void addSalesPerson() {
  cout << "nim: ";
  cin >> Sales.nim;
}

int main() {
  addSalesPerson();
  cout << Sales.nim;
  return 0;
}
