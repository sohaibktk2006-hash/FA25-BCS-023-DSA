#include <iostream>
using namespace std;

// Singly Linked List Node
struct SNode
{
    int data;
    SNode* next;
};

// Doubly Linked List Node
struct DNode
{
    int data;
    DNode* next;
    DNode* prev;
};

// Insert in Singly Linked List
void insertSingly(SNode*& head, int value)
{
    SNode* newNode = new SNode;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    SNode* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Convert Singly List to Doubly List
DNode* convertToDoubly(SNode* head)
{
    DNode* dHead = NULL;
    DNode* dTail = NULL;

    SNode* temp = head;

    while (temp != NULL)
    {
        // Create new doubly node
        DNode* newNode = new DNode;

        newNode->data = temp->data;
        newNode->next = NULL;
        newNode->prev = dTail;

        if (dHead == NULL)
        {
            dHead = newNode;
        }
        else
        {
            dTail->next = newNode;
        }

        dTail = newNode;

        temp = temp->next;
    }

    return dHead;
}

// Display Singly List
void displaySingly(SNode* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

// Display Doubly List
void displayDoubly(DNode* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main()
{
    SNode* head = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    // Create Singly Linked List
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;

        insertSingly(head, value);
    }

    cout << "\nSingly Linked List: ";
    displaySingly(head);

    // Convert to Doubly Linked List
    DNode* dHead = convertToDoubly(head);

    cout << "Doubly Linked List: ";
    displayDoubly(dHead);

    return 0;
}