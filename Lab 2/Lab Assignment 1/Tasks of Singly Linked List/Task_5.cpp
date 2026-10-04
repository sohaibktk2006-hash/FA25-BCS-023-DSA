#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to find middle node
Node* findMiddle(Node* head) {

    if (head == NULL)
        return NULL;

    Node* slow = head;

    // Fast starts from second node
    // This helps us get LEFT middle for even list
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {

        // Move slow one step
        slow = slow->next;

        // Move fast two steps
        fast = fast->next->next;
    }

    // Slow points to middle
    return slow;
}

int main() {

    Node* head = new Node{1, NULL};
    head->next = new Node{2, NULL};
    head->next->next = new Node{3, NULL};
    head->next->next->next = new Node{4, NULL};
    head->next->next->next->next = new Node{5, NULL};

    Node* middle = findMiddle(head);

    cout << "Middle = " << middle->data;

    return 0;
}