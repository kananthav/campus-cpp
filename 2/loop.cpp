#include <iostream>

using namespace std;

int main() {
  // for
  for (int i = 0; i <= 10; i++) {
    cout << i << endl;
  }

  // while
  int j = 0;
  while(j <= 10) {
    cout << j << endl;
    j++;
  }

  // do while
  int k = 0;
  do {
    cout << k << endl;
    k++;
  } while(k <= 10);

  return 0;
}
