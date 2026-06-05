#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev; 
};

void tambahNode(Node** head, int nilai) {
    Node* newNode = new Node();
    newNode->data = nilai;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void cariTerbesar(Node* head) {
    if (head == NULL) {
        cout << "List kosong." << endl;
        return;
    }

    Node* temp = head;
    int urutan = 1;
    int terbesar = head->data;

    cout << "--- Traversal Data ---" << endl;
    while (temp != NULL) {
        cout << "Data ke " << urutan << ": " << temp->data << endl;

        if (temp->data > terbesar) {
            terbesar = temp->data;
        }

        temp = temp->next;
        urutan++;
    }

    cout << "----------------------" << endl;
    cout << "Nilai Terbesar adalah : " << terbesar << endl;
}

int main() {
    Node* head = NULL;

    tambahNode(&head, 15);
    tambahNode(&head, 45);
    tambahNode(&head, 20);
    tambahNode(&head, 30);

    
    cariTerbesar(head);

    return 0;
}
