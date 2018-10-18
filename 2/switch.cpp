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

  switch(pilihan) {
    case 1:
      cout << "makanan";
      break;
    case 2:
      cout << "minuman";
      break;
    case 3:
      cout << "cemilan";
      break;
    default:
      cout << "gg";
      break;
  }

  return 0;
}
