#include "../header/BookEditor.h"

bool BookEditor::editTitle(Book* book, std::string newTitle) {
  if (book == nullptr)
    return false;
  book->setTitle(newTitle);
  return true; 
}



bool BookEditor::editAuthor(Book* book, std::string newAuthor) {
  if (book == nullptr)
    return false;
  book->setAuthor(newAuthor);
  return true; 
}



bool BookEditor::editISBN(Book* book, std::string newISBN) {
  if (book == nullptr)
    return false;
  book->setISBN(newISBN);
  return true; 
}



bool BookEditor::editGenre(Book* book, std::string newGenre) {
  if (book == nullptr)
    return false;
  book->setGenre(newGenre);
  return true;
}



bool BookEditor::editCost(Book* book, double newCost) {
  if (book == nullptr)
    return false;
  book->setCost(newCost);
  return true;
}



bool BookEditor::changeStatus(Book* book, bool newStatus)
{
  if (book == nullptr)
    return false;
  book->setStatus(newStatus);
  return true; 
}