#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Delete all nodes having the given value
void deleteValue(Node*& head, int value) {

    // Delete matching nodes from the beginning
    while (head != NULL && head->data == value) {

        // Store current head
        Node* temp = head;

        // Move head to next node
        head = head->next;

        // Delete old head
        delete temp;
    }

    // Start checking remaining nodes
    Node* current = head;

    while (current != NULL && current->next != NULL) {

        // Check next node's value
        if (current->next->data == value) {

            // Store node to delete
            Node* temp = current->next;

            // Skip the node
            current->next = temp->next;

            // Delete node
            delete temp;
        }
        else {

            // Move current forward
            current = current->next;
        }
    }
}

void display(Node* head) {

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {

    Node* head = new Node{20, NULL};
    head->next = new Node{10, NULL};
    head->next->next = new Node{20, NULL};
    head->next->next->next = new Node{30, NULL};
    head->next->next->next->next = new Node{20, NULL};
    head->next->next->next->next->next = new Node{40, NULL};

    // Value that needs to be deleted
    int value = 20;

    deleteValue(head, value);

    display(head);

    return 0;
}