#include "../header/Book.h"
#include "../header/BookEditor.h"

#include <gtest/gtest.h>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(BookTests, setTitle_returns_new_title) {
  Book testBook("Original Title", "Author Danny", "ISBN123", "Fantasy Genre", 999.99, true);
  testBook.setTitle("New Title");
  
  EXPECT_EQ(testBook.getTitle(), "New Title");
}

TEST(BookTests, setCost_throws_invalid_arguments_with_negative_input) {
  Book testBook("Original Title", "Author Danny", "ISBN123", "Fantasy Genre", 999.99, true);
  EXPECT_THROW(testBook.setCost(-9.99), std::invalid_argument);
}

TEST(BookTests, setCost_returns_new_cost) {
  Book testBook("Original Title", "Author Danny", "ISBN123", "Fantasy Genre", 999.99, true);
  testBook.setCost(1.23);
  EXPECT_DOUBLE_EQ(testBook.getCost(), 1.23);
}

TEST(BookEditorTests, editCost_throws_invalid_arguments_with_negative_input) {
  Book testBook("Original Title", "Author Danny", "ISBN123", "Fantasy Genre", 999.99, true);
  BookEditor editor;
  EXPECT_THROW(editor.editCost(&testBook, -20.00), std::invalid_argument);
}

TEST(BookEditorTests, editTitle_returns_edited_title) {
  Book testBook("Original Title", "Author Danny", "ISBN123", "Fantasy Genre", 999.99, true);
  BookEditor editor;
  editor.editTitle(&testBook, "Edited Title");

  EXPECT_EQ(testBook.getTitle(), "Edited Title");
}

TEST(BookEditorTests, editGenre_returns_edited_genre) {
  Book testBook("Original Title", "Author Danny", "ISBN123", "Fantasy Genre", 999.99, true);
  BookEditor editor;
  editor.editGenre(&testBook, "Edited Genre");

  EXPECT_EQ(testBook.getGenre(), "Edited Genre");
}

TEST(BookEditorTests, edit_nullptr_book_returns_false) {
  BookEditor editor;
  Book* nullBook = nullptr;

  EXPECT_FALSE(editor.editTitle(nullBook, "Book Not Exist"));
}

TEST(BookEditorTests, changeStatus_sets_to_unavailable) {
  Book testBook("Title", "Diego", "ISBN123", "Fantasy", 999.99, true);
  BookEditor editor; 
  EXPECT_TRUE(editor.changeStatus(&testBook, false));
  EXPECT_FALSE(testBook.getStatus());
}

TEST(BookEditorTests, changeStatus_sets_to_available) {
  Book testBook("Title", "Diego", "ISBN123", "Fantasy", 999.99, true);
  BookEditor editor; 
  EXPECT_TRUE(editor.changeStatus(&testBook, true));
  EXPECT_TRUE(testBook.getStatus());
}

TEST(BookEditorTests, changeStatus_nullptr_return_false) {
  BookEditor editor;
  EXPECT_FALSE(editor.changeStatus(nullptr, true));
}
