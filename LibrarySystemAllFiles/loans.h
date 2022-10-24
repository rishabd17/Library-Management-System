#ifndef LOANS_H
#define LOANS_H

#include <iostream>
#include <ctime>
#include <vector>
#include "loan.h"
#include "patrons.h"
#include "books.h"
using namespace std;

/*
    Description:
        This is the header file of Loans class. In this header file, i have declared the functions connecting the patrons and books
        that are being borrowed by the user and the loan associated with it.
        such as check a book if it goes out to a patron
        similary checks a book if it comes in to library from a patron
        Also find the loan of particular patron or a book issued along with the issue date
*/

/*
 * CSCE 1040 Homework 3
 * Section: 001
 *Name : Rieshab Kumar Dev
 *UNT email : rieshabdev@my.unt.edu
 *Date submitted : 04/25/2023
 */

vector<Loan> LoansList;

class Loans
{
private:
    int count;

public:
    void checkBookOut();
    void checkBookIn();
    void reportLost();
    void findLoan();
    void printOverdueLoans();
};
#endif