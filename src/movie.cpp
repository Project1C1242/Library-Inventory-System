#include "Movie.h"

Movie::Movie(std::string n, std::string d, int i, std::string t, std::string dir, std::vector<std::string> actors)
    : Item(n, d, i), title(t), director(dir), mainActors(actors) {}

void Movie::display(std::ostream& os) const {
    Item::display(os);
    os << " | [Movie] Title: " << title << " | Director: " << director << " | Cast: ";
    for (size_t j = 0; j < mainActors.size(); ++j) {
        os << mainActors[j] << (j == mainActors.size() - 1 ? "" : ", ");
    }
}