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

// Find multiple occurrences
void findOccurrences(Node* head, int value)
{
    Node* temp = head;

    int position = 1;
    int count = 0;

    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            cout << "Value found at position: "<< position << endl;
            count++;
        }
        temp = temp->next;
        position++;
    }
    if (count == 0)
    {
        cout << "Value not found." << endl;
    }
    else
    {
        cout << "Total occurrences: " << count << endl;
    }
}

int main()
{
    Node* head = nullptr;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 20);
    insert(head, 40);
    insert(head, 20);
    insert(head, 50);

    cout << "Linked List: "; 
    display(head);

    int value;

    cout << "Enter value to search: ";
    cin >> value;

    findOccurrences(head, value);
    return 0;
}