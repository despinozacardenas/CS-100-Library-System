#ifndef BOOKEDITOR_H
#define BOOKEDITOR_H

#include "Book.h"

class BookEditor {
 public:
  bool editTitle(Book* book, std::string newTitle);
  bool editAuthor(Book* book, std::string newAuthor);
  bool editISBN(Book* book, std::string newISBN);
  bool editGenre(Book* book, std::string newGenre);
  bool editCost(Book* book, double newCost);
  bool changeStatus(Book* book, bool newStatus);
 private:
};



#endif