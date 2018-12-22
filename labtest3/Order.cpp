class Order {
  private:
    int orderID;
    static int autoNum;
  protected:
    double tax;
    double total;
    void setOrderID(int newOrderID) {
      orderID = newOrderID;
    }
    void setTax(double newTax) {
      tax = newTax;
    }
    void setTotal(double newTotal) {
      total = newTotal;
    }
  public:
    Order(double newTax, double newTotal) {
      orderID = autoNum;
      tax = newTax;
      total = newTotal;
      autoNum++;
    }
    int getOrderID() {
      return orderID;
    }
    double getTax() {
      return tax;
    }
    double getTotal() {
      return total;
    }
    void printOrder() {
      cout << "Order ID : " << orderID << "\t\tTax : RM" << tax << "\t\tTotal : RM" << total << endl;
    }
};
int Order :: autoNum = 10000;
