#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Remove duplicate stamp designs
void removeDuplicates(Node* head) {

    // Select one node at a time
    Node* current = head;

    while (current != NULL) {

        // Previous node of the node being checked
        Node* prev = current;

        // Compare current with remaining nodes
        Node* temp = current->next;

        while (temp != NULL) {

            // Duplicate found
            if (temp->data == current->data) {

                // Save duplicate node
                Node* deleteNode = temp;

                // Remove duplicate from list
                prev->next = temp->next;

                // Free memory
                delete deleteNode;

                // Continue checking
                temp = prev->next;
            }
            else {
                
                prev = temp;
                temp = temp->next;
            }
        }

        current = current->next;
    }
}

void display(Node* head) {

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {

    Node* head = new Node{5, NULL};
    head->next = new Node{8, NULL};
    head->next->next = new Node{5, NULL};
    head->next->next->next = new Node{10, NULL};
    head->next->next->next->next = new Node{8, NULL};

    removeDuplicates(head);

    display(head);

    return 0;
}