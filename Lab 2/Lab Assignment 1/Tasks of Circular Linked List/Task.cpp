#include <iostream>
using namespace std;

struct Node {
    string name;
    int priority;
    string status;

    Node* next;
};

// Add a new task at the end
void addTask(Node*& head, string name, int priority, string status) {

    Node* newNode = new Node;

    newNode->name = name;
    newNode->priority = priority;
    newNode->status = status;

    // If list is empty
    if (head == NULL) {
        head = newNode;
        newNode->next = head;   // Make it circular
        return;
    }

    // Find the last node
    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    // Add new node at end
    temp->next = newNode;
    newNode->next = head;
}

// Remove a task by name
void removeTask(Node*& head, string name) {

    if (head == NULL) {
        cout << "Task list is empty!" << endl;
        return;
    }

    Node* current = head;
    Node* previous = NULL;

    // Search for the task
    do {
        if (current->name == name)
            break;

        previous = current;
        current = current->next;

    } while (current != head);


    // Task not found
    if (current->name != name) {
        cout << "Task not found!" << endl;
        return;
    }


    // Only one node exists
    if (current == head && current->next == head) {
        delete current;
        head = NULL;
        return;
    }


    // If deleting head
    if (current == head) {

        Node* last = head;

        while (last->next != head) {
            last = last->next;
        }

        head = head->next;
        last->next = head;

        delete current;
    }

    // Delete middle or last node
    else {
        previous->next = current->next;
        delete current;
    }

    cout << name << " removed successfully." << endl;
}

// Get next pending task
void getNextTask(Node* head, string currentTask) {

    if (head == NULL) {
        cout << "No tasks available!" << endl;
        return;
    }

    Node* current = head;

    // Find current task
    do {

        if (current->name == currentTask)
            break;

        current = current->next;

    } while (current != head);


    if (current->name != currentTask) {
        cout << "Current task not found!" << endl;
        return;
    }


    // Start checking from next task
    Node* temp = current->next;

    do {

        // Find a pending task
        if (temp->status == "pending") {

            cout << "Next Task: " << temp->name << endl;
            cout << "Priority: " << temp->priority << endl;
            cout << "Status: " << temp->status << endl;

            return;
        }

        temp = temp->next;

    } while (temp != current->next);


    cout << "No pending task available!" << endl;
}

// Display all tasks
void displayTasks(Node* head) {

    if (head == NULL) {
        cout << "Task list is empty!" << endl;
        return;
    }

    Node* temp = head;

    cout << "\nAll Tasks:" << endl;

    do {

        cout << "Task: " << temp->name
             << " | Priority: " << temp->priority
             << " | Status: " << temp->status << endl;

        temp = temp->next;

    } while (temp != head);
}

// Update task status
void updateStatus(Node* head, string name, string newStatus) {

    if (head == NULL) {
        cout << "Task list is empty!" << endl;
        return;
    }

    Node* temp = head;

    do {

        if (temp->name == name) {

            temp->status = newStatus;

            cout << "\nUpdated Task: " << temp->name << endl;
            cout << "New Status: " << temp->status << endl;

            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "Task not found!" << endl;
}
int main() {

    Node* head = NULL;

    // Add tasks
    addTask(head, "Design UI", 2, "pending");
    addTask(head, "Database", 1, "pending");
    addTask(head, "Testing", 3, "completed");
    addTask(head, "Documentation", 4, "pending");

    // Display all tasks
    displayTasks(head);

    // Get next task
    cout << "\nGetting next task after Design UI:" << endl;

    getNextTask(head, "Design UI");

    // Update status
    updateStatus(head, "Design UI", "completed");

    // Get next task again
    cout << "\nGetting next task after Design UI:" << endl;

    getNextTask(head, "Design UI");

    // Remove task
    cout << "\nRemoving Testing:" << endl;

    removeTask(head, "Testing");

    // Display tasks after removal
    displayTasks(head);


    return 0;
}