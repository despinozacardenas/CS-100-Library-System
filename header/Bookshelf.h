#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include "Book.h"
#include "IBookshelf.h"

#include <vector>
#include <string>

class Bookshelf: public IBookshelf {
 public:
  ~Bookshelf();
 
  bool loadFromCsv(const std::string& books);
  void displayCatalog() const;
  void addBook(Book* book) override;
  void removeBook(std::string isbn) override;
  Book* getBookByISBN(std::string isbn) override;
  std::vector<Book*> getAllBooks() override;

 private:
  std::vector<Book*> bookCatalog;
};



#endif