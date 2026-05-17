#include "LibraryStorage.h"
#include "Book.h"
#include "Movie.h"
#include "Magazine.h"
#include <iostream>
#include <vector>

int main() {
    std::cout << "Initializing Library System with 3 Shelves...\n\n";
    LibraryStorage library(3);

    // 1. Creating items
    auto book1 = std::make_shared<Book>("Dune", "Sci-fi epic", 1, "Dune Chronicles", "Frank Herbert", "1965");
    auto movie1 = std::make_shared<Movie>("Inception", "Mind-bending thriller", 2, "Inception", "Christopher Nolan", std::vector<std::string>{"Leonardo DiCaprio", "Elliot Page"});
    auto mag1 = std::make_shared<Magazine>("Time", "Weekly insights", 3, "May 2026", "The Evolution of Money");

    // 2. Add Items to Storage
    std::cout << "--- Populating Inventory ---\n";
    library.addItem(0, 2, book1);
    library.addItem(1, 5, movie1);
    library.addItem(2, 14, mag1);

    // 3. Print Initial State
    library.printItemsInStorage();

    // 4. Test Checkouts & Reports
    std::cout << "\n--- Testing Checkouts ---\n";
    library.checkoutItem(0, 2, "Jhon Doe", "06-01-2026");
    library.checkoutItem(1, 5, "Smith Jones", "05-25-2026");
    
    library.printItemsInStorage();   
    library.printCheckedOutItems();  

    // 5. Test Swap Feature
    std::cout << "\n--- Testing Swapping Operation ---\n";
    library.swapItems(2, 14, 0, 0); // Expected error: cell [0][0] is empty
    
    auto book2 = std::make_shared<Book>("1984", "Dystopian fiction", 4, "1984", "George Orwell", "1949");
    library.addItem(0, 0, book2);
    library.swapItems(2, 14, 0, 0); // Expected success
    
    // 6. Test Out of Bounds
    std::cout << "\n--- Testing Bounds / Exceptions ---\n";
    std::cout << "Attempting to access non-existent Shelf 5:\n";
    try {
        library[5][0].item = book2;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception: " << e.what() << "\n";
    }

    // 7. Test Check-in 
    std::cout << "\n--- Testing Returns ---\n";
    library.checkinItem(0, 2); 
    library.printItemsInStorage();

    std::cout << "\nExecution complete. System stable.\n";
    return 0;
}
