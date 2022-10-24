#ifndef PATRON_H
#define PATRON_H

#include <iostream>
using namespace std;

/*
    Description:
        This is the header file of patron class. In this header file all the variables , their setter and getter functions are declared
*/

/*
 * CSCE 1040 Homework 3
 * Section: 001
 *Name : Rieshab Kumar Dev
 *UNT email : rieshabdev@my.unt.edu
 *Date submitted : 04/25/2023
 */


class Patron
{
private:
    string Name;
    int ID_Num;
    float Fine_Balance;
    int Curr_Book_Num;

public:
    //  declaring constructors
    Patron();
    Patron(string Name, int ID_Num,float Fine_Balance, int Curr_Book_Num);

    //  declaring setter functions
    void setName(string Name);
    void setID(int ID_Num);
    void setCurrBookNum(int Curr_Book_Num);
    void setFineBalance(float Fine_Balance);

    //  declaring getter functions
    string getName();
    int getID();
    float getFineBalance();
    int getCurrBookNum();
};
#endif