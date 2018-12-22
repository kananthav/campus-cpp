class OrderByInternet:public Order {
  private:
    string urlAddress;
  protected:
    void setURLAddress(string newURLAdress) {
      urlAddress = newURLAdress;
    }
  public:
    OrderByInternet(double newTax, double newTotal, string newURLAddres):Order(newTax,newTotal) {
      urlAddress = newURLAddres;
    }
    string getURLAddress() {
      return urlAddress;
    }
    void printOBI() {
      cout << "Order by Internet " << urlAddress;
      printOrder();
    }
};
