#include "../header/Admin.h"

void Admin:: addBook(IBookshelf* shelf, Book* newBook) {
  if (shelf != nullptr)
    shelf ->addBook(newBook);
}

void Admin:: removeBook(IBookshelf* shelf, std::string isbn) {
  if (shelf != nullptr)
    shelf ->removeBook(isbn);
}
