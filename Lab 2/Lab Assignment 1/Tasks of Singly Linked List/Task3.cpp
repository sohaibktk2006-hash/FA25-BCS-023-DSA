#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to remove duplicate values
void removeDuplicates(Node* head) {

    // Current node checks each value
    Node* current = head;

    while (current != NULL) {

        Node* prev = current; // Previous node is used to delete duplicate
        
        Node* temp = current->next; // Start checking nodes after current

        while (temp != NULL) {

            // If duplicate is found
            if (temp->data == current->data) {

                // Save duplicate node
                Node* deleteNode = temp;

                // Skip duplicate node
                prev->next = temp->next;

                // Delete duplicate node
                delete deleteNode;

                // Move temp to next node
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

    Node* head = new Node{10, NULL};
    head->next = new Node{20, NULL};
    head->next->next = new Node{10, NULL};
    head->next->next->next = new Node{30, NULL};
    head->next->next->next->next = new Node{20, NULL};

    removeDuplicates(head);

    display(head);

    return 0;
}