#ifndef LIBRARY_STORAGE_H
#define LIBRARY_STORAGE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include "Item.h"

using namespace std;

struct Compartment {
    shared_ptr<Item> item = nullptr;
};

class Shelf {
private:
    vector<Compartment> compartments;
public:
    Shelf();
    Compartment& operator[](size_t index);
    size_t getSize();
};

class LibraryStorage {
private:
    vector<Shelf> shelves;
public:
    LibraryStorage(int numShelves);
    Shelf& operator[](size_t index);

    void addItem(int shelfIndex, int compIndex, shared_ptr<Item> newItem);
    void checkoutItem(int shelfIndex, int compIndex, const string& borrower, const string& dueDate);
    void checkinItem(int shelfIndex, int compIndex);
    void printItemsInStorage();
    void printCheckedOutItems();
    void swapItems(int shelf1, int comp1, int shelf2, int comp2);
};

#endif
