#ifndef BOOKS_H
#define BOOKS_H

#include <iostream>
#include <vector>

using namespace std;

#include "book.h"

/*
    Description:
        This header file of Books class consists the collection of Book objects in vector.
        This contains the functions related to Book objects like adding a Book , editing a Book, printing Book details,
        changing the value of member variables of Book object. Here all the required functions in the code for library are declared.
*/

/*
 * CSCE 1040 Homework 3
 * Section: 001
 *Name : Rieshab Kumar Dev
 *UNT email : rieshabdev@my.unt.edu
 *Date submitted : 04/25/2023
 */

vector<Book> BooksList;

class Books
{
    int count;

public:
    void addBook();
    void editBook();
    void printBook(Book *i);
    void deleteBook();

    void printBookDetail();

    void printAllBooksList();
    void checkBookStatusIn();
    void BookCost();
};
#endif