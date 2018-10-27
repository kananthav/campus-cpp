#include <iostream>
#include <string.h>

using namespace std;

struct SalesPerson {
  string ID;
  double salesbyQuarter[4];
  double totalSales;
  bool checker = false;
};

double calTotalSales(SalesPerson Person) {
  double total = 0.0;
  for (int i = 0; i < 4; i++) {
    total = total + Person.salesbyQuarter[i];
  }
  return total;
}

SalesPerson addSalesPerson(SalesPerson Sales) {
  cout << "Person ID number: ";
  cin >> Sales.ID;
  for (int k = 0; k < 4; k++) {
    cout << "Qty " << k + 1 << " per person: ";
    cin >> Sales.salesbyQuarter[k];
  }
    double total = calTotalSales(Sales);
    Sales.totalSales = total;
    Sales.checker = true;
    return Sales;
}

void detMaxSales(SalesPerson (&Sales)[10]) {
  string highestID;
  double highestSales = 0.0;
  for (int i = 0; i < 10; i ++) {
    if (Sales[i].checker == false) {
      break;
    } else {
      if (highestSales < Sales[i].totalSales) {
        highestSales = Sales[i].totalSales;
        highestID = Sales[i].ID;
      }
    }
  }
  cout << "Max Sale by SalesPerson: ID = " << highestID <<", Amount = RM" << highestSales << endl;
}

void detMaxQuart(SalesPerson (&Sales)[10]) {
  int highestQuart;
  double quart[] = { 0.0, 0.0, 0.0, 0.0 };
  double highestAmount = 0.0;

  double amount = 0.0;
  for (int i = 0; i < 10; i++) {
    if (Sales[i].checker == false) {
      break;
    } else {
      quart[0] = quart[0] + Sales[i].salesbyQuarter[0];
      quart[1] = quart[1] + Sales[i].salesbyQuarter[1];
      quart[2] = quart[2] + Sales[i].salesbyQuarter[2];
      quart[3] = quart[3] + Sales[i].salesbyQuarter[3];
    }
  }
  for (int j = 0; j < 4; j++) {
    if (highestAmount < quart[j]) {
      highestAmount = quart[j];
      highestQuart = j + 1;
    }
  }
  cout << "Max Sale by Quarter: Quarter = " << highestQuart << ", Amount = RM" << highestAmount << endl;
}

void displayReport(SalesPerson Sales[10]) {
  double quart[] = { 0.0, 0.0, 0.0, 0.0 };
  cout << "ID" << "\t";
  cout << "QT1" << "\t";
  cout << "QT2" << "\t";
  cout << "QT3" << "\t";
  cout << "QT4" << "\t";
  cout << "Total" << endl;
  cout << "=============================================" << endl;

  for (int i = 0; i < 10; i++) {
    if (Sales[i].checker == false) {
      break;
      cout << "No data. Please input some" << endl;
    } else {
      quart[0] = quart[0] + Sales[i].salesbyQuarter[0];
      quart[1] = quart[1] + Sales[i].salesbyQuarter[1];
      quart[2] = quart[2] + Sales[i].salesbyQuarter[2];
      quart[3] = quart[3] + Sales[i].salesbyQuarter[3];

      cout << Sales[i].ID << "\t";
      cout << Sales[i].salesbyQuarter[0] << "\t";
      cout << Sales[i].salesbyQuarter[1] << "\t";
      cout << Sales[i].salesbyQuarter[2] << "\t";
      cout << Sales[i].salesbyQuarter[3] << "\t";
      cout << calTotalSales(Sales[i]) << endl;
    }
  }
  cout << "Total" << "\t";
  cout << quart[0] << "\t";
  cout << quart[1] << "\t";
  cout << quart[2] << "\t";
  cout << quart[3] << "\n" << endl;
}

int menu() {
  cout << "1. Enter sales information" << endl;
  cout << "2. Enter sales information report (as per the output defined above)" << endl;
  cout << "3. Exit" << endl;
}

int main() {
  SalesPerson Person[10];
  int counter = 0;
  int option;

  menu();
  cout << "Please choose (1, 2, or 3): ";
  cin >> option;

  do {
    switch (option) {
      case 1:
        if (counter < 10) {
          Person[counter] = addSalesPerson(Person[counter]);
          counter++;
        } else {
          cout << "Sales information is full already!" << endl;
        }
        menu();
        cout << "Please choose (1, 2, or 3): ";
        cin >> option;
        break;
      case 2:
        displayReport(Person);
        detMaxSales(Person);
        detMaxQuart(Person);

        menu();
        cout << "Please choose (1, 2, or 3): ";
        cin >> option;
        break;
      case 3:
        cout << "Thank you!" << endl;
        break;
      default:
        cout << "Invalid number, please try again!" << endl;
        menu();
        cout << "Please choose (1, 2, or 3): ";
        cin >> option;
        break;
    }
  } while(option != 3);

  return 0;

}
