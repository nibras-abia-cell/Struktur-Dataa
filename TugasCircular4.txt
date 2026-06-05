#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node *prev;
};

void traverse(Node *head);
void insertAwal(Node *&head, int newData);
void insertAkhir(Node *&head, int newData);

int main() {
  Node *head = NULL;

  int jumlahData;
  cout << "Berapa banyak data yang ingin diinput? : ";
  cin >> jumlahData;

  for (int i = 1; i <= jumlahData; i++) {
    int inputData;
    cout << "Masukkan data ke-" << i << " : ";
    cin >> inputData;
    insertAkhir(head, inputData);
  }

  cout << "\nData linked list sekarang adalah : " << endl;
  traverse(head);

  int dataTambahan;
  cout << "\nMasukkan data yang ditambahkan di awal : ";
  cin >> dataTambahan;

  insertAwal(head, dataTambahan);

  cout << "\nData linked list setelah ditambahkan di awal : " << endl;
  traverse(head);

  cin.ignore();
  cin.get();
  return 0;
}

void traverse(Node *head) {
  if (head == NULL)
    return;
  Node *temp = head;
  int i = 1;
  do {
    cout << "Data ke " << i << " : " << temp->data << endl;
    temp = temp->next;
    i++;
  } while (temp != head);
}

void insertAwal(Node *&head, int newData) {
  Node *newNode = new Node;
  newNode->data = newData;

  if (head == NULL) {
    newNode->next = newNode;
    newNode->prev = newNode;
    head = newNode;
  } else {
    Node *tail = head->prev;
    newNode->next = head;
    newNode->prev = tail;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode; // Pindah head
  }
}

void insertAkhir(Node *&head, int newData) {
  Node *newNode = new Node;
  newNode->data = newData;

  if (head == NULL) {
    newNode->next = newNode;
    newNode->prev = newNode;
    head = newNode;
  } else {
    Node *tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
  }
}
