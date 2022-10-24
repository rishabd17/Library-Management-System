#include <iostream>
using namespace std;

#include "loan.h"

/*
    Description:
        This is the header file of loan class. In this cpp file all the variables , their setter and getter functions are declared along with the constructors.
*/

/*
 * CSCE 1040 Homework 3
 * Section: 001
 *Name : Rieshab Kumar Dev
 *UNT email : rieshabdev@my.unt.edu
 *Date submitted : 04/25/2023
 */

//  defining constructors
Loan::Loan()
{
    this->Loan_ID = 0;
    this->Book_ID = 0;
    this->Patron_ID = 0;
    this->Curr_State = normal;
}

Loan::Loan(int Loan_ID, int Book_ID, int Patron_ID, CurrLoanStatus Curr_State)
{
    this->Loan_ID = Loan_ID;
    this->Book_ID = Book_ID;
    this->Patron_ID = Patron_ID;
    this->Curr_State = Curr_State;
}

// defining setters
void Loan::setLoanID(int Loan_ID)
{
    this->Loan_ID = Loan_ID;
}

void Loan::setBookID(int Book_ID)
{
    this->Book_ID = Book_ID;
}

void Loan::setPatronID(int Patron_ID)
{
    this->Patron_ID = Patron_ID;
}

void Loan::setCurrStatus(CurrLoanStatus Curr_State)
{
    this->Curr_State = Curr_State;
}

void Loan::setDateTime(string Date_Time)
{
    this->Date_Time = Date_Time;
}

// defining getters
int Loan::getLoanID()
{
    return Loan_ID;
}

int Loan::getBookID()
{
    return Book_ID;
}

int Loan ::getPatronID()
{
    return Patron_ID;
}

CurrLoanStatus Loan::getCurrStatus()
{
    return Curr_State;
}

string Loan::getDateTime()
{
    return Date_Time;
}