#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to display linked list in reverse order
void displayReverse(Node* head) {

    //if list is empty, return
    if (head == NULL)
        return;

    // First go to the last node
    displayReverse(head->next);

    // Print data while returning from recursion
    cout << head->data << " ";
}

int main() {

    Node* head = new Node{1, NULL};
    head->next = new Node{2, NULL};
    head->next->next = new Node{3, NULL};
    head->next->next->next = new Node{4, NULL};

    cout << "Reverse: ";

    displayReverse(head);

    return 0;
}