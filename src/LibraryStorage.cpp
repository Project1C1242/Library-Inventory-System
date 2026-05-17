#include "LibraryStorage.h"

using namespace std;

Shelf::Shelf() {
    for (int i = 0; i < 15; i++) {
        Compartment c;
        c.item = nullptr;
        compartments.push_back(c);
    }
}

Compartment& Shelf::operator[](size_t index) {
    if (index >= 15) {
        throw out_of_range("Compartment index out of bounds");
    }
    return compartments[index];
}

size_t Shelf::getSize() {
    return compartments.size();
}

LibraryStorage::LibraryStorage(int numShelves) {
    for (int i = 0; i < numShelves; i++) {
        Shelf s;
        shelves.push_back(s);
    }
}

Shelf& LibraryStorage::operator[](size_t index) {
    if (index >= shelves.size()) {
        throw out_of_range("Shelf index out of bounds");
    }
    return shelves[index];
}

void LibraryStorage::addItem(int shelfIndex, int compIndex, shared_ptr<Item> newItem) {
    if (shelfIndex >= shelves.size() || shelfIndex < 0) {
        throw out_of_range("Shelf does not exist.");
    }
    if (compIndex >= 15 || compIndex < 0) {
        throw out_of_range("Compartment does not exist.");
    }
    
    shelves[shelfIndex][compIndex].item = newItem;
}

void LibraryStorage::checkoutItem(int shelfIndex, int compIndex, const string& borrower, const string& dueDate) {
    if (shelves[shelfIndex][compIndex].item == nullptr) {
        cout << "Error: Compartment is empty.\n";
        return;
    }
    if (shelves[shelfIndex][compIndex].item->isCheckedOut) {
        cout << "Error: Item is already checked out.\n";
        return;
    }

    shelves[shelfIndex][compIndex].item->isCheckedOut = true;
    shelves[shelfIndex][compIndex].item->borrower = borrower;
    shelves[shelfIndex][compIndex].item->dueDate = dueDate;
}

void LibraryStorage::checkinItem(int shelfIndex, int compIndex) {
    if (shelves[shelfIndex][compIndex].item == nullptr) {
        cout << "Error: Compartment is empty.\n";
        return;
    }

    shelves[shelfIndex][compIndex].item->isCheckedOut = false;
    shelves[shelfIndex][compIndex].item->borrower = "";
    shelves[shelfIndex][compIndex].item->dueDate = "";
}

void LibraryStorage::printItemsInStorage() {
    cout << "--- Current Library Storage ---\n";
    for (int s = 0; s < shelves.size(); s++) {
        for (int c = 0; c < 15; c++) {
            if (shelves[s][c].item != nullptr && !shelves[s][c].item->isCheckedOut) {
                cout << "Shelf " << s << ", Comp " << c << " -> ";
                cout << *(shelves[s][c].item) << "\n";
            }
        }
    }
}

void LibraryStorage::printCheckedOutItems() {
    cout << "--- Checked Out Items ---\n";
    bool found = false;
    
    for (int s = 0; s < shelves.size(); s++) {
        for (int c = 0; c < 15; c++) {
            if (shelves[s][c].item != nullptr && shelves[s][c].item->isCheckedOut) {
                cout << "Shelf " << s << ", Comp " << c << " -> ";
                cout << *(shelves[s][c].item) << " | Borrower: " 
                     << shelves[s][c].item->borrower << " | Due: " << shelves[s][c].item->dueDate << "\n";
                found = true;
            }
        }
    }
    
    if (!found) {
        cout << "No checked out items.\n";
    }
}

void LibraryStorage::swapItems(int shelf1, int comp1, int shelf2, int comp2) {
    if (shelves[shelf1][comp1].item == nullptr || shelves[shelf2][comp2].item == nullptr) {
        cout << "Error: Both compartments must have an item to swap.\n";
        return;
    }
    
    shared_ptr<Item> temp = shelves[shelf1][comp1].item;
    shelves[shelf1][comp1].item = shelves[shelf2][comp2].item;
    shelves[shelf2][comp2].item = temp;
}
