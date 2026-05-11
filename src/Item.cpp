#include "Item.h"

// Item Constructor
Item::Item(std::string n, std::string d, int i) : name(n), description(d), id(i) {}

void Item::display(std::ostream& os) const {
    os << "ID: " << id << " | Name: " << name;
}

// Global Operator Overload
std::ostream& operator<<(std::ostream& os, const Item& item) {
    item.display(os);
    return os;
}

// Movie Constructor
Movie::Movie(std::string n, std::string d, int i, std::string t, std::vector<std::string> a)
    : Item(n, d, i), title(t), actors(a) {}

void Movie::display(std::ostream& os) const {
    Item::display(os);
    os << " | Movie Title: " << title;
}