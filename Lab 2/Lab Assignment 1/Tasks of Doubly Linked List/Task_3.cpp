#include <iostream>
using namespace std;

// Node for Item
struct ItemNode {
    string itemName;
    ItemNode* next;
};

// Node for Location
struct LocationNode {
    string locationName;
    ItemNode* items;
    LocationNode* next;
};

// Node for Section
struct SectionNode {
    string sectionName;
    LocationNode* locations;
    SectionNode* next;
};

// Node for Store
struct StoreNode {
    string storeName;
    SectionNode* sections;
    StoreNode* next;
};


// Add a new store
void addStore(StoreNode*& head, string storeName) {

    StoreNode* newStore = new StoreNode;

    newStore->storeName = storeName;
    newStore->sections = NULL;
    newStore->next = NULL;

    if (head == NULL) {
        head = newStore;
    }
    else {
        StoreNode* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newStore;
    }
}


// Add a new section in a store
void addSection(StoreNode* head, string storeName, string sectionName) {

    // Search for store
    StoreNode* store = head;

    while (store != NULL && store->storeName != storeName) {
        store = store->next;
    }

    if (store == NULL) {
        cout << "Store not found!" << endl;
        return;
    }

    // Create new section
    SectionNode* newSection = new SectionNode;

    newSection->sectionName = sectionName;
    newSection->locations = NULL;
    newSection->next = NULL;

    // Add section
    if (store->sections == NULL) {
        store->sections = newSection;
    }
    else {
        SectionNode* temp = store->sections;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newSection;
    }
}


// Add a location in a section
void addLocation(StoreNode* head,
                 string storeName,
                 string sectionName,
                 string locationName) {

    // Search store
    StoreNode* store = head;

    while (store != NULL && store->storeName != storeName) {
        store = store->next;
    }

    if (store == NULL) {
        cout << "Store not found!" << endl;
        return;
    }

    // Search section
    SectionNode* section = store->sections;

    while (section != NULL && section->sectionName != sectionName) {
        section = section->next;
    }

    if (section == NULL) {
        cout << "Section not found!" << endl;
        return;
    }

    // Create location
    LocationNode* newLocation = new LocationNode;

    newLocation->locationName = locationName;
    newLocation->items = NULL;
    newLocation->next = NULL;

    // Add location
    if (section->locations == NULL) {
        section->locations = newLocation;
    }
    else {
        LocationNode* temp = section->locations;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newLocation;
    }
}


// Add item in a particular location
void addItem(StoreNode* head,
             string storeName,
             string sectionName,
             string locationName,
             string itemName) {

    // Search store
    StoreNode* store = head;

    while (store != NULL && store->storeName != storeName) {
        store = store->next;
    }

    if (store == NULL) {
        cout << "Store not found!" << endl;
        return;
    }

    // Search section
    SectionNode* section = store->sections;

    while (section != NULL && section->sectionName != sectionName) {
        section = section->next;
    }

    if (section == NULL) {
        cout << "Section not found!" << endl;
        return;
    }

    // Search location
    LocationNode* location = section->locations;

    while (location != NULL && location->locationName != locationName) {
        location = location->next;
    }

    if (location == NULL) {
        cout << "Location not found!" << endl;
        return;
    }

    // Create item
    ItemNode* newItem = new ItemNode;

    newItem->itemName = itemName;
    newItem->next = NULL;

    // Add item
    if (location->items == NULL) {
        location->items = newItem;
    }
    else {
        ItemNode* temp = location->items;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newItem;
    }
}


