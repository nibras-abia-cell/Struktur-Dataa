#include <iostream>
using namespace std;

struct Node {
    int dataa;
    Node* next;
};

void tambahNode(Node** head, int nilai) {
    Node* newNode = new Node();
    newNode->dataa = nilai;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void cariTerbesar(Node* head) {
    if (head == NULL) {
        cout << "List kosong." << endl;
        return;
    }

    Node* temp = head;
    int urutan = 1;
      
    int terbesar = head->dataa;

    while (temp != NULL) {
        
        cout << "Data ke " << urutan << ": " << temp->dataa << endl;

        
        if (temp->dataa > terbesar) {
            terbesar = temp->dataa;
        }

        temp = temp->next;
        urutan++;
    }
   
    cout << "Terbesar adalah : " << terbesar << endl;
}

int main() {
    Node* head = NULL;

    tambahNode(&head, 10);
    tambahNode(&head, 20);
    tambahNode(&head, 30);

    
    cariTerbesar(head);

    return 0;
}
