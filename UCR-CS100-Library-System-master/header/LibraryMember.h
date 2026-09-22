#ifndef LIBRARYMEMBER_H
#define LIBRARYMEMBER_H

#include "User.h"
#include "Book.h"
#include "IBookshelf.h"

#include <vector>


class LibraryMember : public User {
 public:
  LibraryMember(int inUserID, std::string inUserName, std::string inUserPassword);
  bool borrowBook(IBookshelf* aShelf, std::string bookISBN);
  bool returnBook(std::string bookISBN);
  const std::vector<Book*>& getCheckoutBooks() const;
 private:
  std::vector<Book*> checkoutBooks;
};

#endif