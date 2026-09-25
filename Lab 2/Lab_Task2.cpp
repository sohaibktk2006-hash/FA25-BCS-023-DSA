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

// Merge two lists into third new list
Node* mergeLists(Node* head1, Node* head2)
{
    Node* head3 = nullptr;

    Node* temp = head1;

    while (temp != nullptr)
    {
        insert(head3, temp->data);
        temp = temp->next;
    }

    temp = head2;

    while (temp != nullptr)
    {
        insert(head3, temp->data);
        temp = temp->next;
    }

    return head3;
}

int main()
{
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    Node* head3 = nullptr;

    // First List
    insert(head1, 1);
    insert(head1, 2);
    insert(head1, 3);
    insert(head1, 4);

    // Second List
    insert(head2, 5);
    insert(head2, 6);
    insert(head2, 7);

    cout << "First List: ";
    display(head1);

    cout << "Second List: ";
    display(head2);

    // Merge
    head3 = mergeLists(head1, head2);

    cout << "Third List after Merging: ";
    display(head3);

    return 0;
}