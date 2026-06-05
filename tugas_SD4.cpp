#include <iostream>
using namespace std;

struct Node {
    int dataa;
    Node* next;
};

void insertDepan(Node** head, int newData) {
	
    Node* newNode = new Node();
    
    newNode->dataa = newData;
     
    newNode->next = *head;
      
    *head = newNode;
}

void insertBelakang(Node** head, int newData) {
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
    int jumlah, nilai, dataBaru;
  
    cout << "Masukkan jumlah dataa: ";
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
