#include "../header/Book.h"

#include <cassert>
#include <stdexcept>

Book::Book(std::string inTitle, std::string inAuthor, std::string inIsbn, std::string inGenre, double inCost, bool inStatus) {
  title = inTitle;
  author = inAuthor;
  isbn = inIsbn;
  genre = inGenre;
  cost = inCost;
  bookStatus = inStatus;
}

std::string Book::getTitle() const {
  return title;
}

std::string Book::getAuthor() const {
  return author;
}

std::string Book::getISBN() const {
  return isbn;
}

std::string Book::getGenre() const {
  return genre;
}

double Book::getCost() const {
  return cost;
}

bool Book::getStatus() const {
  return bookStatus;
}

void Book::setTitle(std::string newTitle) {
  title = newTitle;
}

void Book::setAuthor(std::string newAuthor) {
  author = newAuthor;
}

void Book::setISBN(std::string newISBN) {
  isbn = newISBN;
}

void Book::setGenre(std::string newGenre) {
  genre = newGenre;
}

void Book::setStatus(bool newStatus) {
  bookStatus = newStatus;
}

void Book::setCost(double newCost) {
  if (newCost < 0) 
    throw std::invalid_argument("Book must be a positive nonzero value.");
  
  cost = newCost;
}
