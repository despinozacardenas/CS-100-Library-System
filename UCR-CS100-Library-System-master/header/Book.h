#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
 public:
  Book(std::string inTitle, std::string inAuthor, std::string inIsbn, std::string inGenre, double inCost, bool inStatus);
  
  std::string getTitle() const;
  std::string getAuthor() const;
  std::string getISBN() const;
  std::string getGenre() const;
  double getCost() const;
  bool getStatus() const;

  void setTitle(std::string newTitle);
  void setAuthor(std::string newAuthor);
  void setISBN(std::string newISBN);
  void setGenre(std::string newGenre);
  void setCost(double newCost);
  void setStatus(bool newStatus);
 private:
  std::string title;
  std::string author;
  std::string isbn;
  std::string genre;
  double cost;
  bool bookStatus;
};



#endif