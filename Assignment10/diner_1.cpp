//
// diner_1.cpp
//
// Doga Ozkaracaabatlioglu
// 4/10/2018
// Assignment 10 - Program 1
// Creates MenuItem with user entry and prints it out.
//
#include <iostream>
#include <fstream>
using namespace std;

struct MenuItem
{
    char name[255];
    float price;
};
void ReadItem(MenuItem &menuItem, istream &is);
void PrintItem(MenuItem menuItem, ostream &os);

int main()
{
    MenuItem one;
    ReadItem(one,cin);
    PrintItem(one,cout);
    return 0;
}

void ReadItem(MenuItem &menuItem, istream &is)
{
    cout << "Enter product name:" << endl;
    is.getline(menuItem.name, 255, '\n' );
    cout << "Enter product price:" << endl;
    is >> menuItem.price;
}

void PrintItem(MenuItem menuItem, ostream &os)
{
    os << menuItem.name << " -- $" << menuItem.price << endl;
}
