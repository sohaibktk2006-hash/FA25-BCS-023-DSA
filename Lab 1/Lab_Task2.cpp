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

    // 1. Insert value at end
    void insertAtEnd(int value) {
        arr[size] = value;
        size++;
        cout << "Value inserted at end.\n";
    }

    // 2. Insert value at start
    void insertAtStart(int value) {
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = value;
        size++;

        cout << "Value inserted at start.\n";
    }

    // 3. Insert value after specific value
    void insertAfter(int specificValue, int value) {
        int index = -1;

        for (int i = 0; i < size; i++) {
            if (arr[i] == specificValue) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Specific value not found.\n";
            return;
        }

        for (int i = size; i > index + 1; i--) {
            arr[i] = arr[i - 1];
        }

        arr[index + 1] = value;
        size++;

        cout << "Value inserted after " << specificValue << ".\n";
    }

    // 4. Insert value before specific value
    void insertBefore(int specificValue, int value) {
        int index = -1;

        for (int i = 0; i < size; i++) {
            if (arr[i] == specificValue) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Specific value not found.\n";
            return;
        }

        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }

        arr[index] = value;
        size++;

        cout << "Value inserted before " << specificValue << ".\n";
    }

    // 5. Display array list
    void display() {
        if (size == 0) {
            cout << "Array list is empty.\n";
            return;
        }

        cout << "Array List: ";

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // 6. Delete value from end
    void deleteFromEnd() {
        if (size == 0) {
            cout << "Array list is empty.\n";
            return;
        }

        size--;
        cout << "Value deleted from end.\n";
    }

    // 7. Delete value from start
    void deleteFromStart() {
        if (size == 0) {
            cout << "Array list is empty.\n";
            return;
        }

        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;

        cout << "Value deleted from start.\n";
    }

    // 8. Delete specific value
    void deleteSpecific(int value) {
        int index = -1;

        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Value not found.\n";
            return;
        }

        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;

        cout << "Value deleted successfully.\n";
    }
};

int main() {
    ArrayList list;
    int choice, value, specificValue;

    do {
        cout << "\nARRAY LIST MENU\n";
        cout << "1. Insert value at end\n";
        cout << "2. Insert value at start\n";
        cout << "3. Insert value after specific value\n";
        cout << "4. Insert value before specific value\n";
        cout << "5. Display array list\n";
        cout << "6. Delete value from end\n";
        cout << "7. Delete value from start\n";
        cout << "8. Delete specific value\n";
        cout << "9. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtStart(value);
            break;

        case 3:
            cout << "Enter specific value: ";
            cin >> specificValue;

            cout << "Enter value to insert: ";
            cin >> value;

            list.insertAfter(specificValue, value);
            break;

        case 4:
            cout << "Enter specific value: ";
            cin >> specificValue;

            cout << "Enter value to insert: ";
            cin >> value;

            list.insertBefore(specificValue, value);
            break;

        case 5:
            list.display();
            break;

        case 6:
            list.deleteFromEnd();
            break;

        case 7:
            list.deleteFromStart();
            break;

        case 8:
            cout << "Enter value to delete: ";
            cin >> value;

            list.deleteSpecific(value);
            break;

        case 9:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 9);

    return 0;
}