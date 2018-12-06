#include <iostream>

using namespace std;

class Komputer {
  private:
    string merk;
    int storage;
  public:
    Komputer(string merk2, int storage2);
    string getMerk();
    int getStorage();
    void setMerk(string merk2);
    void setStorage(int storage2);
    void tampilkan();
};

Komputer :: Komputer(string merk2, int storage2) {
  merk = merk2;
  storage = storage2;
}

string Komputer :: getMerk() {
  return merk;
}

int Komputer :: getStorage() {
  return storage;
}

void Komputer :: setMerk(string merk2) {
  merk = merk2;
}

void Komputer :: setStorage(int storage2) {
  storage = storage2;
}

void Komputer :: tampilkan() {
  cout << merk;
  cout << storage;
}
