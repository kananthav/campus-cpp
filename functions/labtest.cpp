#include <iostream>
#include <string.h>

using namespace std;

struct SalesPerson {
  string ID;
  double salesbyQuarter[4];
  double totalSales;
  bool checker;
} Sales;

double calTotalSales(Sales) {
  double total = 0;
  for (int i = 0; i < 4; i++) {
    total = total + Sales.salesbyQuarter[i];
  }
  return total;
}

SalesPerson addSalesPerson(Sales) {
  cout << "Person ID number " << ":" << endl;
  cin >> Sales.ID;
  for (int k = 0; k < 4; k++) {
    cout << "Qty " << k << " per person :" << endl;
    cin >> Sales.salesbyQuarter[k];
  }
    double total = calTotalSales(Sales);
    Sales.totalSales = total;
    Sales.checker = true;
    return Sales;
}

void menu() {
  cout << "1. Enter sales information" << endl;
  cout << "2. Enter sales informationeport (as per the output defined above)" << endl;
  cout << "3. Exit" << endl;
}

int main() {
  int counter = 0;
  Sales[10];
  int option;

  menu();
  cout << "Please choose (1, 2, or 3): ";
  cin >> option;

  switch (option) {
    case 1:
      if (counter < 10) {
        Sales[counter] = addSalesPerson(Sales[counter]);
        counter++;
      } else {
        cout << "Sales information is full already!" << endl;
      }
      menu();
      cout << "Please choose (1, 2, or 3): ";
      cin >> option;
      break;
    case 2:
      cout << "u picked 2" << endl;
      break;
    case 3:
      cout << "u picked 3" << endl;
      break;
    default:
      cout << "thank you" << endl;
      break;
  }
  return 0;
}
