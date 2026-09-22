#include "../header/System.h"
#include "../header/LibraryMember.h"
#include "../header/User.h"
#include "../header/BookEditor.h"
#include "../header/Admin.h"
#include <iostream>
#include <string>

static void printHeader(const std::string& headerText) {
  std::cout << "\n----------------------------------------\n";
  std::cout << headerText << "\n";
  std::cout << "----------------------------------------\n";
}


void System::run() {
  if (!bookshelf.loadFromCsv("books.csv")){
    std::cout << "Warning: could not open books.csv. Catalog is empty.\n";
  }
  displayLoginMenu();
}


void System::displayLoginMenu(){
  int choice = 0;

  while (choice != 4) {
    std::cout << "\n=== Library System Login ===\n";
    std::cout << "1. Library Member\n";
    std::cout << "2. Create Library Member Account\n";
    std::cout << "3. Admin\n";
    std::cout << "4. Exit\n";
    std::cout << "Select option: ";

    choice = getIntInput();
    loginSelection(choice);
  }
}


void System::loginSelection(int choice) {
  switch (choice) {
    case 1: 
      if (login(false))
        displayMemberMenu();
        std::cout << "\n";
      break;
    case 2:
      createAccount();
      std::cout << "\n";
      break;
    case 3: 
      if (login(true))
        displayAdminMenu();
        std::cout << "\n";
      break;
    case 4: 
      std::cout << "Exiting Library System.\n"; 
      break;
    default: std::cout << "Invalid choice. Try again.\n"; break;
  }
}



void System::displayAdminMenu() {
  int choice = 0;

  while (choice != 5) {
    std::cout << "\n--- Admin Menu ---\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Remove Book\n";
    std::cout << "3. Open Book Editor\n";
    std::cout << "4. View Book Catalog \n";
    std::cout << "5. Logout\n";
    std::cout << "\n";
    std::cout << "Select option: ";

    choice = getIntInput();

    switch (choice) {
      case 1: systemAddBook(); std::cout << "\n"; break;
      case 2: systemRemoveBook(); std::cout << "\n"; break;
      case 3: openBookEditor();std::cout << "\n"; break;
      case 4: 
        displayBooks();
        break;
      case 5: std::cout << "Logging out from Admin Menu.\n"; break;
      default: std::cout << "Invalid choice. Try again.\n"; break;
    }
  }
  this->currentUser = nullptr;
}



void System::displayMemberMenu() {
  int choice = 0;

  while (choice != 6) {
    printHeader("Member Menu");
    std::cout << "1. View Catalog\n";
    std::cout << "2. Checkout Book\n";
    std::cout << "3. Return Book\n";
    std::cout << "4. View Borrowed Books\n";
    std::cout << "5. Reset Password\n";
    std::cout << "6. Logout\n";
    std::cout << "Select option: ";

    choice = getIntInput();

    switch (choice) {
      case 1: displayBooks(); std::cout << "\n"; break;
      case 2: checkoutBook(); std::cout << "\n"; break;
      case 3: returnBook(); std::cout << "\n"; break;
      case 4: viewBorrowed(); std::cout << "\n"; break;
      case 5: resetCurrentUserPassword(); std::cout << "\n"; break;
      case 6: std::cout << "Logging out from Member Menu.\n"; break;
      default: std::cout << "Invalid choice. Try again.\n"; break;
    }

  }
}



int System::getIntInput() {
  int value;
  std::cin >> value;

  while (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cout << "Invalid input. Enter a valid number: ";
    std::cin >> value;
  }
  std::cin.ignore(256, '\n');
  return value;
}



double System::getDoubleInput() {
  double value;
  std::cin >> value;

  while (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cout << "Invalid input. Enter a valid number: ";
    std::cin >> value;
  }
  std::cin.ignore(256, '\n'); 

  return value;
}



void System::displayBooks() {
  bookshelf.displayCatalog();
}



