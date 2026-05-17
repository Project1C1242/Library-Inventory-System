#include "Magazine.h"

Magazine::Magazine(std::string n, std::string d, int i, std::string ed, std::string article)
    : Item(n, d, i), edition(ed), mainArticle(article) {}

void Magazine::display(std::ostream& os) const {
    Item::display(os);
    os << " | [Magazine] Edition: " << edition << " | Main Article: \"" << mainArticle << "\"";
}