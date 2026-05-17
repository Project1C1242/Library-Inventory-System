#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item {
public:
    std::string name;
    std::string description;
    int id;

    // Checkout Status Tracking
    bool isCheckedOut;
    std::string borrower;
    std::string dueDate;

    Item(std::string n, std::string d, int i);
    virtual ~Item();

    virtual void display(std::ostream& os) const;

    friend std::ostream& operator<<(std::ostream& os, const Item& item);
};

#endif // ITEM_H