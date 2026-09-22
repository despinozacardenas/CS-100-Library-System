#include "../header/LibraryMember.h"
#include "../header/Bookshelf.h"
#include "../header/Book.h"

#include <gtest/gtest.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



TEST(LibraryMemberTests, borrowBook_updates_book_status) {
  Bookshelf testShelf;
  Book* testBook = new Book ("Original Title", "Author Danny", "ISBN123", "Fantasy Genre", 999.99, true);
  testShelf.addBook(testBook);

  LibraryMember member(123, "User Danny", "password123");

  bool success = member.borrowBook(&testShelf, "ISBN123");

  EXPECT_TRUE(success);
  EXPECT_FALSE(testBook->getStatus());
}



TEST(LibraryMemberTests, getCheckoutBooks_returns_correct_vector) {
  Bookshelf testShelf;
  Book* testBook = new Book ("Original Title", "Author Danny", "ISBN123", "Fantasy Genre", 999.99, true);
  testShelf.addBook(testBook);
  
  LibraryMember member(123, "User Danny", "password123");
  member.borrowBook(&testShelf, "ISBN123");

  const std::vector<Book*>& testCheckoutBooks = member.getCheckoutBooks();

  EXPECT_EQ(testCheckoutBooks.size(), 1);
  EXPECT_EQ(testCheckoutBooks[0]->getISBN(), "ISBN123");
}



TEST(LibraryMemberTests, borrowBook_updates_multiple_checkout_vector) {
  Bookshelf testShelf;
  Book* testBook = new Book ("Original Title", "Author Danny", "ISBN123", "Fantasy Genre", 999.99, true);
  Book* testBook2 = new Book ("Original Title 2", "Author Danny 2", "ISBN123 2", "Fantasy Genre 2", 999.99, true);
  testShelf.addBook(testBook);
  testShelf.addBook(testBook2);
  
  LibraryMember member(123, "User Danny", "password123");
  member.borrowBook(&testShelf, "ISBN123");
  member.borrowBook(&testShelf, "ISBN123 2");

  EXPECT_EQ(member.getCheckoutBooks().size(), 2);
  EXPECT_EQ(member.getCheckoutBooks()[0]->getISBN(), "ISBN123");
  EXPECT_EQ(member.getCheckoutBooks()[1]->getISBN(), "ISBN123 2");
}



TEST(LibraryMemberTests, borrowBook_false_if_book_already_checked_out) {
  Bookshelf shelf;
  Book* testBook = new Book("Title", "Author Danny", "ISBN123", "Genre", 999.99, false);
  shelf.addBook(testBook);
  LibraryMember member(123, "User Danny", "password123");

  bool success = member.borrowBook(&shelf, "ISBN123");

  EXPECT_FALSE(success);
}



TEST(LibraryMemberTests, returnBook_removes_book_from_checkout_vector) {
  Bookshelf testShelf;
  Book* testBook = new Book ("Original Title", "Author Danny", "ISBN123", "Fantasy Genre", 999.99, true);
  testShelf.addBook(testBook);

  LibraryMember member(123, "User Danny", "password123");
  member.borrowBook(&testShelf, "ISBN123");

  bool success = member.returnBook("ISBN123");

  EXPECT_TRUE(success);
  EXPECT_TRUE(testBook->getStatus());
}



TEST(LibraryMemberTests, returnBook_false_if_member_doesnt_have_book) {
  LibraryMember member(123, "User Danny", "password123");
  bool success = member.returnBook("NULL_ISBN");

  EXPECT_FALSE(success);
}