bool System::login(bool isAdminLogin)
{
  std::string name, password;
  bool success = false;
  bool foundUser = false;
  
  if (isAdminLogin) {
    printHeader("Admin Login");
  } else {
    printHeader("Member Login");
  }
  std::cout << "Enter username: ";
  std::cin >> name;

  std::cout << "Enter password: ";
  std::cin >> password;

  auto it = users.begin();
  
  while (it != users.end() && !foundUser) {
    User* user = *it;
    
    if (user->getUserName() == name && user->getPassword() == password) {
      foundUser = true; 

      if (isAdminLogin) {
        if (user->getAccountType() == 2) {
          currentUser = user;
          std::cout << "Admin Login Successful. Welcome " << currentUser->getUserName() << "!\n";
          success = true;
        } else {
          std::cout << "Error: This account does not have Admin privileges.\n";
        }
      }

      else {
        if (user->getAccountType() == 1) {
          currentUser = user;
          std::cout << "Member Login Successful. Welcome " << currentUser->getUserName() << "!\n";
          success = true;
        } else {
          std::cout << "Error: Admins cannot log into the Member menu.\n";
        }
      }
    }
    else {
      ++it; 
    }
  }

  if (!foundUser) {
    std::cout << "Invalid username or password.\n";
  }

  return success;
}



void System::createAccount() {
  std::string name, password, confirmPassword;

  printHeader("Create New Account");

  std::cout <<  "Enter username: ";
  std::cin >> name;

  for(User*& user : users) {
    if (user -> getUserName() == name) {
      std::cout << "Username already taken" << std::endl;
      return;
    }
  }

  std::cout << "Enter password: ";
  std::cin >> password;

  std::cout << "Confirms password: ";
  std::cin >> confirmPassword;

  if(password != confirmPassword) {
    std::cout << "Passwords do not match!!" << std::endl;
    return;
  }

  users.push_back(new LibraryMember(nextUserID++,name,password));
  std::cout << "Account created successfully";
}



void System::resetCurrentUserPassword() {
  std::string newPassword;
  std::cout << "Enter new password: ";
  std::cin >> newPassword;

  bool success = currentUser->resetPassword(newPassword);

  if (success) {
    std::cout << "Password updated successfully.\n";
  } else {
    std::cout << "Invalid password.\n";
  }
}



void System:: systemAddBook() {
  std::string newBookTitle;
  std::string newBookAuthor;
  std::string newBookISBN;
  std::string newBookGenre;
  double newBookPrice;
  printHeader("Add Book");
  std::cout <<"Enter New Title: ";
  std::getline(std::cin >> std::ws, newBookTitle);
  std::cout <<"Enter New Author: ";
  std::getline(std::cin, newBookAuthor);
  std::cout <<"Enter New ISBN: ";
  std::getline(std::cin, newBookISBN);
  std::cout <<"Enter New Genre: ";
  std::getline(std::cin, newBookGenre);
  std::cout <<"Enter New Price: ";
  newBookPrice = getDoubleInput();

  while (newBookPrice < 0) {
    std::cout << "Price cannot be negative. Enter valid price: ";
    newBookPrice = getDoubleInput();
  }
  
  Book* newBook = new Book(newBookTitle,newBookAuthor,newBookISBN,newBookGenre,newBookPrice,true);
  Admin* adminPtr = dynamic_cast<Admin*>(currentUser);

  if (adminPtr != nullptr) {
    adminPtr->addBook(&bookshelf, newBook);
  } else {
    std::cout << "Error: Only Admin can add books. Action canceled.\n";
  }
}



void System:: systemRemoveBook() {
  std::string removeBookISBN;
  printHeader("Remove Book");
  std::cout << "Enter ISBN to Remove: ";
  std::getline(std::cin >> std::ws, removeBookISBN);
  Admin* adminPtr = dynamic_cast<Admin*>(currentUser);
  if (adminPtr != nullptr) {
    adminPtr->removeBook(&bookshelf,removeBookISBN);
  } else{
    std::cout<<"Error: Only Admin can remove books. Action canceled.\n";
  }
}



