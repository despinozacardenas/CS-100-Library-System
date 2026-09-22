[![CI](https://github.com/cs100/final-project-despi065-amont247-cgarc418-drami201/actions/workflows/main.yml/badge.svg)](https://github.com/cs100/final-project-despi065-amont247-cgarc418-drami201/actions/workflows/main.yml)
# Library System
 
**Authors:**
* [Danny Espinoza Cardenas](https://github.com/despinozacardenas)
* [Diego Ramirez](https://github.com/Dramiroo)
* [Alan Montalvo](https://github.com/amont247)
* [Carlos Garcia Romo](https://github.com/cgromo)

## Project Description
We created a library system that allows users to create their own library member account. After logging in, users may view the library catalog, checkout & return books, view their borrowed books, and reset password. We also created an admin interface where an admin may login and add & remove books from the catalog. Admins can also display and edit books within the library catalog.

This project is important to us because the design choices behind every library system across the world must make information accessible to people of different ages and backgrounds. Designing a system that is intuitive for everyone helps us understand how our decisions directly impact the user experience.

What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
- C++
- Github

What will be the input/output of your project?

- Input: User Account information, borrow / return requests, search commands, admin tasks
- Output: Action confirmation screen, book status / catalog, account status, book reccommendation

What are the features that the project provides?

- User Accounts:
  - User - Account creation, borrow & return books, show account debt, display available books
  - Admin - Add/edit/remove books from users and catalog
- Book Catalog
- Book Search

## Phase II
## User Interface Specification
### Navigation Diagram
Link to our [diagram](https://lucid.app/lucidchart/c69e78fc-516d-4bef-9478-76af539b5794/edit?viewport_loc=-294%2C402%2C2670%2C1605%2C0_0&invitationId=inv_d776ae7f-cca8-46db-92bd-e3a5a4baf939)

### Screen Layouts
Link to our [slides](https://docs.google.com/presentation/d/1i8NMiH1dvCKKe9z06vOqgxZNhIMUy9tksvhO4md6xaw/edit?usp=sharing)

## Class Diagram
Link to our [diagram](https://lucid.app/lucidchart/c69e78fc-516d-4bef-9478-76af539b5794/edit?viewport_loc=-294%2C402%2C2670%2C1605%2C0_0&invitationId=inv_d776ae7f-cca8-46db-92bd-e3a5a4baf939)
 
## Phase III
### Reference to the same Links in Phase II for updated Navigation Diagram, Screen Layouts, and Class Diagram
**Updated class diagram description:**  

This is the class diagram for a Library management system.  

The System class main purpose is to manage the display of our library system. It is composed of Users and IBookshelf, which make up the core components of a library.  

We have a User superclass from which Admin and Member subclasses inherit. The Admin class performs the tasks of a librarian through the usage of a BookEditor class and IBookshelf. The BookEditor class handles any data processing for a Book object's title, genre, price, etc.  

The IBookshelf class is an interface that defines bookshelf functionality. This includes being able to search the catalog, display all books, and add or remove books from the bookshelf.  

The Member class is responsible for allowing a library member to check out books, return books, check fines, and show search history. This class uses IBookshelf and Book to conduct its functionalities.  

The Bookshelf class manages the library’s book catalog by using a vector to store books. It includes methods to retrieve books, display the catalog, and handle checkout functionality.


**New Classes:**
* We added the BookEditor Class which is a composition of the Admin, since it cannot exist without an Admin. We can think of this as a Librarian that uses an editing tool for books. Without the Librarian the edit tool is nonexistant. We seperated this into its own class to follow the single responsibility principle by allowing admin to still initialize the tool, but the new class handles the data processing.

* We added the IBookshelf class as an interface for the bookshelf so that the System can use the bookshelf, but the actual dependency logic relies on the implementation in the Bookshelf class. This follow the dependency inversion principle so that the system does not need to know how the books are stored but just the functionality of the bookshelf. For example, we could create a hash map of the book's isbn or a vector of books from a csv, or from an online api of a completely seperate database. These implementations do not need to specified to the system, just the functionality is shown.

**Updated Relationships:**
* System is a composite of User and IBookshelf.
* Admin and Member inherit from User Class
* Member and Admin have an association with IBookshelf since they use the Bookshelf extensively.
* Admin is a compositon of BookEditor since an admin owns that tool.
* Member and BookEditor are dependent on the Book since they need the Book Class Object to be able to compute their functions.
* Bookshelf class is the Realization / implementation of the IBookshelf. 
* Bookshelf is the aggregate of Books, but books can exist without the bookshelf since a member can checkout a book and hold its ownership. 

 
# Final deliverable
 
## Screenshots
Link to our [Screenshot Input / Output](https://docs.google.com/document/d/1WpRgIhCq3tKkKaR7qNRwIexsD9yOCb2b-ba3J8Lc5Po/edit?usp=sharing) (More functionalities shown in this document)

![mainmenu](/images/mainmenu.png)
![membermenus](/images/membermenus.png)
![bookcatalog](/images/bookcatalog.png)
![adminmenus](/images/adminmenus.png)
![bookeditormenus](/images/bookeditormenus.png)
 ## Installation/Usage
 ### 1. Required software / tools
 - A **C++ compiler** (g++, clang++, etc.)
 - **CMake**


Once these are installed, proceed to git clone our repository through the linux terminal by typing: 
```sh
git clone --recursive https://github.com/cs100/final-project-despi065-amont247-cgarc418-drami201.git
```
Next change your working environment into that cloned directory by typing: 
```sh
cd final-project-despi065-amont247-cgarc418-drami201
```
Now run cmake. and make. This will compile and build the library system program. 
```sh
cmake .
```
```sh
make
```
Now run the library system program using ./library_system.
```sh
./library_system
```

You are first greeted with the library system login. From here, users may create a new library member account, login as admins or library members ( only if they have an existing account ), or exit the program by selecting one of the numeric options 1- 4.

### Library Menu Guide
Since our program has no saved library members, you should first create a new library member account with option #2. Follow the prompts to create the member account. Once successful, proceed to option #1 for logging in as a member. You will see the member menu with 6 options all self-explanatory. Choose option 1 first and note down any ISBN to use within the Checkout Book and Return Book as users will require the specific ISBN for the book of their choice. Now input option 6 to logout. 

### Admin Menu Guide
We will now login with our pre-existing admin credentials.

<details>
<summary>Show Admin Login Credentials</summary>

First enter “Danny” for the username then “adminPass2” for the password.

</details>

After successfully logging in, you are presented with the Admin Menu. Here an admin can add a book to the catalog, remove a book, edit a book in catalog, and view the catalog as well. For adding, removing, and editing a book the user will again need the book ISBN.

After inputting a proper book ISBN into the library member and admin options, the prompts for user input are straightforward. Please refer to the screenshot above for additional guidance. Please do not hesitate to reach out to any of the authors for any further clarification.
 
 ## Testing
Our project was mainly tested throguh unit tests within our test directory. We ensured that google unit tests passed through continuous integration with our yaml file. We verified that all of our system worked at every push and pull request onto the master branch from all of our individual branches. We included the worflow status badge to display that our CI is functioning properly.
