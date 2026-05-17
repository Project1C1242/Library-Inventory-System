#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Item.h"
#include <string>

class Magazine : public Item {
public:
    std::string edition;
    std::string mainArticle;

    Magazine(std::string n, std::string d, int i, std::string ed, std::string article);
    void display(std::ostream& os) const override;
};

#endif // MAGAZINE_H