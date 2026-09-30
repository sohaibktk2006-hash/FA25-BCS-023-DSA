#include <iostream>
using namespace std;


struct Node
{
    int data; // Store value in node
    Node* next; // Store Address of next node
    Node* prev; //Store Address of previous node
};

// Function to reverse doubly linked list
void reverseList(Node*& head)
{
    Node* current = head;
    Node* temp = NULL;

    while (current != NULL)
    {
        // Swap next and prev
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to next node
        current = current->prev;
    }

    // Update head
    if (temp != NULL)
    {
        head = temp->prev;
    }
}

// Function to insert node at end
void insert(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display list
void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    cout << "Original List: ";
    display(head);

    reverseList(head);

    cout << "Reversed List: ";
    display(head);

    return 0;
}