// Remove an item
void removeItem(StoreNode* head,
                string storeName,
                string sectionName,
                string locationName,
                string itemName) {

    // Search store
    StoreNode* store = head;

    while (store != NULL && store->storeName != storeName) {
        store = store->next;
    }

    if (store == NULL) {
        cout << "Store not found!" << endl;
        return;
    }

    // Search section
    SectionNode* section = store->sections;

    while (section != NULL && section->sectionName != sectionName) {
        section = section->next;
    }

    if (section == NULL) {
        cout << "Section not found!" << endl;
        return;
    }

    // Search location
    LocationNode* location = section->locations;

    while (location != NULL && location->locationName != locationName) {
        location = location->next;
    }

    if (location == NULL) {
        cout << "Location not found!" << endl;
        return;
    }

    // Search item
    ItemNode* current = location->items;
    ItemNode* previous = NULL;

    while (current != NULL && current->itemName != itemName) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Item not found!" << endl;
        return;
    }

    // If item is first
    if (previous == NULL) {
        location->items = current->next;
    }
    else {
        previous->next = current->next;
    }

    delete current;

    cout << itemName << " removed successfully." << endl;
}


// Display items of a particular section
void displaySection(StoreNode* head,
                    string storeName,
                    string sectionName) {

    StoreNode* store = head;

    // Search store
    while (store != NULL && store->storeName != storeName) {
        store = store->next;
    }

    if (store == NULL) {
        cout << "Store not found!" << endl;
        return;
    }

    // Search section
    SectionNode* section = store->sections;

    while (section != NULL && section->sectionName != sectionName) {
        section = section->next;
    }

    if (section == NULL) {
        cout << "Section not found!" << endl;
        return;
    }

    cout << "\nItems in " << sectionName << " section:" << endl;

    // Display all locations
    LocationNode* location = section->locations;

    while (location != NULL) {

        cout << location->locationName << ": ";

        ItemNode* item = location->items;

        while (item != NULL) {
            cout << item->itemName << " -> ";
            item = item->next;
        }

        cout << "NULL" << endl;

        location = location->next;
    }
}


// Display all items of a store
void displayStore(StoreNode* head, string storeName) {

    StoreNode* store = head;

    // Search store
    while (store != NULL && store->storeName != storeName) {
        store = store->next;
    }

    if (store == NULL) {
        cout << "Store not found!" << endl;
        return;
    }

    cout << "\nItems in " << storeName << ":" << endl;

    SectionNode* section = store->sections;

    while (section != NULL) {

        cout << "\nSection: " << section->sectionName << endl;

        LocationNode* location = section->locations;

        while (location != NULL) {

            cout << "  " << location->locationName << ": ";

            ItemNode* item = location->items;

            while (item != NULL) {
                cout << item->itemName << " -> ";
                item = item->next;
            }

            cout << "NULL" << endl;

            location = location->next;
        }

        section = section->next;
    }
}


int main() {

    StoreNode* stores = NULL;

    // Add stores
    addStore(stores, "Islamabad Store");
    addStore(stores, "Lahore Store");

    // Add sections
    addSection(stores, "Islamabad Store", "Grocery");
    addSection(stores, "Islamabad Store", "Toys");

    addSection(stores, "Lahore Store", "Fruits");


    // Add locations
    addLocation(stores, "Islamabad Store","Grocery", "Shelf A");

    addLocation(stores, "Islamabad Store","Grocery", "Shelf B");

    addLocation(stores, "Islamabad Store","Toys", "Rack 1");

    addLocation(stores, "Lahore Store","Fruits", "Section A");


    // Add items
    addItem(stores, "Islamabad Store","Grocery", "Shelf A", "Milk");

    addItem(stores, "Islamabad Store","Grocery", "Shelf A", "Bread");

    addItem(stores, "Islamabad Store","Grocery", "Shelf B", "Butter");

    addItem(stores, "Islamabad Store","Toys", "Rack 1", "Car");

    addItem(stores, "Islamabad Store","Toys", "Rack 1", "Doll");

    addItem(stores, "Lahore Store","Fruits", "Section A", "Apple");


    // Display particular section
    displaySection(stores,"Islamabad Store","Grocery");


    // Remove an item
    removeItem(stores,"Islamabad Store","Grocery","Shelf A","Bread");

    // Display section after deletion
    displaySection(stores,"Islamabad Store","Grocery");


    // Display complete store
    displayStore(stores, "Islamabad Store");

    return 0;
}