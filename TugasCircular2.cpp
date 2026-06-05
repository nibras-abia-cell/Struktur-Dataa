#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node *prev;
};

void traverse(Node *head);

int cariMaksimal(Node *head) {
  if (head == NULL) {
    return -1;
  }
  int max = head->data;

  Node *current = head->next;
  while (current != head) {
    if (current->data > max) {
      max = current->data;
    }
    current = current->next;
  }
  return max;
}

int main() {
  Node *node1 = new Node;
  Node *node2 = new Node;
  Node *node3 = new Node;

  node1->data = 10;
  node1->next = node2;
  node1->prev = node3;

  node2->data = 20;
  node2->next = node3;
  node2->prev = node1;

  node3->data = 30;
  node3->next = node1;
  node3->prev = node2;

  cout << " Data linked list adalah : " << endl;
  traverse(node1);
  cout << " Nilai maksimal adalah : " << cariMaksimal(node1) << endl;
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
