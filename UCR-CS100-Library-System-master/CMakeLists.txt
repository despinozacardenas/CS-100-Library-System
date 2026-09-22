CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(library_system
  src/main.cpp
  src/System.cpp
  src/Book.cpp
  src/BookEditor.cpp
  src/Bookshelf.cpp
  src/User.cpp
  src/LibraryMember.cpp
  src/Admin.cpp
)

ADD_EXECUTABLE(bookeditor_test
  test/BookEditor_test.cpp
  src/System.cpp
  src/Book.cpp
  src/BookEditor.cpp
  src/Bookshelf.cpp
  src/User.cpp
  src/LibraryMember.cpp
  src/Admin.cpp
)

ADD_EXECUTABLE(librarymember_test
  test/LibraryMember_test.cpp
  src/System.cpp
  src/Book.cpp
  src/BookEditor.cpp
  src/Bookshelf.cpp
  src/User.cpp
  src/LibraryMember.cpp
  src/Admin.cpp
)

ADD_EXECUTABLE(bookshelf_test
  test/Bookshelf_test.cpp
  src/Book.cpp
  src/Bookshelf.cpp
)

TARGET_LINK_LIBRARIES(bookeditor_test gtest)

TARGET_LINK_LIBRARIES(bookshelf_test gtest)

TARGET_LINK_LIBRARIES(librarymember_test gtest)

TARGET_COMPILE_DEFINITIONS(bookeditor_test PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(librarymember_test PRIVATE gtest_disable_pthreads=ON)