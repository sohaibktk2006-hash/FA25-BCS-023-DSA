#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insert(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(Node* head)
{
    Node* temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Reverse using loop
void reverseLoop(Node* head)
{
    if (head == nullptr)
        return;

    int count = 0;
    Node* temp = head;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    for (int i = count - 1; i >= 0; i--)
    {
        temp = head;

        for (int j = 0; j < i; j++)
        {
            temp = temp->next;
        }
        cout << temp->data << " ";
    }
    cout << endl;
}

// Reverse using recursion
void reverseRecursive(Node* head)
{
    if (head == nullptr)
        return;
    reverseRecursive(head->next);
    cout << head->data << " ";
}

int main()
{
    Node* head = nullptr;
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    cout << "Original List: ";
    display(head);
    cout << "Reverse using Loop: ";
    reverseLoop(head);
    cout << "Reverse using Recursion: ";
    reverseRecursive(head);
    cout << endl;
    return 0;
}