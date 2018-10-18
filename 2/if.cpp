#include <iostream>

using namespace std;

int main() {
  int pilihan;
  cout << "menu" << endl;
  cout << "1. makanan" << endl;
  cout << "2. minuman" << endl;
  cout << "3. cemilan" << endl;
  cout << "pilih 1, 2, atau 3: ";
  cin >> pilihan;

  if (pilihan == 1) {
    cout << "makanan";
  } else if (pilihan == 2) {
    cout << "minuman";
  } else {
    cout << "cemilan";
  }

  return 0;
}
