#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Swap nodes in pairs
Node* pairWiseSwap(Node* head) {

    // If list has less than 2 nodes
    if (head == NULL || head->next == NULL)
        return head;

    // Second node becomes new head
    Node* newHead = head->next;

    // Previous pair's last node
    Node* prev = NULL;

    // Start from first node
    Node* current = head;

    while (current != NULL && current->next != NULL) {

        // Second node of current pair
        Node* second = current->next;

        // First node of next pair
        Node* nextPair = second->next;

        // Reverse the pair
        second->next = current;

        // Connect current node to next pair
        current->next = nextPair;

        // Connect previous pair to current pair
        if (prev != NULL)
            prev->next = second;

        // Current becomes the previous node
        prev = current;

        // Move to next pair
        current = nextPair;
    }

    // Return new head
    return newHead;
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

    head = pairWiseSwap(head);

    display(head);

    return 0;
}