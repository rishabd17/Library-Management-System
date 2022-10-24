#include <iostream>
using namespace std;

#include "patron.h"

/*
    Description:
        This is the cpp file of patron class. In this header file all the variables , their setter and getter functions are defined along with the constructors.
*/

/*
 * CSCE 1040 Homework 3
 * Section: 001
 *Name : Rieshab Kumar Dev
 *UNT email : rieshabdev@my.unt.edu
 *Date submitted : 04/25/2023
 */

// defining constructors
Patron::Patron()
{
    this->Fine_Balance = 0;
    this->Curr_Book_Num = 0;
}

Patron::Patron(string Name, int ID_Num, float Fine_Balance, int Curr_Book_Num)
{
    this->Name = Name;
    this->ID_Num = ID_Num;
    this->Fine_Balance = Fine_Balance;
    this->Curr_Book_Num = Curr_Book_Num;
}

// defining setter functions
void Patron ::setName(string Name)
{
    this->Name = Name;
}

void Patron ::setID(int ID_Num)
{
    this->ID_Num = ID_Num;
}

void Patron ::setCurrBookNum(int Curr_Book_Num)
{
    this->Curr_Book_Num = Curr_Book_Num;
}

void Patron:: setFineBalance(float Fine_Balance){
    this->Fine_Balance  = Fine_Balance;
}

//  defining getter functions
string Patron::getName()
{
    return Name;
}

int Patron::getID()
{
    return ID_Num;
}

float Patron::getFineBalance()
{
    return Fine_Balance;
}

int Patron::getCurrBookNum()
{
    return Curr_Book_Num;
}