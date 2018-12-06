#include <iostream>

using namespace std;

int main() {
  class mahasiswa {
  private:
    string nama;
    string nim;
    int umur;

  public:
    mahasiswa();
    mahasiswa(string nama, string n);
    ~mahasiswa();
    string getNama();
    string getNim();
    int getUmur();
    int operator+ (mahasiswa mhs1);
    void setName(string nama);
    void setNim(string n);
    void setUmur(int u);
    void toString();
  };

  mahasiswa :: mahasiswa() {
    nama = "";
    nim = "";
  }

  mahasiswa :: mahasiswa(string nama, string n) {
    nama = nama;
    nim = n;
  }

  mahasiswa :: ~mahasiswa() {

  }

  string mahasiswa :: getNama() {
    return nama;
  }

  string mahasiswa :: getNim() {
    return nim;
  }

  int mahasiswa :: getUmur() {
    return umur;
  }

  void mahasiswa :: setNama(string nama) {
    nama = nama;
  }

  void mahasiswa :: setNim(string nim) {
    nim = nim;
  }

  void mahasiswa :: setUmur(int u) {
    umur = u;
  }

  voud mahasiswa :: toString() {
    cout << "nama mahasiswa " << nama << endl;
    cout << "nim mahasiswa " << nim << endl;
  }

  int mahasiswa :: operator+ (mahasiswa mhs1) {
    int hasil = mhs1.umur + umur;
    return hasil;
  }

  return 0;
}
