#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to reverse the linked list
Node* reverseList(Node* head) {

    Node* prev = NULL; // Previous node initially does not exist

    
    Node* current = head; // Start from first node

    
    Node* nextNode; // Used to save the next node

    while (current != NULL) {

        nextNode = current->next; // Save the next node before changing the link

        current->next = prev; // Reverse the current node's link

        // Move prev one step forward
        prev = current;

        // Move current one step forward
        current = nextNode;
    }

    return prev;
}

void display(Node* head) {

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {

    Node* head = new Node{1, NULL};
    head->next = new Node{2, NULL};
    head->next->next = new Node{3, NULL};
    head->next->next->next = new Node{4, NULL};
    
    head = reverseList(head);

    display(head);

    return 0;
}