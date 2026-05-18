cmake_minimum_required(VERSION 3.10)

# Name
project(Library-Inventory-System VERSION 1.0)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add your source files here as you create them
set(SOURCES
    src/main.cpp
    src/item.cpp
    src/item.h
    src/LibraryStorage.cpp
    src/LibraryStorage.h
    src/book.cpp
    src/book.h
    src/movie.cpp
    src/movie.h
    src/magazine.cpp
    src/magazine.h
  
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})