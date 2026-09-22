#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Bookshelf.h"
#include "IBookshelf.h"
#include "Book.h"

class Admin : public User {
 public:
  Admin(int inUserID, std::string inName, std::string inPass) 
    : User(inUserID, inName, inPass) { 
      this->accountType = 2;
  }
  void addBook(IBookshelf* shelf,Book* newBook);
  void removeBook(IBookshelf* shelf,std::string isbn);
  void editBook();
 private:
};



#endif