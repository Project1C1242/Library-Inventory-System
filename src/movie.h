#ifndef MOVIE_H
#define MOVIE_H

#include "Item.h"
#include <string>
#include <vector>

class Movie : public Item {
public:
    std::string title;
    std::string director;
    std::vector<std::string> mainActors;

    Movie(std::string n, std::string d, int i, std::string t, std::string dir, std::vector<std::string> actors);
    void display(std::ostream& os) const override;
};

#endif // MOVIE_H