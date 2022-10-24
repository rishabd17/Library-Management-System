#include <iostream>
using namespace std;

#include "book.h"

/*
    Description:
        This is the cpp file of book class. In this cpp file all the variables , their setter and getter functions are defined along with the constructors.
*/

/*
 * CSCE 1040 Homework 3
 * Section: 001
 *Name : Rieshab Kumar Dev
 *UNT email : rieshabdev@my.unt.edu
 *Date submitted : 04/25/2023
 */

// defining constructors
Book::Book()
{
    this->Curr_State = In;
}

Book::Book(string Author, string Title, string ISBN_Num, int Lib_ID, float Cost)
{
    this->Author = Author;
    this->Title = Title;
    this->ISBN_Num = ISBN_Num;
    this->Lib_ID = Lib_ID;
    this->Cost = Cost;
}

//  defining setters
void Book::setAuthor(string Author)
{
    this->Author = Author;
}

void Book::setTitle(string Title)
{
    this->Title = Title;
}

void Book::setISBN(string ISBN_Num)
{
    this->ISBN_Num = ISBN_Num;
}

void Book::setLibraryID(int Lib_ID)
{
    this->Lib_ID = Lib_ID;
}

void Book::setCost(float Cost)
{
    this->Cost = Cost;
}

void Book::setCurrStatus(Curr_Status Curr_State)
{
    this->Curr_State = Curr_State;
}

// defining getter functions
string Book::getAuthor()
{
    return Author;
}

string Book::getTitle()
{
    return Title;
}

string Book::getISBN()
{
    return ISBN_Num;
}

int Book::getLibraryID()
{
    return Lib_ID;
}

float Book::getCost()
{
    return Cost;
}

Curr_Status Book::getCurrStatus()
{
    return Curr_State;
}