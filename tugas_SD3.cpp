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

void hitungTotal(Node* head) {
    Node* temp = head;
    int total = 0;
    int urutan = 1;

    while (temp != NULL) {
        
        cout << "Data ke " << urutan << ": " << temp->dataa << endl;
            
        total += temp->dataa;
        
        temp = temp->next;
        urutan++;
    }
    
    cout << "Total nilai adalah : " << total << endl;
}

int main() {
    Node* head = NULL;
  
    tambahNode(&head, 10);
    tambahNode(&head, 20);
    tambahNode(&head, 30);
   
    hitungTotal(head);

    return 0;
}
