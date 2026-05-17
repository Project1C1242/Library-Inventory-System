#include "LibraryStorage.h"

std::vector<Item>& LibraryShelf::operator[](size_t compartmentIndex)
{
  return compartments[compartmentIndex];
}

LibraryShelf& LibraryShelf::operator[](size_t libraryIndex)
{
  return LibraryShelf[libraryIndex];
}
