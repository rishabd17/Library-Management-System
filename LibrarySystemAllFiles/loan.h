#ifndef LOAN_H
#define LOAN_H

#include <iostream>
using namespace std;

/*
    Description:
        This is the header file of loan class. In this header file all the variables , their setter and getter functions are declared along with the constructors.
*/

/*
 * CSCE 1040 Homework 3
 * Section: 001
 *Name : Rieshab Kumar Dev
 *UNT email : rieshabdev@my.unt.edu
 *Date submitted : 04/25/2023
 */

enum CurrLoanStatus
{
    overdue,
    normal
};
class Loan
{
private:
    int Loan_ID;
    int Book_ID;
    int Patron_ID;
    string Date_Time;
    CurrLoanStatus Curr_State;

public:
    // constructors
    Loan();
    Loan(int Loan_ID, int Book_ID, int Patron_ID, CurrLoanStatus Curr_State);

    // setters
    void setLoanID(int Loan_ID);
    void setBookID(int Book_ID);
    void setPatronID(int Patron_ID);
    void setCurrStatus(CurrLoanStatus Curr_State);
    void setDateTime(string Date_Time);

    // getters
    int getLoanID();
    int getBookID();
    int getPatronID();
    CurrLoanStatus getCurrStatus();
    string getDateTime();
};
#endif