void System::openBookEditor() {
  std::string isbnToEdit;
  printHeader("Open Book Editor");
  std::cout << "Enter the ISBN of the book you want to edit: ";
  std::getline(std::cin >> std::ws, isbnToEdit);
  Book* targetBook = bookshelf.getBookByISBN(isbnToEdit);

  if (targetBook == nullptr) {
    std::cout << "Error: Book with ISBN " << isbnToEdit << " not found.\n";
    return; 
  }

  std::cout << "Editing: " << targetBook->getTitle() << "\n";
  
  BookEditor editor;
  std::string newEdit = "";
  double newCost = 0.0;
  int choice = 0;
  int statusInput = 0;
  while (choice != 7) 
  {
    printHeader("Book Editor Menu");
    std::cout << "1. Edit Title\n";
    std::cout << "2. Edit Author\n";
    std::cout << "3. Edit ISBN\n";
    std::cout << "4. Edit Genre\n";
    std::cout << "5. Edit Cost\n";
    std::cout << "6. Edit Book Status\n";
    std::cout << "7. Exit Book Editor\n";
    std::cout << "\n";
    std::cout << "Select option: ";

    choice = getIntInput();

    switch (choice) {
      case 1:
        std::cout << "Enter New Title: ";
        std::getline(std::cin, newEdit);
        editor.editTitle(targetBook, newEdit);
        break;

      case 2:
        std::cout << "Enter New Author: ";
        std::getline(std::cin, newEdit);
        editor.editAuthor(targetBook, newEdit);
        break;

      case 3:
        std::cout << "Enter New ISBN: ";
        std::getline(std::cin, newEdit);
        editor.editISBN(targetBook, newEdit);
        break;

      case 4:
        std::cout << "Enter New Genre: ";
        std::getline(std::cin, newEdit);
        editor.editGenre(targetBook, newEdit);
        break;

      case 5: 
        std::cout << "Enter New Cost: ";
        newCost = getDoubleInput();
        
        while (newCost < 0) {
          std::cout << "New cost must be a positive number. Enter a new cost: ";
          newCost = getDoubleInput();
        }
        editor.editCost(targetBook, newCost);
        break;
      case 6: 
      {
        std::cout << "Set status (1 = Available, 0 = Checked Out): ";
        statusInput = getIntInput();
        if (statusInput == 1){
          editor.changeStatus(targetBook, true);
          std::cout << "Book status set to Available.\n";
        }
        else if(statusInput == 0){
          editor.changeStatus(targetBook, false);
          std::cout << "Book status set to Checked Out.\n";
        }
        else{
          std::cout << "Invalid Input, Enter 1 or 0 only\n";
        }
          break;
      }
      case 7:
        std::cout << "Exit Book Edit Options\n";
        break;
    }
  }
}


System::System() 
{
  users.push_back(new Admin(111, "Alan", "adminPass1"));
  users.push_back(new Admin(222, "Danny", "adminPass2"));
}


System::~System()
{
   for(User*& user : users)
   {
     delete user;
   }
}



void System::checkoutBook() {
  if (currentUser != nullptr) {
    LibraryMember* currentMember = static_cast<LibraryMember*>(currentUser);
    std::string isbn;
    std::cout << "Enter the ISBN of the book you want to checkout: ";
    std::getline(std::cin >> std::ws, isbn); 

    if (currentMember->borrowBook(&bookshelf, isbn)) {
      std::cout << "You checked out book with ISBN: " << isbn << std::endl;
    } else {
      std::cout << "Failed to checkout book with ISBN: " << isbn << std::endl;
    }
  }
}



void System::returnBook() {
  if (currentUser != nullptr) {
    LibraryMember* currentMember = static_cast<LibraryMember*>(currentUser);
    std::string isbn;
    printHeader("Return Book");
    std::cout << "Enter the ISBN of the book to return: ";
    std::getline(std::cin >> std::ws, isbn);
    
    if (currentMember->returnBook(isbn)) {
      std::cout << "You returned book with ISBN: " << isbn << std::endl;
    } else {
      std::cout << "Failed to return book with ISBN: " << isbn << std::endl;
    }
  }
}


void System::viewBorrowed() {
  if (currentUser != nullptr) {
    LibraryMember* currentMember = static_cast<LibraryMember*>(currentUser);
    const auto& currentBooks = currentMember->getCheckoutBooks();
    printHeader("Borrowed Books");

    if (currentBooks.empty()) {
      std::cout << "No books checked out.\n";
    } else {
      std::cout << "---- Checked Out ---- \n";
      std::cout << "Title | ISBN | Genre | Author | Cost | Status \n ";
      std::cout << "-------------------------------------------------- \n";

      for (const auto* book : currentBooks) {
        std::cout << book->getTitle() << " | "
                  << book->getISBN() << " | "
                  << book->getGenre() << " | "
                  << book->getAuthor() << " | "
                  << book->getCost() << " | "
                  << "Checked Out\n"; 
      }
    }
  }
}
