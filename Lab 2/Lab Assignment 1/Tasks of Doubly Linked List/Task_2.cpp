#include <iostream>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;
};

void displayForward(Node* head) {
    Node* temp = head;

    cout << "Forward Playlist: ";

    while (temp != NULL) {
        cout << temp->song << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

void displayBackward(Node* tail) {
    Node* temp = tail;

    cout << "Backward Playlist: ";

    while (temp != NULL) {
        cout << temp->song << " -> ";
        temp = temp->prev;
    }

    cout << "NULL" << endl;
}

int main() {

    // Creating songs
    Node* head = new Node{"Song A", NULL, NULL};
    Node* song2 = new Node{"Song B", NULL, NULL};
    Node* song3 = new Node{"Song C", NULL, NULL};
    Node* tail = new Node{"Song D", NULL, NULL};

    // Connecting nodes forward
    head->next = song2;
    song2->next = song3;
    song3->next = tail;

    // Connecting nodes backward
    song2->prev = head;
    song3->prev = song2;
    tail->prev = song3;

    displayForward(head);
    displayBackward(tail);

    return 0;
}