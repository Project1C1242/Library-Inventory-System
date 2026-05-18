#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "LibraryStorage.h"
#include "Book.h"
#include "Movie.h"
#include "Magazine.h"

using namespace std;

int main() {
    cout << "========================================\n";
    cout << "  LIBRARY INVENTORY SYSTEM AUTOGRADER   \n";
    cout << "========================================\n\n";

    // Create the main storage system (e.g., 5 shelves)
    LibraryStorage libraryStorage(5);

    cout << "--- 1. ADDING ITEMS TO STORAGE ---\n";
    // Creating items using Polymorphism
    auto book1 = make_shared<Book>("Gatsby Book", "Classic novel", 101, "The Great Gatsby", "F. Scott Fitzgerald", "1925");
    auto book2 = make_shared<Book>("1984 Book", "Dystopian sci-fi", 102, "1984", "George Orwell", "1949");

    vector<string> actors = {"Keanu Reeves", "Laurence Fishburne"};
    auto movie1 = make_shared<Movie>("Matrix Video", "Sci-fi action", 201, "The Matrix", "The Wachowskis", actors);

    auto mag1 = make_shared<Magazine>("NatGeo Mag", "Nature and science", 301, "June 2026", "The Deep Ocean");

    // Adding to specific shelves [shelf][compartment]
    libraryStorage.addItem(0, 0, book1);
    libraryStorage.addItem(0, 1, book2);
    libraryStorage.addItem(1, 0, movie1);
    libraryStorage.addItem(2, 4, mag1); // 3rd shelf, 5th compartment

    cout << "Added Books, a Movie, and a Magazine to the shelves.\n\n";

    cout << "--- 2. PRINTING ITEMS IN STORAGE (Testing << overload) ---\n";
    libraryStorage.printItemsInStorage();
    cout << "\n";

    cout << "--- 3. CHECKING OUT ITEMS ---\n";
    libraryStorage.checkoutItem(0, 0, "Marcus", "05-24-2026");
    libraryStorage.checkoutItem(1, 0, "Emmanuel", "05-21-2026");
    cout << "Checked out 'The Great Gatsby' and 'The Matrix'.\n\n";

    cout << "--- 4. PRINTING CHECKED-OUT ITEMS ---\n";
    libraryStorage.printCheckedOutItems();
    cout << "\n";

    cout << "--- 5. TESTING OPERATOR OVERLOAD [] ---\n";
    cout << "Accessing item at Shelf 3, Compartment 5 using libraryStorage[2][4]:\n";
    // This tests the specific requirement from the PDF
    if (libraryStorage[2][4].item != nullptr) {
        cout << *(libraryStorage[2][4].item) << "\n";
    }
    cout << "\n";

    cout << "--- 6. SWAPPING ITEMS ---\n";
    cout << "Swapping Book at [0][1] with Magazine at [2][4]...\n";
    libraryStorage.swapItems(0, 1, 2, 4);
    libraryStorage.printItemsInStorage();
    cout << "\n";

    cout << "--- 7. CHECKING IN ITEMS ---\n";
    cout << "Marcus returns 'The Great Gatsby'.\n";
    libraryStorage.checkinItem(0, 0);
    cout << "\n";

    cout << "--- 8. ERROR HANDLING & EDGE CASES (Exception Testing) ---\n";
    
    cout << "Test A: Accessing a shelf that doesn't exist...\n";
    try {
        libraryStorage.addItem(99, 0, book1);
    } catch (const exception& e) {
        cout << "Caught Error: " << e.what() << "\n";
    }

    cout << "\nTest B: Checking out an empty compartment...\n";
    try {
        libraryStorage.checkoutItem(4, 14, "Ghost User", "Never");
    } catch (const exception& e) {
        cout << "Caught Error: " << e.what() << "\n";
    }

    cout << "\nTest C: Swapping with an empty compartment...\n";
    try {
        libraryStorage.swapItems(0, 0, 4, 14);
    } catch (const exception& e) {
        cout << "Caught Error: " << e.what() << "\n";
    }
    
    //  Test Out of Bounds
    std::cout << "\n--- Testing Bounds / Exceptions ---\n";
    std::cout << "Attempting to access non-existent Shelf 5:\n";
    try {
        libraryStorage[5][0].item = book2;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception: " << e.what() << "\n";
    }

    cout << "\n========================================\n";
    cout << "          TEST SCRIPT COMPLETE          \n";
    cout << "========================================\n";

    return 0;
}
