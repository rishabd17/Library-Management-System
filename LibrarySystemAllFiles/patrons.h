#ifndef PATRONS_H
#define PATRONS_H

#include <iostream>
#include <vector>
using namespace std;

#include "patron.h"

/*
    Description:
        This header file of Patrons class consists the collection of patron objects in vector.
        This contains the functions related to Patron objects like adding a patron , editing a patron, printing patron details,
        changing the value of member variables of Patron object.
*/

/*
 * CSCE 1040 Homework 3
 * Section: 001
 *Name : Rieshab Kumar Dev
 *UNT email : rieshabdev@my.unt.edu
 *Date submitted : 04/25/2023
 */

vector<Patron> PatronsList;

class Patrons
{
private:
    int count = 0;
    int x = 0;
    // vector<Patron> PatronsList;

public:
    void addPatron();
    void patronOperations();
    void allPatronsDetails();

    void displayOperations();

    void editPatron();
    void changeFineBalance();
    void deletePatron();
    void printPatronDetails();
    void getNoOfBooks();
    void checkFine();
    void changeBooksBorrowedNum();
};
#endif