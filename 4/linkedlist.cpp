#include <iostream>

using namespace std;

struct node {
  int data;
  node *next;
};

node *head = NULL;

void tambahDepan() {
  node *baru;
  baru = new node;
  baru->next = NULL;
  cout << "masukkan data: ";
  cin >> baru->data;

  if (head == NULL) {
    head = baru;
  } else {
    baru->next = head;
    head = baru;
  }
}

void hapusDepan() {
  node *hapus;
  hapus = head;

  head = head->next;
  hapus->next = NULL;
  delete hapus;
}

void tambahBelakang() {
  node * baru;
  baru = new node;
  baru->next = NULL;

  cout << "Masukkan data: ";
  cin >> baru->data;

  if (head == NULL) {
    head = baru;
  } else {
    node *bantu;
    bantu = head;
    while (bantu->next != NULL) {
      bantu = bantu->next;
    }
    bantu->next = baru;
  }
}

void hapusBelakang() {
  node *hapus, *bantu;
  hapus = bantu = head;

  while (hapus->next != NULL) {
    bantu = hapus;
    hapus = hapus->next;
  }
  bantu->next = NULL;
  delete hapus;
}

void cetak() {
  node *bantu;
  bantu = head;
  while (bantu != NULL) {
    cout << bantu->data << " ";
    bantu = bantu->next;
  }
}

int main() {

  tambahDepan();
  tambahDepan();
  tambahDepan();
  cetak();
  hapusDepan();
  cetak();
  tambahBelakang();
  tambahBelakang();
  hapusBelakang();
  cetak();
  tambahBelakang();
  cetak();

  
  return 0;
}
