#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

// Insert node at end
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

// Display list
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

// Swap two nodes
void swapNodes(Node*& head, int value1, int value2)
{
    if (value1 == value2)
        return;

    Node* node1 = NULL;
    Node* node2 = NULL;

    Node* temp = head;

    // Search both values
    while (temp != NULL)
    {
        if (temp->data == value1)
            node1 = temp;

        if (temp->data == value2)
            node2 = temp;

        temp = temp->next;
    }

    // If any value is not found
    if (node1 == NULL || node2 == NULL)
    {
        cout << "Both values are not found." << endl;
        return;
    }

    // Connect previous nodes
    if (node1->prev != NULL)
        node1->prev->next = node2;
    else
        head = node2;

    if (node2->prev != NULL)
        node2->prev->next = node1;
    else
        head = node1;

    // Connect next nodes
    if (node1->next != NULL)
        node1->next->prev = node2;

    if (node2->next != NULL)
        node2->next->prev = node1;

    // Swap prev pointers
    Node* tempPrev = node1->prev;
    node1->prev = node2->prev;
    node2->prev = tempPrev;

    // Swap next pointers
    Node* tempNext = node1->next;
    node1->next = node2->next;
    node2->next = tempNext;
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

    int value1, value2;

    cout << "Enter first value: ";
    cin >> value1;

    cout << "Enter second value: ";
    cin >> value2;

    swapNodes(head, value1, value2);

    cout << "List after swapping nodes: ";
    display(head);

    return 0;
}