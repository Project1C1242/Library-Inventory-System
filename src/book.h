#ifndef BOOK_H
#define BOOK_H

#include "Item.h"
#include <string>

class Book : public Item {
public:
    std::string title;
    std::string author;
    std::string copyrightDate;

    Book(std::string n, std::string d, int i, std::string t, std::string a, std::string cd);
    void display(std::ostream& os) const override;
};

#endif // BOOK_H