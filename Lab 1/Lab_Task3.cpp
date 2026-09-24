#include <iostream>
using namespace std;

class ArrayList {
private:
    int arr[100];
    int size;

public:
    ArrayList() {
        size = 0;
    }

    // Insert at end
    void insertAtEnd(int value) {
        arr[size] = value;
        size++;
    }

    // Insert at start
    void insertAtStart(int value) {
        int i = size;

        while (i > 0) {
            arr[i] = arr[i - 1];
            i--;
        }

        arr[0] = value;
        size++;
    }

    // Insert after specific value
    void insertAfter(int specificValue, int value) {
        int i = 0;

        while (i < size && arr[i] != specificValue) {
            i++;
        }

        if (i == size) {
            cout << "Specific value not found.\n";
            return;
        }

        int j = size;

        while (j > i + 1) {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[i + 1] = value;
        size++;
    }

    // Insert before specific value
    void insertBefore(int specificValue, int value) {
        int i = 0;

        while (i < size && arr[i] != specificValue) {
            i++;
        }

        if (i == size) {
            cout << "Specific value not found.\n";
            return;
        }

        int j = size;

        while (j > i) {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[i] = value;
        size++;
    }

    // Display
    void display() {
        if (size == 0) {
            cout << "Array List is empty.\n";
            return;
        }

        int i = 0;

        cout << "Array List: ";

        while (i < size) {
            cout << arr[i] << " ";
            i++;
        }

        cout << endl;
    }

    // Delete from end
    void deleteFromEnd() {
        if (size == 0) {
            cout << "Array List is empty.\n";
            return;
        }

        size--;
    }

    // Delete from start
    void deleteFromStart() {
        if (size == 0) {
            cout << "Array List is empty.\n";
            return;
        }

        int i = 0;

        while (i < size - 1) {
            arr[i] = arr[i + 1];
            i++;
        }

        size--;
    }

    // Delete specific value
    void deleteSpecific(int value) {
        int i = 0;

        while (i < size && arr[i] != value) {
            i++;
        }

        if (i == size) {
            cout << "Value not found.\n";
            return;
        }

        while (i < size - 1) {
            arr[i] = arr[i + 1];
            i++;
        }

        size--;
    }

    // Linear Search using while loop
    void linearSearch(int value) {
        int i = 0;
        bool found = false;

        while (i < size) {
            if (arr[i] == value) {
                cout << "Value found at index " << i << endl;
                found = true;
                break;
            }

            i++;
        }

        if (!found) {
            cout << "Value not found in the Array List.\n";
        }
    }
};

int main() {
    ArrayList list;

    // Adding some values
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    list.display();

    // Linear Search
    int value;

    cout << "Enter value to search: ";
    cin >> value;

    list.linearSearch(value);

    return 0;
}