class OrderByPhone : public Order {
  private:
    string clerkName;
    int phoneNumber;
  protected:
    void setClerkName(string newClerkName) {
      clerkName = newClerkName;
    }
    void setPhoneNumber(int newPhoneNumber) {
      phoneNumber = newPhoneNumber;
    }
  public:
    OrderByPhone(double newTax, double newTotal, string newClerkName, int newPhoneNumber):Order(newTax, newTotal) {
    clerkName = newClerkName;
    phoneNumber = newPhoneNumber;
  }
    string getClerkName() {
      return clerkName;
    }
    int getPhoneNumber() {
      return phoneNumber;
    }
    void printOBP() {
      printOrder();
      cout << "Order By Phone with clerk ID " << clerkName << " Phone Number " << phoneNumber << endl;
    }
};
