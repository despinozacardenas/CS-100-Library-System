#include "../header/Bookshelf.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>


Bookshelf::~Bookshelf() {
  for (int i=0;i<bookCatalog.size();++i) {
    delete bookCatalog[i];
  }
  bookCatalog.clear();
}


const int titleWidth = 32;
const int isbnWidth = 20;
const int genreWidth = 20;
const int authorWidth = 20;
const int costWidth = 20;
const int statusWidth = 20;


bool Bookshelf::loadFromCsv(const std::string& books) {
  std::ifstream file(books);
  if (!file.is_open())
        return false;

  for (int i=0;i<bookCatalog.size();++i) {
    delete bookCatalog[i];
  }
  bookCatalog.clear();

  std::string currentLine;
  std::getline(file, currentLine);

  while(std::getline(file, currentLine)) {
    if (!currentLine.empty()) {
      std::stringstream lineParser(currentLine);
      std::string title;
      std::string isbn;
      std::string genre;
      std::string author;
      std::string costText;
      std::string statusText;

      std::getline(lineParser,title, ',');
      std::getline(lineParser,isbn, ',');
      std::getline(lineParser,genre, ',');
      std::getline(lineParser,author, ',');
      std::getline(lineParser,costText, ',');

      if (!std::getline(lineParser, statusText)) {
        statusText = "Available";
      }
            
        if (!title.empty() && !isbn.empty() && !genre.empty() && !author.empty() && !costText.empty()) {
          std::stringstream costParser(costText);
          double cost;

          if (costParser >> cost){
            bool isAvailable = (statusText != "Checked Out");
            Book* newBook = new Book(title, author, isbn, genre, cost, isAvailable);
            bookCatalog.push_back(newBook);
          }
        }
    }
  }
  return true;
}

void Bookshelf::displayCatalog() const {
  if (bookCatalog.empty()) {
    std::cout<< "No books in the catalog. \n";
    return;
  }

  std::cout << "---- Book Catalog ---- \n";
  std::cout << std::left
            << std::setw(titleWidth) << "Title" << " | "
            << std::setw(isbnWidth) << "ISBN" << " | "
            << std::setw(genreWidth) << "Genre" << " | "
            << std::setw(authorWidth) << "Author" << " | "
            << std::setw(costWidth) << "Cost" << " | "
            << std::setw(statusWidth) << "Status"
            << "\n";
  std::cout << std::string(titleWidth + isbnWidth + genreWidth + authorWidth + costWidth + statusWidth, '-') << "\n";

  for (int i=0; i<bookCatalog.size(); ++i) {
    const Book* book = bookCatalog[i];

    if (book != nullptr){
      std::string status = "Checked out";
        if (book -> getStatus()) {
          status = "Available";
        }

        std::cout << std::left
                  << std::setw(titleWidth) << book->getTitle() << " | "
                  << std::setw(isbnWidth) << book->getISBN() << " | "
                  << std::setw(genreWidth) << book->getGenre() << " | "
                  << std::setw(authorWidth) << book->getAuthor() << " | "
                  << std::setw(costWidth)  << book->getCost() << " | "
                  << std::setw(statusWidth) << status
                  << "\n";
    }
  }
}

void Bookshelf:: addBook(Book* book) {
  if (book != nullptr) {
    bookCatalog.push_back(book);
    std::cout << "Added successfully.\n";
  } else {
      std::cout <<"No book added.\n";
  }
}

void Bookshelf:: removeBook(std::string isbn){
  Book* bookToRemove = getBookByISBN(isbn);

  if (bookToRemove == nullptr) {
    std::cout << "Error: Book with ISBN " << isbn << " not found.\n";
    return; 
  }
  for (int i=0; i < bookCatalog.size(); ++i) {
    if (bookToRemove == bookCatalog[i]) {
      delete bookCatalog[i];
      bookCatalog.erase(bookCatalog.begin()+i);
      std::cout <<"Book Removed.\n";
      return;
    }
  }
}

Book* Bookshelf:: getBookByISBN(std::string isbn) {
  for(int i =0 ; i < bookCatalog.size(); ++i) {
    if (bookCatalog[i]->getISBN() == isbn)
      return bookCatalog[i];
  }
  return nullptr;
}

std::vector<Book*> Bookshelf:: getAllBooks() {
  return bookCatalog;
}
