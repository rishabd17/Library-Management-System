#include <iostream>
using namespace std;

#include "books.h"
#include "loans.h"
#include "patrons.h"

/*
    This Assignment is submitted in collaboration with

    * Section: 001
    *Name : Rieshab Kumar Dev
    *UNT email : rieshabdev@my.unt.edu
    *Date submitted : 04/25/2023

    &

    * Section: 002
    *Name : Umanga Adhikari
    *UNT email : umangaadhikari@my.unt.edu
    *Date submitted : 04/25/2023


*/

/*
    Description:
        This is the main function of library management system. Here I have designed the class interface where user will be accessing
        his needs and to do tasks according to choices given...
        Like adding patron, book or account of loan
*/

/*
* CSCE 1040 Homework 3
* Section: 001
*Name : Rieshab Kumar Dev
*UNT email : rieshabdev@my.unt.edu
*Date submitted : 04/25/2023
*/

//  User Interface for interacting with the users
class Interface
{
public:
    void userInterface()
    {
        int x;
    tag:
        cout << "-----> What you are here for? <-----" << endl;
        cout << "\t\t1. Patron" << endl;
        cout << "\t\t2. Book" << endl;
        cout << "\t\t3. Loan" << endl;
        cout << "\t\tExit (0)" << endl;
        cout << endl;
        cin >> x;
    // to clear the error flag 
        cin.clear();
    // skips the first 10000 characters in buffer zone unless new line triggered
        cin.ignore(10000,'\n');

        switch (x)
        {
        case 1:
        {
            PatronInterface();
            break;
        }
        case 2:
        {
            BookInterface();
            break;
        }
        case 3:
        {
            LoanInterface();
            break;
        }
        case 0:
        {
            return;
        }
        default:
        {
            cout << "Invalid choice" << endl;
        }
        }
        goto tag;
    }

    void PatronInterface()
    {
    tag:
        cout << "\t\t\t 1. Add Patron" << endl;
        cout << "\t\t\t 2. Operations on Patron" << endl;
        cout << "\t\t\t 3. Print all Patrons Detail" << endl;
        cout << "\t\t Exit (0)" << endl;
        cout << endl;
        int choice;
        cin >> choice;

        cin.clear();
        cin.ignore(10000, '\n');

        Patrons user1;

        switch (choice)
        {
        case 1:
        {
            user1.addPatron();
            break;
        }
        case 2:
        {
            user1.patronOperations();
            break;
        }
        case 3:
        {
            user1.allPatronsDetails();
            break;
        }
        case 0:
        {
            return;
        }
        default:
        {
            cout << "\t\tInvalid choice" << endl;
        }
        }
        goto tag;
    }

    void BookInterface()
    {
    tag:
        cout << "\t\t1. Add Book" << endl;
        cout << "\t\t2. Edit Book" << endl;
        cout << "\t\t3. Delete Book" << endl;
        cout << "\t\t4. Print Book Detail" << endl;
        cout << "\t\t5. Print All Books Detail" << endl;
        cout << "\t\t6. Check Book Status In or Not" << endl;
        cout << "\t\t7. Cost of a Book" << endl;
        cout << "\t\t\tExit (0)" << endl;
        cout << endl;

        int choice;
        cin >> choice;

        cin.ignore();

        Books book2;

        switch (choice)
        {
        case 1:
        {
            book2.addBook();
            break;
        }
        case 2:
        {
            book2.editBook();
            break;
        }
        case 3:
        {
            book2.deleteBook();
            break;
        }
        case 4:
        {
            book2.printBookDetail();
            break;
        }
        case 5:
        {
            book2.printAllBooksList();
            break;
        }
        case 6:
        {
            book2.checkBookStatusIn();
            break;
        }
        case 7:
        {
            book2.BookCost();
            break;
        }
        case 0:
        {
            return;
        }
        default:
        {
            cout << "\t\tInvalid Choice!!!" << endl;
            break;
        }
        }
        goto tag;
    }

    void LoanInterface()
    {
    tag:
        cout << "\t\t1. Check Book Out" << endl;
        cout << "\t\t2. Check Book In" << endl;
        cout << "\t\t3. Report Book Lost" << endl;
        cout << "\t\t4. find Loan" << endl;
        cout << "\t\t5. Print Overdue Loans" << endl;
        cout << "\t\t\tExit (0)" << endl;
        cout << endl;

        int choice;
        cin >> choice;

        cin.clear();
        cin.ignore(10000,'\n');

        Loans person;

        switch (choice)
        {
        case 1:
        {
            person.checkBookOut();
            break;
        }
        case 2:
        {
            person.checkBookIn();
            break;
        }
        case 3:
        {
            person.reportLost();
            break;
        }
        case 4:
        {
            person.findLoan();
            break;
        }
        case 5:
        {
            person.printOverdueLoans();
            break;
        }
        case 0:
        {
            return;
        }
        default:
        {
            cout << "\t\tInvalid Choice!!!" << endl;
            break;
        }
        }
        goto tag;
    }
};

int main()
{
    Interface user;
    user.userInterface();
    return 0;
}