#include <iostream>
#include <ctime>
#include <vector>

#include "loans.h"
#include "loan.h"
#include "patrons.h"
#include "books.h"

using namespace std;

/*
    Description:
        This is the cpp file of the Loans class which is a vector list of loan class objects.
        In this file, all the functions that are mentioned in header file loans.h are implemented like
         checking a book going out, checking a book coming in, creating id for users taking book, changing status of the book, current number of
         patron objects and their details. Further more, it prints the details of the patron or book if their corresponding id is proviced
         including the name, id , book , id , book name, book status, book issued date and further more.
*/

/*
 * CSCE 1040 Homework 3
 * Section: 001
 *Name : Rieshab Kumar Dev
 *UNT email : rieshabdev@my.unt.edu
 *Date submitted : 04/25/2023
 */

void Loans::checkBookOut()
{
    int Patron_ID;
    cout << "Enter the Patron id: ";
    cin >> Patron_ID;
    for (auto i : PatronsList)
    {
        if (i.getID() == Patron_ID)
        {
            if (i.getCurrBookNum() <= 5)
            {
                Loan user2;
                int Book_ID;
                user2.setPatronID(Patron_ID);
                user2.setLoanID(Patron_ID + 1000);
                cout << "Enter the book id: ";
                cin >> Book_ID;
                cin.ignore();
                user2.setBookID(Book_ID);
                // current date/time based on current system
                time_t now = time(0);

                // convert now to string form
                char *dt = ctime(&now);

                user2.setDateTime(dt);
                user2.setCurrStatus(normal);

                LoansList.push_back(user2);

                for (auto j : BooksList)
                {
                    if (j.getLibraryID() == Book_ID)
                        j.setCurrStatus(Out);
                }
                cout << "Your unique Loan id is " << user2.getLoanID() << endl;
            }
            else
                cout << "User has already checked out maximum books" << endl;
            break;
        }
    }
}

void Loans::checkBookIn()
{
    int Loan_ID;
    cout << "Enter the Loan ID: ";
    cin >> Loan_ID;
    cin.ignore();

    for (int i = 0; i < LoansList.size(); i++)
    {
        if (LoansList[i].getLoanID() == Loan_ID)
        {
            if (LoansList[i].getCurrStatus() == normal)
            {
                for (auto j : PatronsList)
                    if (j.getID() == LoansList[i].getPatronID())
                        j.setCurrBookNum(j.getCurrBookNum() - 1);
                for (auto k : BooksList)
                    if (k.getLibraryID() == LoansList[i].getBookID())
                        k.setCurrStatus(In);
                LoansList.erase(LoansList.begin() + i);
            }
            else
            {
                for (auto j : PatronsList)
                    if (j.getID() == LoansList[i].getPatronID())
                    {
                        j.setFineBalance(j.getFineBalance() + 10);
                        j.setCurrBookNum(j.getCurrBookNum() - 1);
                    }
                for (auto k : BooksList)
                    if (k.getLibraryID() == LoansList[i].getBookID())
                        k.setCurrStatus(In);
                LoansList.erase(LoansList.begin() + i);
            }
            break;
        }
    }
}

void Loans::reportLost()
{
    int Loan_ID;
    cout << "Enter the Loan ID: ";
    cin >> Loan_ID;
    cin.ignore();

    for (auto i : LoansList)
    {
        if (i.getLoanID() == Loan_ID)
        {
            int cost;
            for (auto j : BooksList)
                if (j.getLibraryID() == i.getBookID())
                {
                    j.setCurrStatus(Out);
                    cost = j.getCost();
                }

            for (auto k : PatronsList)
                if (k.getID() == i.getPatronID())
                    k.setFineBalance(cost);
            break;
        }
    }
}

void Loans::findLoan()
{
    int Loan_ID;
    cout << "Enter the Loan ID: ";
    cin >> Loan_ID;
    cin.ignore();

    for (auto i : LoansList)
    {
        if (i.getLoanID() == Loan_ID)
        {
            for (auto k : PatronsList)
                if (i.getPatronID() == k.getID())
                {
                    cout << "Name: " << k.getName() << endl;
                    cout << "Patron ID: " << k.getID() << endl;
                    cout << "fine Balance: " << k.getFineBalance() << endl;
                    cout << "Books Borrowed: " << k.getCurrBookNum() << endl;
                }
            for (auto j : BooksList)
                if (i.getBookID() == j.getLibraryID())
                {
                    cout << "Book name: " << j.getTitle() << endl;
                    cout << "Author: " << j.getAuthor() << endl;
                    cout << "Library ID: " << j.getLibraryID() << endl;
                    cout << "Book Cost: " << j.getCost() << endl;
                    cout << "Book Status: " << j.getCurrStatus() << endl;
                }
            cout << "Loan due date is in next 10 days of given date: " << i.getDateTime() << endl;
            cout << "Loan Status: " << i.getCurrStatus() << endl;
        }
    }
}

void Loans::printOverdueLoans()
{
    for (auto i : LoansList)
        if (i.getCurrStatus() == overdue)
        {
            cout << endl;
            cout << "Loan ID: " << i.getLoanID() << endl;
            cout << "Patron ID: " << i.getPatronID() << endl;
            cout << "Book ID: " << i.getBookID() << endl;
            cout << "issued date: " << i.getDateTime() << endl;
        }
}