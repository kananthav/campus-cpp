#include <iostream>

using namespace std;

struct transactions {
  double amount;
  transactions *next;
}; 

typedef transactions *transPtr;

class account {
  private:
    string accountName;
    static const int accountNumber = 10000;
    double accountBalance;
    transPtr listOfTrans;

  public:
    account();
    account(string accName, double accBalance);
    ~account();
    void setAccName(string accName);
    void setAccBalance(double accBalance);
    void addTransaction(double accBalance);
    void printBankStatement();
    string getAccName();
    double getAccBalance();
};

account :: account() {
  accountName = "";
  accountBalance = 0.0;
  listOfTrans = NULL;
}

account :: ~account() {

}

account :: account(string accName, double accBalance) {
  accountName = accName;
  accountBalance = accBalance;
  listOfTrans = NULL;
}

void account :: setAccName(string accName) {
  accountName = accName;
}

void account :: setAccBalance(double accBalance) {
  accountBalance = accBalance;
}

string account :: getAccName() {
  return accountName;
}

double account :: getAccBalance() {
  return accountBalance;
}

void account :: addTransaction(double accBalance) {
  if (accountBalance + accBalance > 100) {
    transactions *transactions = new transactions();
    transactions->amount = accBalance;
    if (listOfTrans == NULL) {
      listOfTrans = transactions;
    } else {
      transactions *helper = new transactions();
      helper = listOfTrans;
      while (helper->next != NULL) {
        helper = helper->next;
      }
      helper->next = transactions;
    }
    accountNumber = accountBalance + accBalance;
  } else {
    cout << "Account not succicient" << endl;
  }
}

void account :: printBankStatement() {
  cout << "Bank Statement" << endl;
  cout << "Account Number: " << accountNumber << endl;
  cout << "Account Name: " << accountName << endl;
  double deposit = 0;
  transactions *helperDeposit = new transactions();
  if (listOfTrans != NULL) {
    helperDeposit = listOfTrans;
    while (helperDeposit != NULL) {
      if (helperDeposit->amount > 0) {
        deposit = deposit + helperDeposit->amount;
      }
      helperDeposit = helperDeposit->next;
    }
  }
  cout << "Deposit: " << deposit << endl;
  double withdrawal = 0;
  transactions *helperWithdrawal = new transactions();
  if (listOfTrans != NULL) {
    helperWithdrawal = listOfTrans;
    while (helperWithdrawal != NULL) {
      if (helperWithdrawal->amount < 0) {
        withdrawal = withdrawal + helperWithdrawal->amount;
      }
      helperWithdrawal = helperWithdrawal->next;
    }
  }
  withdrawal = withdrawal - withdrawal * 2;
  cout << "Withdrawal: " << withdrawal << endl;
  cout << "Account Balance: " << accountBalance << endl;
}

void addAccount(account &user) {
  cout << endl << "Enter Name: ";
  string accName;
  cin >> accName;
  cout << "Enter Balance: ";
  double accBalance;
  cin >> accBalance;
  user.setAccName(accName);
  user.setAccBalance(accBalance);
}

void makeWithdrawal(account &user) {
  cout << endl;
  double amount;
  cout << "Enter withdrawal amount: ";
  cin amount;
  amount *= -1;
  user.addTransaction(amount);
}

void makeDeposit(account &user) {
  cout << endl;
  double amount = 0;
  cout << "Enter deposit amount: ";
  cin >> amount;
  user.addTransaction(amount);
}

void printAccount(account &user) {
  cout << endl;
  user.printBankStatement();
}

int menu() {
  cout << "1. Create new account" << endl;
  cout << "2. Make Withdrawal" << endl;
  cout << "3. Make Deposit" << endl;
  cout << "4. Print Statement" << endl;
  int option;
  cout << "Your option >>>>" << flush;
  cin >> option;
  return option;
}

int main() {

  account customer;
  int option;

  do {
    option = menu();
    switch (option) {
      case 1:
        addAccount(customer);
        break;
      case 2:
        makeWithdrawal(customer);
        break;
      case 3:
        makeDeposit(customer);
        break;
      case 4:
        printAccount(customer);
      default:
        cout << "Bye" << endl;
    }
  } while (option <= 4);

  return 0;
}

