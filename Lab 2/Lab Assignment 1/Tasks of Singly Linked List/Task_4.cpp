#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to detect cycle/loop
bool detectLoop(Node* head) {

    Node* slow = head;

    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;

        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main() {

    Node* head = new Node{1, NULL};
    head->next = new Node{2, NULL};
    head->next->next = new Node{3, NULL};
    head->next->next->next = new Node{4, NULL};

    head->next->next->next->next = head->next;

    if (detectLoop(head))
        cout << "Loop exists";
    else
        cout << "No loop";

    return 0;
}