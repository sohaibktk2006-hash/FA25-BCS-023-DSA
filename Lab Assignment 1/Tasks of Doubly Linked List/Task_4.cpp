#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Display the doubly linked list
void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

// Create the required special pattern
void specialPattern(Node* head, Node* tail) {

    // First and last seats remain fixed

    Node* left = head->next;          // Seat 2
    Node* right = tail->prev;         // Seat 8

    // Swap 2 and 8
    int temp = left->data;
    left->data = right->data;
    right->data = temp;

    // Move two positions from both sides
    left = left->next->next;          // Seat 4
    right = right->prev->prev;        // Seat 6

    // Swap 4 and 6
    temp = left->data;
    left->data = right->data;
    right->data = temp;
}

int main() {

    // Create nodes
    Node* n1 = new Node{1, NULL, NULL};
    Node* n2 = new Node{2, NULL, NULL};
    Node* n3 = new Node{3, NULL, NULL};
    Node* n4 = new Node{4, NULL, NULL};
    Node* n5 = new Node{5, NULL, NULL};
    Node* n6 = new Node{6, NULL, NULL};
    Node* n7 = new Node{7, NULL, NULL};
    Node* n8 = new Node{8, NULL, NULL};
    Node* n9 = new Node{9, NULL, NULL};

    // Connect forward
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;

    // Connect backward
    n2->prev = n1;
    n3->prev = n2;
    n4->prev = n3;
    n5->prev = n4;
    n6->prev = n5;
    n7->prev = n6;
    n8->prev = n7;
    n9->prev = n8;

    Node* head = n1;
    Node* tail = n9;

    cout << "Original list: ";
    display(head);

    specialPattern(head, tail);

    cout << "After swapping: ";
    display(head);

    return 0;
}