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

void cetak() {
  node *bantu;
  bantu = head;
  while (bantu != NULL) {
    cout << bantu->data << " ";
    //head = bantu;
    bantu = bantu->next;
  }
}

int main() {

  tambahDepan();
  tambahDepan();
  tambahDepan();
  cetak();

  
  return 0;
}
