#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void separateEvenOdd(Node* head) {

    // Head and tail for even list
    Node* evenHead = NULL;
    Node* evenTail = NULL;

    // Head and tail for odd list
    Node* oddHead = NULL;
    Node* oddTail = NULL;

    while (head != NULL) {

        // Create a new node with current value
        Node* newNode = new Node{head->data, NULL};

        // Check if value is even
        if (head->data % 2 == 0) {

            // First even node
            if (evenHead == NULL) {
                evenHead = evenTail = newNode;
            }
            else {
                // Add node at end of even list
                evenTail->next = newNode;
                evenTail = newNode;
            }
        }
        else {

            if (oddHead == NULL) {
                oddHead = oddTail = newNode;
            }
            else {

                oddTail->next = newNode;
                oddTail = newNode;
            }
        }
        head = head->next;
    }

    // Display even list
    cout << "Even: ";
    Node* temp = evenHead;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    // Display odd list
    cout << "\nOdd: ";
    temp = oddHead;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {

    Node* head = new Node{1, NULL};
    head->next = new Node{2, NULL};
    head->next->next = new Node{3, NULL};
    head->next->next->next = new Node{4, NULL};
    head->next->next->next->next = new Node{5, NULL};
    head->next->next->next->next->next = new Node{6, NULL};

    separateEvenOdd(head);

    return 0;
}