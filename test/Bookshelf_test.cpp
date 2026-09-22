#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "../header/Bookshelf.h"
#include "../header/Book.h"
#include "../header/IBookshelf.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(BookshelfTests,addBookcorrect){
    Bookshelf shelf;
    Book* testBook = new Book("Original Title", "Author Alan", "ISBN123", "Fantasy Genre", 999.99, true);

    shelf.addBook(testBook);
    ASSERT_EQ(shelf.getAllBooks().size(),1);
    EXPECT_EQ(shelf.getBookByISBN("ISBN123")->getTitle(),"Original Title");
}
TEST(BookshelfTests,addBookincorrect){
    Bookshelf shelf;
    Book* testBook = nullptr;
    shelf.addBook(testBook);
    EXPECT_EQ(shelf.getAllBooks().size(),0);
}
TEST(BookshelfTests,removeBookCorrect){
    Bookshelf shelf;
    Book* testBook = new Book("Original Title", "Author Alan", "ISBN123", "Fantasy Genre", 999.99, true);
    shelf.addBook(testBook);
    ASSERT_EQ(shelf.getAllBooks().size(),1);
    EXPECT_EQ(shelf.getBookByISBN("ISBN123")->getTitle(),"Original Title");
    shelf.removeBook("ISBN123");
    EXPECT_EQ(shelf.getAllBooks().size(),0);
}
TEST(BookshelfTests,removeBookIncorrect){
    Bookshelf shelf;
    shelf.removeBook("noISBN");
    EXPECT_EQ(shelf.getAllBooks().size(),0);
}
TEST(BookshelfTests,getBookByISBN_Found){
    Bookshelf shelf;
    Book* testBook = new Book("Original Title", "Author Alan", "ISBN123", "Fantasy Genre", 999.99, true);
    shelf.addBook(testBook);

    Book* found = shelf.getBookByISBN("ISBN123");
    EXPECT_EQ(found -> getISBN(),"ISBN123");
}
TEST(BookshelfTests,getBookByISBN_NotFound){
    Bookshelf shelf;
    EXPECT_EQ(shelf.getBookByISBN("noISBN"),nullptr);
}
TEST(BookshelfTests,getAllBookscorrect){
    Bookshelf shelf;
    Book* testBook = new Book("Original Title", "Author Alan", "ISBN123", "Fantasy Genre", 999.99, true);
    Book* testBook2 = new Book("Original Title 2", "Author Alan 2", "ISBN456", "Romance Genre", 999.99, true); 
    shelf.addBook(testBook);
    shelf.addBook(testBook2);
    EXPECT_EQ(shelf.getAllBooks().size(),2);
    EXPECT_EQ(shelf.getAllBooks()[0]->getISBN(),"ISBN123");
    EXPECT_EQ(shelf.getAllBooks()[1]->getISBN(),"ISBN456");
}
TEST(BookshelfTests,loadCSVCorrectly){
    Bookshelf shelf;
    EXPECT_TRUE(shelf.loadFromCsv("books.csv"));
    EXPECT_GT(shelf.getAllBooks().size(),0);
}

TEST(BookshelfTests,loadCSVIncorrectFile){
    Bookshelf shelf;
    EXPECT_FALSE(shelf.loadFromCsv("fake.csv"));
}