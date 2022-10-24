#include <iostream>
#include <vector>

using namespace std;

#include "patrons.h"
#include "patron.h"

/*
    Description:
        This cpp file of Patrons class consists the collection of patron objects in vector.
        This contains the functions related to Patron objects like adding a patron , editing a patron, printing patron details,
        changing the value of member variables of Patron object. Here the functions are implemented and wherever necessary proper user interface is required are also implemented in display interface
*/

/*
 * CSCE 1040 Homework 3
 * Section: 001
 *Name : Rieshab Kumar Dev
 *UNT email : rieshabdev@my.unt.edu
 *Date submitted : 04/25/2023
 */

// defining  functions for the Patron
//  this function adds a patron to the patronslist
void Patrons ::addPatron()
{
    string name;
    int id;
    Patron user; // creating a object user of class Patron
                 // constructor of patron class sets fine and current no of books to 0
    cout << "\t\tEnter the Name: ";
    getline(cin, name);
    cout << "\t\tEnter the id: ";
    cin >> id;

    cin.clear();
    cin.ignore(10000, '\n');

    user.setName(name);
    user.setID(id);
    PatronsList.push_back(user);
}

void Patrons::patronOperations()
{
    int id;
    cout << "\t\tEnter the id of a patron: ";
    cin >> id;

    cin.clear();
    cin.ignore(10000, '\n');

    for (int i = 0; i < PatronsList.size(); i++)
    {
        if (PatronsList[i].getID() == id)
        {
            cout << "\t\tPatron with given ID found" << endl;
        tag:
            displayOperations();
            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            cin.clear();
            cin.ignore(10000, '\n');

            this->x = i;

            switch (choice)
            {
            case 1:
            {
                editPatron();
                break;
            }
            case 2:
            {
                changeFineBalance();
                break;
            }
            case 3:
            {
                deletePatron();
                break;
            }
            case 4:
            {
                printPatronDetails();
                break;
            }
            case 5:
            {
                getNoOfBooks();
                break;
            }
            case 6:
            {
                checkFine();
                break;
            }
            case 7:
            {
                changeBooksBorrowedNum();
                break;
            }
            case 0:
            {
                return;
            }
            default:
            {
                cout << "Invalid choice!!!" << endl;
            }
            }
            goto tag;
        }
    }
    cout << "Patron with id " << id << " not found" << endl;
}

void Patrons::displayOperations()
{
    cout << endl;
    cout << "\t\t1. Edit Patron" << endl;
    cout << "\t\t2. Change Fine Balance" << endl;
    cout << "\t\t3. Delete Patron" << endl;
    cout << "\t\t4. Print Patron Detail" << endl;
    cout << "\t\t5. Get No. of Books Borrowed" << endl;
    cout << "\t\t6. Check Fine" << endl;
    cout << "\t\t7. Change No. of Books Borrowed" << endl;
    cout << "\t\t\tExit (0)" << endl;
    cout << endl;
}

void Patrons::editPatron()
{
    string name;
    cout << "\t\tEnter the Name to change: ";
    getline(cin, name);
    PatronsList[x].setName(name);
    cout << "\t\tName has been changed successfully" << endl;
}

void Patrons::changeFineBalance()
{
    int choice;
    float amount;
    float tempAmount;

    cout << "\t\t1. Add fine balance" << endl;
    cout << "\t\t2. Pay fine balance" << endl;
    cin >> choice;

    cout << "Enter Amount: ";
    cin >> amount;

    cin.clear();
    cin.ignore(10000, '\n');

    if (choice == 1)
        tempAmount = PatronsList[x].getFineBalance() + amount;
    else
        tempAmount = PatronsList[x].getFineBalance() - amount;

    PatronsList[x].setFineBalance(tempAmount);
    cout << "\t\tFine balance updated successfully" << endl;
    cout << "\t\tYour new fine Balance: " << PatronsList[x].getFineBalance() << endl;
}

void Patrons::deletePatron()
{
    PatronsList.erase(PatronsList.begin() + x);
    cout << "\t\tPatron deleted successfully" << endl;
}

void Patrons::printPatronDetails()
{
    cout << endl;
    cout << "\t\tName of Patron: " << PatronsList[x].getName() << endl;
    cout << "\t\tId of Patron: " << PatronsList[x].getID() << endl;
    cout << "\t\tTotal fine balance: " << PatronsList[x].getFineBalance() << endl;
    cout << "\t\tTotal no. of books borrowed: " << PatronsList[x].getCurrBookNum() << endl;
}

void Patrons::getNoOfBooks()
{
    cout << "\t\tNo. of Books borrowed: " << PatronsList[x].getCurrBookNum() << endl;
}

void Patrons ::checkFine()
{
    cout << "\t\tAmount of fine Balance: " << PatronsList[x].getFineBalance() << endl;
}

void Patrons ::changeBooksBorrowedNum()
{
    int noOfBooks;
    cout << "\t\tEnter the no. of Books borrowed: ";
    cin >> noOfBooks;

    cin.clear();
    cin.ignore(10000, '\n');

    PatronsList[x].setCurrBookNum(noOfBooks);
    cout << "\t\tNo. of Books borrowed set" << endl;
}

void Patrons::allPatronsDetails()
{
    cout << "\t\tPrinting all the Patrons details" << endl;
    cout << endl;
    for (auto i : PatronsList)
    {
        cout << "\t\tName of Patron: " << i.getName() << endl;
        cout << "\t\tId of Patron: " << i.getID() << endl;
        cout << "\t\tTotal fine balance: " << i.getFineBalance() << endl;
        cout << "\t\tTotal no. of books borrowed: " << i.getCurrBookNum() << endl;
        cout << endl;
        cout << endl;
    }
}
