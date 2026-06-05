#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertAkhir(Node** head, int newData) {
    
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
    cout << "Isi List: ";
    while (node != NULL) {
        cout << node->data;
        if (node->next != NULL) cout << " <-> ";
        node = node->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    Node* head = NULL;
    int jumlah, nilai, dataTambahan;

    cout << "Masukkan jumlah data awal: ";
    cin >> jumlah;

    for (int i = 1; i <= jumlah; i++) {
        cout << "Masukkan data ke " << i << ": ";
        cin >> nilai;
        insertAkhir(&head, nilai);
    }

    cout << "\nMasukkan data tambahan untuk di akhir: ";
    cin >> dataTambahan;
    insertAkhir(&head, dataTambahan);

    cout << "\nData setelah diperbarui:" << endl;
    tampilkanList(head);

    return 0;
}
