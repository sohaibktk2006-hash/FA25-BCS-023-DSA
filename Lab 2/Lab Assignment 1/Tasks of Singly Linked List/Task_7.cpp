#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to reverse a linked list
Node* reverseList(Node* head) {

    Node* prev = NULL;
    Node* current = head;

    while (current != NULL) {

        // Save next node
        Node* nextNode = current->next;

        // Reverse link
        current->next = prev;

        // Move pointers forward
        prev = current;
        current = nextNode;
    }

    return prev;
}

// Function to reverse both halves
Node* reverseHalves(Node* head) {

    // If list has 0 or 1 node
    if (head == NULL || head->next == NULL)
        return head;

    // Slow and fast pointers find middle
    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Second half starts after slow
    Node* secondHalf = slow->next;

    // Break list into two halves
    slow->next = NULL;

    // Reverse first half
    Node* firstHalf = reverseList(head);

    // Reverse second half
    secondHalf = reverseList(secondHalf);

    // Find end of first reversed half
    Node* temp = firstHalf;

    while (temp->next != NULL)
        temp = temp->next;

    // Connect first reversed half with second reversed half
    temp->next = secondHalf;

    return firstHalf;
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
    head->next->next->next->next = new Node{5, NULL};
    head->next->next->next->next->next = new Node{6, NULL};
    head->next->next->next->next->next->next = new Node{7, NULL};
    head->next->next->next->next->next->next->next = new Node{8, NULL};

    head = reverseHalves(head);

    display(head);

    return 0;
}