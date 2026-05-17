#include "Book.h"

Book::Book(std::string n, std::string d, int i, std::string t, std::string a, std::string cd)
    : Item(n, d, i), title(t), author(a), copyrightDate(cd) {}

void Book::display(std::ostream& os) const {
    Item::display(os);
    os << " | [Book] Title: " << title << " | Author: " << author << " | Year: " << copyrightDate;
}