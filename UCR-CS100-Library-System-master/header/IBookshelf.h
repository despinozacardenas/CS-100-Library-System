#ifndef IBOOKSHELF_H
#define IBOOKSHELF_H

#include "Book.h"

#include <vector> 

class IBookshelf {
public:
virtual ~IBookshelf() {}
virtual void addBook(Book* book) = 0;
virtual void removeBook(std::string isbn) = 0;
virtual Book* getBookByISBN(std::string isbn) = 0;
//virtual std::vector<Book*> search(std::string query) = 0;
virtual std::vector<Book*> getAllBooks() = 0;

};



#endif 