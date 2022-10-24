#include <iostream>
#include <vector>

using namespace std;

#include "books.h"
#include "book.h"

/*
    Description:
        This cpp file of Books class consists the collection of Book objects in vector.
        This contains the functions related to Book objects like adding a Book , editing a Book, printing Book details,
        changing the value of member variables of Book object. Here the functions are implemented and wherever necessary proper user interface is required are also implemented in display interface
*/

/*
 * CSCE 1040 Homework 3
 * Section: 001
 *Name : Rieshab Kumar Dev
 *UNT email : rieshabdev@my.unt.edu
 *Date submitted : 04/25/2023
 */

void Books::addBook()
{
    string Author, Title, ISBN_Num;
    int Lib_ID;

    float Cost;

    Book book1;

    cout << "\t\tEnter the name of Author: ";
    getline(cin, Author);
    cout << "\t\tEnter the title of Book: ";
    getline(cin, Title);
    cout << "\t\tEnter the ISBN number: ";
    cin >> ISBN_Num;
    cout << "\t\tEnter the Library ID: ";
    cin >> Lib_ID;
    cout << "\t\tEnter the cost of a book: ";
    cout << endl;
    cin >> Cost;

    cin.clear();
    cin.ignore(10000, '\n');

    book1.setAuthor(Author);
    book1.setTitle(Title);
    book1.setISBN(ISBN_Num);
    book1.setLibraryID(Lib_ID);
    book1.setCost(Cost);

    BooksList.push_back(book1);
}

void Books::editBook()
{
    int Lib_ID;
    cout << "\t\tEnter the Library ID of a book: ";
    cin >> Lib_ID;

    cin.clear();
    cin.ignore(10000, '\n');

    for (auto i : BooksList)
    {
        if (i.getLibraryID() == Lib_ID)\t\t
        {
        tag:
            cout << "\t\t1.Edit Author's Name" << endl;
            cout << "\t\t2.Edit Book's Name" << endl;
            cout << "\t\t3.Edit ISBN no." << endl;
            cout << "\t\t4.Edit Book's Cost" << endl;
            cout << "\t\t Exit (0)" << endl;
            cout << endl;

            int choice;
            cin >> choice;

            cin.clear();
            cin.ignore(10000, '\n');

            switch (choice)
            {
            case 1:
            {
                string Author;
                cout << "\t\tEnter the new Author's Name: ";
                getline(cin, Author);
                i.setAuthor(Author);
                break;
            }
            case 2:
            {
                string Title;
                cout << "\t\tEnter the new Book's Title: ";
                getline(cin, Title);
                i.setTitle(Title);
                break;
            }
            case 3:
            {
                string ISBN_Num;
                cout << "\t\tEnter the new ISBN no. ";
                cin >> ISBN_Num;

                cin.ignore();
                i.setISBN(ISBN_Num);
                break;
            }
            case 4:
            {
                float Cost;
                cout << "\t\tEnter the new cost of a book: ";
                cin >> Cost;
                cin.ignore();
                i.setCost(Cost);
                break;
            }
            case 0:
            {
                return;
            }
            default:
            {
                cout << "\t\tInvalid Choice!!! Exiting..." << endl;
                return;
            }
            }
            cout << "\t\tNew Data Updated Successfully" << endl;
            goto tag;
        }
    }
}

void Books::printBook(Book *i)
{
    cout << endl;
    cout << "\t\tLibrary ID: " << i->getLibraryID() << endl;
    cout << "\t\tAuthor Name: " << i->getAuthor() << endl;
    cout << "\t\tBook Name: " << i->getTitle() << endl;
    cout << "\t\tISBN no. " << i->getISBN() << endl;
    cout << "\t\tCost of Book: " << i->getCost() << endl;
    cout << "\t\tCurrent Status: " << i->getCurrStatus() << endl;
    cout << endl;
}

void Books::deleteBook()
{
    cout << "\t\tEnter the Library id: ";
    int Lib_ID;
    cin >> Lib_ID;

    cin.clear();
    cin.ignore(10000, '\n');

    for (int i = 0; i < BooksList.size(); i++)
    {
        if (BooksList[i].getLibraryID() == Lib_ID)
        {
            BooksList.erase(BooksList.begin() + i);
            return;
        }
    }
}

void Books::printBookDetail()
{
    cout << "\t\tPrint Book Details" << endl;
    cout << "\t\t\t1. Using Library id" << endl;
    cout << "\t\t\t2. Using ISBN no." << endl;
    cout << "\t\t\t3. Using Book's Title" << endl;
    cout << "\t\t\t4. Using Author's Name" << endl;

    int choice;
    cin >> choice;
    cin.clear();
    cin.ignore(10000, '\n');
    switch (choice)
    {
    case 1:
    {
        int Lib_ID;
        cout << "\t\tEnter the Library id: ";
        cin >> Lib_ID;
        cin.clear();
        cin.ignore(10000, '\n');
        for (auto i : BooksList)
            if (i.getLibraryID() == Lib_ID)
            {
                printBook(&i);
                return;
            }
        break;
    }
    case 2:
    {
        string ISBN_Num;
        cout << "\t\tEnter the ISBN no. ";
        cin >> ISBN_Num;

        cin.ignore();
        for (auto i : BooksList)
            if (i.getISBN() == ISBN_Num)
            {
                printBook(&i);
                return;
            }
        break;
    }
    case 3:
    {
        string Title;
        cout << "\t\tEnter the Book's Title: ";
        getline(cin, Title);
        for (auto i : BooksList)
            if (i.getTitle() == Title)
            {
                printBook(&i);
                return;
            }
        break;
    }
    case 4:
    {
        string Author;
        cout << "\t\tEnter the Author's name: ";
        getline(cin, Author);
        for (auto i : BooksList)
            if (i.getAuthor() == Author)
            {
                printBook(&i);
                return;
            }
        break;
    }
    default:
    {
        cout << "\t\tInvalid Choice!!! Exiting..." << endl;
        return;
    }
    }
    cout << "\t\tBook with given details is not found" << endl;
}

void Books::printAllBooksList()
{
    cout << "\t\t\tPrinting Details of all books" << endl;
    for (auto i : BooksList)
    {
        printBook(&i);
        cout << endl;
    }
}

void Books::checkBookStatusIn()
{
    int Lib_ID;
    cout << "\t\tEnter the library id: ";
    cin >> Lib_ID;

    cin.ignore();
    for (auto i : BooksList)
        if (i.getLibraryID() == Lib_ID)
            if (i.getCurrStatus() == In)
                cout << "\t\tBook is available in In state" << endl;
            else
                cout << "\t\tBook is not available in In state" << endl;
}
void Books::BookCost()
{
    int Lib_ID;
    cout << "\t\tEnter the library id of a book: ";
    cin >> Lib_ID;
    cin.ignore();
    for (auto i : BooksList)
        if (i.getLibraryID() == Lib_ID)
            cout << "\t\tCost of a book is: " << i.getCost() << endl;
}