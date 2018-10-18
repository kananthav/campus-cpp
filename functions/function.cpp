#include <iostream>

using namespace std;

void pangkatDua(double *bil) {
  double hasil = *bil * *bil;
  //return hasil;
  cout << hasil;
}

void bintang() {
  cout << "*****";
  cout << endl;

  for (int i = 0; i < 10; i++) {
    for (int j = i; j < 10; j++) {
      cout << "^";
    }
    cout << endl;
  }
}

int main() {
  bintang();
  cout << endl;
  double angka = 2.5;
  pangkatDua(&angka);
  cout << endl;

  return 0;
}
