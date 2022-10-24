#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

/*
    Description:
        This is the header file of book class. In this header file all the variables , their setter and getter functions are declared along with the constructors.
*/

/*
 * CSCE 1040 Homework 3
 * Section: 001
 *Name : Rieshab Kumar Dev
 *UNT email : rieshabdev@my.unt.edu
 *Date submitted : 04/25/2023
 */

enum Curr_Status
{
    In,
    Out,
    Repair,
    Lost
};
class Book
{
private:
    string Author;
    string Title;
    string ISBN_Num;
    int Lib_ID;
    float Cost;
    Curr_Status Curr_State;

public:
    // declaring Constructors
    Book();
    Book(string Author, string Title, string ISBN_Num, int Lib_ID, float Cost);

    // declaring setter functions
    void setAuthor(string Author);
    void setTitle(string Title);
    void setISBN(string ISBN_Num);
    void setLibraryID(int Lib_ID);
    void setCost(float Cost);
    void setCurrStatus(Curr_Status Curr_State);

    // declaring getter functions
    string getAuthor();
    string getTitle();
    string getISBN();
    int getLibraryID();
    float getCost();
    Curr_Status getCurrStatus();
};
#endif