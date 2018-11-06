class phoneCard {

  private:
    string phoneNumber;
    double balance;

  public:
    phoneCard() {
      phoneNumber = "";
      balance = 0;
    }

    phoneCard(string num, double sal) {
      phoneNumber = num;
      balance = sal;
    }

  string getPhoneNumber() {
    return phoneNumber;
  }

  double getBalance() {
    return balance;
  }

  void setPhoneNumber(string num) {
    phoneNumber = num;
  }

  void setBalance(double sal) {
    balance = sal;
  }

  void toString() {
    cout << "nomor tlp " << phoneNumber << " memiliki saldo " << balance << endl;
  }

};
