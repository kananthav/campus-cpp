class Customer {
  private:
    int accountNo;
    static int autoNum;
    string accountName;
    string shippingAdd;
    vector<OrderByPhone> listOfOrderPhone;
    vector<OrderByInternet> listOfOrderInternet;
  public:
    Customer(string accountName, string shippingAdd) {
      accountNo = autoNum;
      accountName = accountName;
      shippingAdd = shippingAdd;
      autoNum++;
    }
    void setAccountNo(int accountNo) {
      accountNo = accountNo;
    }
    void setAccountName(string accountName) {
      accountName = accountName;
    }
    void setShippingAdd(string shippingAdd) {
      shippingAdd = shippingAdd;
    }
    int getAccountNo() {
      return accountNo;
    }
    string getAccountName() {
      return accountName;
    }
    string getShippingAdd() {
      return shippingAdd;
    }
    void addOrder(OrderByPhone Phone) {
      listOfOrderPhone.push_back(Phone);
    }
    void addOrder(OrderByInternet Internet) {
      listOfOrderInternet.push_back(Internet);
    }
    void printAllInfo() {
      double AllTotal = 0;
      double AllTax = 0;

      vector<OrderByPhone> byPhoneX = listOfOrderPhone;
      vector<OrderByPhone>::iterator phoneX;

      vector<OrderByInternet> byInternetY = listOfOrderInternet;
      vector<OrderByInternet>::iterator internetY;

      cout << "Account No: " << accountNo << endl;
      cout << "Account Name: " << accountName << endl;
      cout << endl;
      for (phoneX = byPhoneX.begin(); phoneX != byPhoneX.end(); phoneX++) {
        phoneX->printOBP();
        AllTax = AllTax + phoneX->getTax();
        AllTotal = AllTotal + phoneX->getTotal();
        cout << endl;
      }
      for (internetY = byInternetY.begin(); internetY != byInternetY.end(); internetY++) {
        internetY->printOBI();
        AllTax = AllTax + internetY->getTax();
        AllTotal = AllTotal + internetY->getTotal();
        cout << endl;
      }

      cout << "Total Tax Payable : RM" << AllTax << endl;
      cout << "Total Payment : RM" << AllTotal << endl;

    }

};
int Customer :: autoNum = 10000;
