#include <iostream>

using namespace std;

#include "mahasiswa.cpp"

int main() {
  mahasiswa stikom;
  stikom.setNama("kevin");
  stikom.setUmur(21);
  stikom.toString();

  mahasiswa unud;
  unud.setNama("anantha");
  unud.setUmur(21);

  int hasilTambah = stikom + unud;
  cout << hasilTambah;

  int angkat 3 + 4;
  cout << angka;

  return 0;
}
