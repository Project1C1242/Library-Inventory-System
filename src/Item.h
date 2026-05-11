#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>

// ==========================================
// Base Class: Item
// ==========================================
class Item {
public:
    std::string name;
    std::string description;
    int id;

    // Checkout status
    bool isCheckedOut = false;
    std::string borrower = "";
    std::string dueDate = "";

    Item(std::string n, std::string d, int i);
    
    // Virtual destructor
    virtual ~Item() {}

    // Polymorphism
    virtual void display(std::ostream& os) const;

    // Overloading <<
    friend std::ostream& operator<<(std::ostream& os, const Item& item);
};

// ==========================================
// Derived Class: Book
// ==========================================
class Book : public Item {
public:
    std::string title;
    std::string author;
    std::string copyrightDate;

    Book(std::string n, std::string d, int i, std::string t, std::string a, std::string cd);
    void display(std::ostream& os) const override;
};

// ==========================================
// Derived Class: Movie
// ==========================================
class Movie : public Item {
public:
    std::string title;
    std::string director;
    std::vector<std::string> mainActors;

    Movie(std::string n, std::string d, int i, std::string t, std::string dir, std::vector<std::string> actors);
    void display(std::ostream& os) const override;
};

// ==========================================
// Derived Class: Magazine
// ==========================================
class Magazine : public Item {
public:
    std::string edition;
    std::string mainArticle;

    Magazine(std::string n, std::string d, int i, std::string ed, std::string article);
    void display(std::ostream& os) const override;
};

#endif // ITEM_H