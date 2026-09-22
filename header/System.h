#ifndef SYSTEM_H
#define SYSTEM_H

#include "Bookshelf.h"
#include "User.h"
#include "LibraryMember.h"

#include <vector>

class System {
 public:
  System();
  void run();
  ~System();
  
 private:
  Bookshelf bookshelf;
  std::vector<User*> users;
  User* currentUser = nullptr;
  int nextUserID = 1;

  void createAccount();
  bool login(bool choice);

  void displayLoginMenu();
  void loginSelection(int choice);
  int getIntInput();
  double getDoubleInput();

  void displayAdminMenu();
  void displayMemberMenu();

  void resetCurrentUserPassword();
  void openBookEditor();

  void displayBooks();
  void checkoutBook();
  void returnBook();
  void viewBorrowed();
  void systemAddBook();
  void systemRemoveBook();
};



#endif