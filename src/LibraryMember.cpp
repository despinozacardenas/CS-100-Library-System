#include "../header/LibraryMember.h"

LibraryMember::LibraryMember(int inUserID, std::string inUserName, std::string inUserPassword)
    : User(inUserID, inUserName, inUserPassword) {
    this->accountType = 1;
}

bool LibraryMember::borrowBook(IBookshelf* aShelf, std::string bookISBN) {
  if (aShelf == nullptr)
    return false;

  Book* borrowingBook = aShelf->getBookByISBN(bookISBN);

  if (borrowingBook == nullptr || borrowingBook->getStatus() == false)
    return false;

  borrowingBook->setStatus(false);
  checkoutBooks.push_back(borrowingBook);
  return true;
}
bool LibraryMember::returnBook(std::string bookISBN) {
  for (auto it = checkoutBooks.begin(); it != checkoutBooks.end(); it++) {
    Book* currentBook = *it;
    if (currentBook->getISBN() == bookISBN) {
      currentBook->setStatus(true);
      checkoutBooks.erase(it);
      return true;
    }
  }
  return false;
}



const std::vector<Book*>& LibraryMember::getCheckoutBooks() const {
  return checkoutBooks;
}
