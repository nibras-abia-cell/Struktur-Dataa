#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertDepan(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    
    newNode->next = *head;
    newNode->prev = NULL; 

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

void insertBelakang(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void tampilkanList(Node* node) {
    Node* last = NULL;
    cout << "Traversal Maju: ";
    while (node != NULL) {
        cout << node->data << " <-> ";
        last = node; 
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    int jumlah, nilai, dataBaru;

    cout << "Masukkan jumlah data: ";
    cin >> jumlah;

    for (int i = 1; i <= jumlah; i++) {
        cout << "Masukkan data ke " << i << ": ";
        cin >> nilai;
        insertBelakang(&head, nilai);
    }

    cout << "\nMasukkan data yang ditambahkan di awal: ";
    cin >> dataBaru;
    insertDepan(&head, dataBaru);

    cout << "\nData setelah ditambah di awal:" << endl;
    tampilkanList(head);

    return 0;
}
