#include <iostream>
using namespace std;

struct Node {
    int dataa;
    Node* next;
};

void insertAkhir(Node** head, int newData) {
    
    Node* newNode = new Node();
    newNode->dataa = newData;
    newNode->next = NULL; 
 
    if (*head == NULL) {
        *head = newNode;
        return;
    }
  
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    
    temp->next = newNode;
}

void tampilkanList(Node* node) {
    while (node != NULL) {
        cout << node->dataa << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    int jumlah, nilai, dataTambahan;
   
    cout << "Masukkan jumlah data: ";
    cin >> jumlah;

    for (int i = 1; i <= jumlah; i++) {
        cout << "Masukkan data ke " << i << ": ";
        cin >> nilai;
        insertAkhir(&head, nilai);
    }
 
    cout << "\nMasukkan data yang ditambahkan di akhir: ";
    cin >> dataTambahan;
    insertAkhir(&head, dataTambahan);
  
    cout << "\nData setelah ditambah di akhir:" << endl;
    tampilkanList(head);

    return 0;
}
