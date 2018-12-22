#include<iostream>
#include<vector>

using namespace std;

#include "Order.cpp"
#include "OrderByPhone.cpp"
#include "OrderByInternet.cpp"
#include "Customer.cpp"

int menu() {
  cout << "Welcome to HELP Inventory System " << endl;
  cout << "1.Create Customer" << endl;
  cout << "2.Add Order" << endl;
  cout << "3.Print Statement " << endl;
  cout << "4.Exit" << endl;
  int option;
  cout << "Your Option >>>> ";
  cin >> option;
  return option;
}
vector <Customer> listCustomer;
void addCustomer(vector <Customer> &listCustomer) {
  string name;
  string address;
  int accountNo;
  cout << "Enter Name : ";
  cin >> name;
  cout << "Enter Shipping Address : ";
  cin >> address;
  Customer customer(name,address);
  listCustomer.push_back(customer);
  cout << endl;
  cout << "Customer : " << customer.getAccountName() << " with account No " << customer.getAccountNo() << " has been successfully been created" << endl;
  cout << endl;
}

void addOrder(vector <Customer> &listCustomer) {
  int checkIDs;
  int option;
  bool checkers = false;
  char repeat = 'Y';
  cout << "Enter Customer Account No: ";
  cin >> checkIDs;
  vector<Customer> customers = listCustomer;
  vector<Customer> :: iterator iterCostumers;
  for(iterCostumers = customers.begin(); iterCostumers != customers.end(); iterCostumers++) {
    if (iterCostumers->getAccountNo() == checkIDs) {
      checkers = true;
      while (tolower(repeat) == 'y') {
        cout << "1. Order by Phone" << endl;
        cout << "2. Order by Internet" << endl;
        cout << "Your option >>>> ";
        cin >> option;
        if (option == 1) {
          string sellersNames;
          int sellersPhones;
          double productsTaxs;
          double productsTotals;

          cout << "Enter Clerk Name: ";
          cin >> sellersNames;
          cout << "Enter Phone Number: ";
          cin >> sellersPhones;
          cout << "Enter Tax: RM";
          cin >> productsTaxs;
          cout << "Enter Total: RM";
          cin >> productsTotals;
          OrderByPhone orderPhones = OrderByPhone(productsTaxs, productsTotals, sellersNames, sellersPhones);
          iterCostumers->addOrder(orderPhones);
        } else if(option == 2) {
          string linkURLs;
          double productTaxs;
          double productsTotals;
          cout << "Enter URL: ";
          cin >> linkURLs;
          cout << "Enter Tax: RM";
          cin >> productTaxs;
          cout << "Enter Total: RM";
          cin >> productsTotals;

          OrderByInternet orderInternets = OrderByInternet(productTaxs, productsTotals, linkURLs);
          iterCostumers->addOrder(orderInternets);

        } else {
          cout << "Wrong choice";
        }
        cout << "Do you wish to continue (y/n)";
        cin >> repeat;
      }
      break;
    }
  }

  if(checkers == false) {
    cout << "Account Not Found" << endl;
  }
  listCustomer = customers;
}
void printStatement(vector<Customer> &listCustomer) {
  int checkIDs;
  bool checkers = false;

  vector<Customer> customers = listCustomer;
  vector<Customer>::iterator custPrint;

  cout << "Enter Account No : ";
  cin >> checkIDs;

  for(custPrint = customers.begin(); custPrint != customers.end(); custPrint++) {
    if(custPrint->getAccountNo() == checkIDs) {
      checkers = true;
      custPrint->printAllInfo();
    }
  }

  if (checkers == false) {
    cout << "Account Not Found" << endl;
  }
}

int main() {
  int option;
  do {
    option =menu();
    switch(option) {
      case 1:
        addCustomer(listCustomer);
        break;
      case 2:
        addOrder(listCustomer);
        break;
      case 3:
        printStatement(listCustomer);
        break;
      default:
        cout << "Finished" << endl;
    }
  } while (option <=3);
  return 0;
}
