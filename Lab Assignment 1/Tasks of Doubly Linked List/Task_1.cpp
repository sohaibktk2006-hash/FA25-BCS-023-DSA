#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
};

// Function to swap nodes' data from both ends
void swapEnds(Node* head, Node* tail) {

    // Left pointer starts from first node
    Node* left = head;

    // Right pointer starts from last node
    Node* right = tail;

    // Continue until both pointers meet or cross
    while (left != right && left->prev != right) {

        // Swap data of left and right nodes
        string temp = left->data;
        left->data = right->data;
        right->data = temp;

        // Move left one step forward
        left = left->next;

        // Move right one step backward
        right = right->prev;
    }
}

void display(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {

    // Create nodes
    Node* head = new Node{"Alice", NULL, NULL};
    Node* n2 = new Node{"Bob", NULL, NULL};
    Node* n3 = new Node{"Charlie", NULL, NULL};
    Node* n4 = new Node{"Dana", NULL, NULL};
    Node* n5 = new Node{"Eva", NULL, NULL};
    Node* tail = new Node{"Frank", NULL, NULL};

    // Connect nodes in forward direction
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = tail;

    // Connect nodes in backward direction
    n2->prev = head;
    n3->prev = n2;
    n4->prev = n3;
    n5->prev = n4;
    tail->prev = n5;

    swapEnds(head, tail);

    cout << "After swapping: ";
    display(head);

    return 0;
}