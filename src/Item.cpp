#include "Item.h"

Item::Item(std::string n, std::string d, int i) 
    : name(n), description(d), id(i), isCheckedOut(false), borrower(""), dueDate("") {}

Item::~Item() {}

void Item::display(std::ostream& os) const {
    os << "ID: " << id << " | Name: " << name << " | Description: " << description;
}

std::ostream& operator<<(std::ostream& os, const Item& item) {
    item.display(os);
    return os;
}